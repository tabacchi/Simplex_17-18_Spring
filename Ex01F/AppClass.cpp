#include "AppClass.h"
using namespace Simplex;
void Application::Display(void)
{
#pragma region DOES NOT NEED CHANGES
	// Clear the screen
	ClearScreen();

	
#pragma endregion
	//Your code goes here ---------------------------------------------------------
	
	m_sProgrammer = "Alberto Bobadilla - labigm@rit.edu"; //Replace with your name and email

	static float fTimer = 0;	//store the new timer
	static uint uClock = m_pSystem->GenClock(); //generate a new clock for that timer
	fTimer += m_pSystem->GetDeltaTime(uClock); //get the delta time for that timer

	static int ticount = 2;

	//get the subtraction for the timer so that the lerp works
	static int ticount1 = 0;

	//calculate the current position
	vector3 v3CurrentPos;

	//get end position
	vector3 v3EndPos;

	//interp flaot num
	static float interp = 0.0f;

	//what number im on for start and end position
	static uint counter = 0;

	//your code goes here
	//sets up the start position
	v3CurrentPos = m_v3StopList[counter];
	//gives the value for where the char should be from 00-1
	interp = (fTimer - ticount1) / 2;
	//loops if at max number in the array
	if (counter == m_v3StopList.size()-1)
	{

		v3EndPos = m_v3StopList[0];
		if ((int)fTimer / ticount == 1)
		{
			counter = 0;
			ticount += 2;
			ticount1 += 2;

		}
	}
	//normal loop
	else
	{
		v3EndPos = m_v3StopList[counter + 1];
		if ((int)fTimer / ticount == 1)
		{

			counter += 1;
			ticount += 2;
			ticount1 += 2;
		}
	}


	matrix4 m4Model = glm::translate(glm::lerp(v3CurrentPos, v3EndPos, interp));
	
	
	//---------------------------------------------------------
#pragma region DOES NOT NEED CHANGES
	matrix4 m4View = m_pCameraMngr->GetViewMatrix(); //view Matrix
	matrix4 m4Projection = m_pCameraMngr->GetProjectionMatrix(); //Projection Matrix

	// render the object
	m_pMesh->Render(m4Projection, m4View, m4Model);

	// draw stops to know we are within stops
	for (uint i = 0; i < m_v3StopList.size(); ++i)
	{
		m_pMeshMngr->AddSphereToRenderList(glm::translate(m_v3StopList[i]) * glm::scale(vector3(0.10f)), C_RED);
	}
		
	// draw a skybox
	m_pMeshMngr->AddSkyboxToRenderList();

	//render list call
	m_uRenderCallCount = m_pMeshMngr->Render();

	//clear the render list
	m_pMeshMngr->ClearRenderList();

	//draw gui
	DrawGUI();

	//end the current frame (internally swaps the front and back buffers)
	m_pWindow->display();
#pragma endregion
}
#pragma region DOES NOT NEED CHANGES
void Application::InitVariables(void)
{
	//Set the position and target of the camera
	//(I'm at [0,0,10], looking at [0,0,0] and up is the positive Y axis)
	m_pCameraMngr->SetPositionTargetAndUp(AXIS_Z * 15.0f, ZERO_V3, AXIS_Y);

	//initializing the model
	m_pMesh = new Simplex::MyMesh();

	//Generate a primitive
	m_pMesh->GenerateCone(1.5f, 2.0f, 5, C_YELLOW);

	//Check if stops is empty if it is add some points to it
	if (m_v3StopList.size() == 0)
	{
		m_v3StopList.push_back(vector3());
		m_v3StopList.push_back(vector3(2.5f, 0.0f, 0.0f));
		m_v3StopList.push_back(vector3(-1.0f, 2.5f, 0.0f));
		m_v3StopList.push_back(vector3(-2.5f));
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
void Application::Release(void)
{
	//release model
	SafeDelete(m_pMesh);

	//release GUI
	ShutdownGUI();
}
#pragma endregion