#include "AppClass.h"
void Application::InitVariables(void)
{
	//Change this to your name and email
	m_sProgrammer = "Thomas Tabacchi twt6012@rit.edu";
	
	//Set the position and target of the camera
	//(I'm at [0,0,10], looking at [0,0,0] and up is the positive Y axis)
	m_pCameraMngr->SetPositionTargetAndUp(AXIS_Z * 20.0f, ZERO_V3, AXIS_Y);

	//if the light position is zero move it
	if (m_pLightMngr->GetPosition(1) == ZERO_V3)
		m_pLightMngr->SetPosition(vector3(0.0f, 0.0f, 3.0f));

	//if the background is cornflowerblue change it to black (its easier to see)
	if (vector3(m_v4ClearColor) == C_BLUE_CORNFLOWER)
	{
		m_v4ClearColor = vector4(ZERO_V3, 1.0f);
	}
	
	//if there are no segments create 7
	if(m_uOrbits < 1)
		m_uOrbits = 7;

	float fSize = 1.0f; //initial size of orbits

	//creating a color using the spectrum 
	uint uColor = 650; //650 is Red
	//prevent division by 0
	float decrements = 250.0f / (m_uOrbits > 1? static_cast<float>(m_uOrbits - 1) : 1.0f); //decrement until you get to 400 (which is violet)
	/*
		This part will create the orbits, it start at 3 because that is the minimum subdivisions a torus can have
	*/
	uint uSides = 3; //start with the minimal 3 sides
	for (uint i = uSides; i < m_uOrbits + uSides; i++)
	{
		vector3 v3Color = WaveLengthToRGB(uColor); //calculate color based on wavelength
		m_shapeList.push_back(m_pMeshMngr->GenerateTorus(fSize, fSize - 0.1f, 3, i, v3Color)); //generate a custom torus and add it to the meshmanager
		fSize += 0.5f; //increment the size for the next orbit
		uColor -= static_cast<uint>(decrements); //decrease the wavelength
	}
}
void Application::Update(void)
{
	//Update the system so it knows how much time has passed since the last call
	m_pSystem->Update();

	//Is the arcball active?
	ArcBall();

	//Is the first person camera active?
	CameraRotation();
}
void Application::Display(void)
{
	// Clear the screen
	ClearScreen();

	//Get a timer
	static float fTimer = 0;	//store the new timer
	static uint uClock = m_pSystem->GenClock(); //generate a new clock for that timer
	fTimer += m_pSystem->GetDeltaTime(uClock); //get the delta time for that timer


	matrix4 m4View = m_pCameraMngr->GetViewMatrix(); //view Matrix
	matrix4 m4Projection = m_pCameraMngr->GetProjectionMatrix(); //Projection Matrix
	matrix4 m4Offset = IDENTITY_M4; //offset of the orbits, starts as the global coordinate system
	/*
		The following offset will orient the orbits as in the demo, start without it to make your life easier.
	*/
	//m4Offset = glm::rotate(IDENTITY_M4, 90.0f, AXIS_Z);

	//get the divider for the lerp
	static int ticount = 2;

	//get the subtraction for the timer so that the lerp works
	static int ticount1 = 0;
	//get end position
	vector3 v3EndPos;

	//interp flaot num
	static float interp = 0.0f;

	//what number im on for start and end position
	static uint counter = 0;
	
	int modual=0;
	 float fSize = 1.0f-.05f; //initial size of orbits
	 //sides the tri has
	 uint uSides = 3;
	 //checks if it got all the veticies for orbitss
	 static bool go = true;
	
	 static int pos = 0;
	 //a vector of vectors of vec3s
	 static std::vector<std::vector<vector3>> positions;
	 //positions to add to the previous vector
	 static std::vector<vector3> positionsToAdd;
	
	// draw a shapes
	for (uint i = 0; i < m_uOrbits; ++i)
	{
		//gets the degrees for making orbits
		int degrees = 360 / uSides;
		m_pMeshMngr->AddMeshToRenderList(m_shapeList[i], glm::rotate(m4Offset, 90.0f, AXIS_X));
		pos = 0;
		double radions = (PI / 180)*pos;

		if (go == true)
		{
			//gets all the positions of the orbits once
			for (uint j = 0; j < uSides; j++)
			{
				positionsToAdd.push_back(vector3(vector3(cos(radions), sin(radions), 0) *fSize));
				pos += degrees;
				radions = (PI / 180)*pos;
				
			}
		positions.push_back(positionsToAdd);
		}
		positionsToAdd.clear();
		static matrix4 m4Model;
		//calculate the current position
		vector3 v3CurrentPos;

		// if it is the last vertex it will go back to the beggining
		if (counter == uSides-1||counter%uSides==uSides-1)
		{
			v3CurrentPos = positions[i][uSides - 1];
			v3EndPos = positions[i][0];
			//gets where in the line the sphere should be
			interp = (fTimer - ticount1) / 2;
			m4Model = glm::translate(glm::lerp(v3CurrentPos, v3EndPos, interp));
						
		}
		//for after the first loop
		else if (counter >= uSides)
		{
			//gets where the sphere index for what position it is at
			modual = counter%uSides;
			v3CurrentPos = positions[i][modual];
			v3EndPos = positions[i][modual+1];
			interp = (fTimer - ticount1) / 2;
		    m4Model = glm::translate(glm::lerp(v3CurrentPos, v3EndPos, interp));
		}
		//only works for first loop
		else
		{
			v3CurrentPos = positions[i][counter];
			v3EndPos = positions[i][counter + 1];
			interp = (fTimer - ticount1) / 2;
		    m4Model = glm::translate(glm::lerp(v3CurrentPos, v3EndPos, interp));
		}



		//increases size of orbit and amount of sides
		fSize += .5f;
		uSides += 1;

		//draw spheres
		m_pMeshMngr->AddSphereToRenderList(m4Model * glm::scale(vector3(0.1)), C_WHITE);

		
	}
	//increses variables after one vertex increase
	if ((int)fTimer / ticount == 1)
	{
		
		
		counter += 1;
		ticount += 2;
		ticount1 += 2;
	}

	go = false;

	positionsToAdd.clear();

	//render list call
	m_uRenderCallCount = m_pMeshMngr->Render();

	//clear the render list
	m_pMeshMngr->ClearRenderList();
	
	//draw gui
	DrawGUI();
	
	//end the current frame (internally swaps the front and back buffers)
	m_pWindow->display();
}
void Application::Release(void)
{
	//release GUI
	ShutdownGUI();
}