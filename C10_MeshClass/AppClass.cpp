#include "AppClass.h"
void Application::InitVariables(void)
{
	//Make MyMesh object
	m_pMesh = new MyMesh();
	m_pMesh->GenerateCube(2.0f, C_BROWN);

	//Make MyMesh object
	m_pMesh1 = new MyMesh();
	m_pMesh1->GenerateCube(1.0f, C_BLACK);
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

	static float value = 0.0f;

	//bottom teeth things
	m_pMesh1->Render(m_pCameraMngr->GetProjectionMatrix(), m_pCameraMngr->GetViewMatrix(), glm::translate(IDENTITY_M4,vector3(3.0f+value, 0.0f, 0.0f)));
	m_pMesh1->Render(m_pCameraMngr->GetProjectionMatrix(), m_pCameraMngr->GetViewMatrix(), glm::translate(IDENTITY_M4, vector3(4.0f + value, 0.0f, 0.0f)));
	m_pMesh1->Render(m_pCameraMngr->GetProjectionMatrix(), m_pCameraMngr->GetViewMatrix(), glm::translate(IDENTITY_M4, vector3(1.0f + value, 0.0f, 0.0f)));
	m_pMesh1->Render(m_pCameraMngr->GetProjectionMatrix(), m_pCameraMngr->GetViewMatrix(), glm::translate(IDENTITY_M4, vector3(0.0f + value, 0.0f, 0.0f)));
	//above teeth
	m_pMesh1->Render(m_pCameraMngr->GetProjectionMatrix(), m_pCameraMngr->GetViewMatrix(), glm::translate(IDENTITY_M4, vector3(-3.0f + value, 1.0f, 0.0f)));
	m_pMesh1->Render(m_pCameraMngr->GetProjectionMatrix(), m_pCameraMngr->GetViewMatrix(), glm::translate(IDENTITY_M4, vector3(-1.0f + value, 1.0f, 0.0f)));
	m_pMesh1->Render(m_pCameraMngr->GetProjectionMatrix(), m_pCameraMngr->GetViewMatrix(), glm::translate(IDENTITY_M4, vector3(7.0f + value, 1.0f, 0.0f)));
	m_pMesh1->Render(m_pCameraMngr->GetProjectionMatrix(), m_pCameraMngr->GetViewMatrix(), glm::translate(IDENTITY_M4, vector3(5.0f + value, 1.0f, 0.0f)));
	//mid-1
	m_pMesh1->Render(m_pCameraMngr->GetProjectionMatrix(), m_pCameraMngr->GetViewMatrix(), glm::translate(IDENTITY_M4, vector3(2.0f + value, 2.0f, 0.0f)));
	//mid-1 left
	m_pMesh1->Render(m_pCameraMngr->GetProjectionMatrix(), m_pCameraMngr->GetViewMatrix(), glm::translate(IDENTITY_M4, vector3(1.0f + value, 2.0f, 0.0f)));
	m_pMesh1->Render(m_pCameraMngr->GetProjectionMatrix(), m_pCameraMngr->GetViewMatrix(), glm::translate(IDENTITY_M4, vector3(0.0f + value, 2.0f, 0.0f)));
	m_pMesh1->Render(m_pCameraMngr->GetProjectionMatrix(), m_pCameraMngr->GetViewMatrix(), glm::translate(IDENTITY_M4, vector3(-1.0f + value, 2.0f, 0.0f)));
	m_pMesh1->Render(m_pCameraMngr->GetProjectionMatrix(), m_pCameraMngr->GetViewMatrix(), glm::translate(IDENTITY_M4, vector3(-3.0f + value, 2.0f, 0.0f)));
	//mid-1 right
	m_pMesh1->Render(m_pCameraMngr->GetProjectionMatrix(), m_pCameraMngr->GetViewMatrix(), glm::translate(IDENTITY_M4, vector3(3.0f + value, 2.0f, 0.0f)));
	m_pMesh1->Render(m_pCameraMngr->GetProjectionMatrix(), m_pCameraMngr->GetViewMatrix(), glm::translate(IDENTITY_M4, vector3(4.0f + value, 2.0f, 0.0f)));
	m_pMesh1->Render(m_pCameraMngr->GetProjectionMatrix(), m_pCameraMngr->GetViewMatrix(), glm::translate(IDENTITY_M4, vector3(5.0f + value, 2.0f, 0.0f)));
	m_pMesh1->Render(m_pCameraMngr->GetProjectionMatrix(), m_pCameraMngr->GetViewMatrix(), glm::translate(IDENTITY_M4, vector3(7.0f + value, 2.0f, 0.0f)));
	//mid mid
	m_pMesh1->Render(m_pCameraMngr->GetProjectionMatrix(), m_pCameraMngr->GetViewMatrix(), glm::translate(IDENTITY_M4, vector3(2.0f + value, 3.0f, 0.0f)));
	//mid left
	m_pMesh1->Render(m_pCameraMngr->GetProjectionMatrix(), m_pCameraMngr->GetViewMatrix(), glm::translate(IDENTITY_M4, vector3(1.0f + value, 3.0f, 0.0f)));
	m_pMesh1->Render(m_pCameraMngr->GetProjectionMatrix(), m_pCameraMngr->GetViewMatrix(), glm::translate(IDENTITY_M4, vector3(0.0f + value, 3.0f, 0.0f)));
	m_pMesh1->Render(m_pCameraMngr->GetProjectionMatrix(), m_pCameraMngr->GetViewMatrix(), glm::translate(IDENTITY_M4, vector3(-1.0f + value, 3.0f, 0.0f)));
	m_pMesh1->Render(m_pCameraMngr->GetProjectionMatrix(), m_pCameraMngr->GetViewMatrix(), glm::translate(IDENTITY_M4, vector3(-2.0f + value, 3.0f, 0.0f)));
	m_pMesh1->Render(m_pCameraMngr->GetProjectionMatrix(), m_pCameraMngr->GetViewMatrix(), glm::translate(IDENTITY_M4, vector3(-3.0f + value, 3.0f, 0.0f)));
	//mid right
	m_pMesh1->Render(m_pCameraMngr->GetProjectionMatrix(), m_pCameraMngr->GetViewMatrix(), glm::translate(IDENTITY_M4, vector3(3.0f + value, 3.0f, 0.0f)));
	m_pMesh1->Render(m_pCameraMngr->GetProjectionMatrix(), m_pCameraMngr->GetViewMatrix(), glm::translate(IDENTITY_M4, vector3(4.0f + value, 3.0f, 0.0f)));
	m_pMesh1->Render(m_pCameraMngr->GetProjectionMatrix(), m_pCameraMngr->GetViewMatrix(), glm::translate(IDENTITY_M4, vector3(5.0f + value, 3.0f, 0.0f)));
	m_pMesh1->Render(m_pCameraMngr->GetProjectionMatrix(), m_pCameraMngr->GetViewMatrix(), glm::translate(IDENTITY_M4, vector3(6.0f + value, 3.0f, 0.0f)));
	m_pMesh1->Render(m_pCameraMngr->GetProjectionMatrix(), m_pCameraMngr->GetViewMatrix(), glm::translate(IDENTITY_M4, vector3(7.0f + value, 3.0f, 0.0f)));
	//+1mid
	m_pMesh1->Render(m_pCameraMngr->GetProjectionMatrix(), m_pCameraMngr->GetViewMatrix(), glm::translate(IDENTITY_M4, vector3(2.0f + value, 4.0f, 0.0f)));
	//+1mid left
	m_pMesh1->Render(m_pCameraMngr->GetProjectionMatrix(), m_pCameraMngr->GetViewMatrix(), glm::translate(IDENTITY_M4, vector3(1.0f + value, 4.0f, 0.0f)));
	m_pMesh1->Render(m_pCameraMngr->GetProjectionMatrix(), m_pCameraMngr->GetViewMatrix(), glm::translate(IDENTITY_M4, vector3(-1.0f + value, 4.0f, 0.0f)));
	m_pMesh1->Render(m_pCameraMngr->GetProjectionMatrix(), m_pCameraMngr->GetViewMatrix(), glm::translate(IDENTITY_M4, vector3(-2.0f + value, 4.0f, 0.0f)));
	//+1mid right
	m_pMesh1->Render(m_pCameraMngr->GetProjectionMatrix(), m_pCameraMngr->GetViewMatrix(), glm::translate(IDENTITY_M4, vector3(3.0f + value, 4.0f, 0.0f)));
	m_pMesh1->Render(m_pCameraMngr->GetProjectionMatrix(), m_pCameraMngr->GetViewMatrix(), glm::translate(IDENTITY_M4, vector3(5.0f + value, 4.0f, 0.0f)));
	m_pMesh1->Render(m_pCameraMngr->GetProjectionMatrix(), m_pCameraMngr->GetViewMatrix(), glm::translate(IDENTITY_M4, vector3(6.0f + value, 4.0f, 0.0f)));
	//+2mid
	m_pMesh1->Render(m_pCameraMngr->GetProjectionMatrix(), m_pCameraMngr->GetViewMatrix(), glm::translate(IDENTITY_M4, vector3(2.0f + value, 5.0f, 0.0f)));
	//+2mid left
	m_pMesh1->Render(m_pCameraMngr->GetProjectionMatrix(), m_pCameraMngr->GetViewMatrix(), glm::translate(IDENTITY_M4, vector3(1.0f + value, 5.0f, 0.0f)));
	m_pMesh1->Render(m_pCameraMngr->GetProjectionMatrix(), m_pCameraMngr->GetViewMatrix(), glm::translate(IDENTITY_M4, vector3(0.0f + value, 5.0f, 0.0f)));
	m_pMesh1->Render(m_pCameraMngr->GetProjectionMatrix(), m_pCameraMngr->GetViewMatrix(), glm::translate(IDENTITY_M4, vector3(-1.0f + value, 5.0f, 0.0f)));
	//+2mid right
	m_pMesh1->Render(m_pCameraMngr->GetProjectionMatrix(), m_pCameraMngr->GetViewMatrix(), glm::translate(IDENTITY_M4, vector3(3.0f + value, 5.0f, 0.0f)));
	m_pMesh1->Render(m_pCameraMngr->GetProjectionMatrix(), m_pCameraMngr->GetViewMatrix(), glm::translate(IDENTITY_M4, vector3(4.0f + value, 5.0f, 0.0f)));
	m_pMesh1->Render(m_pCameraMngr->GetProjectionMatrix(), m_pCameraMngr->GetViewMatrix(), glm::translate(IDENTITY_M4, vector3(5.0f + value, 5.0f, 0.0f)));
	//ears
	m_pMesh1->Render(m_pCameraMngr->GetProjectionMatrix(), m_pCameraMngr->GetViewMatrix(), glm::translate(IDENTITY_M4, vector3(0.0f + value, 6.0f, 0.0f)));
	m_pMesh1->Render(m_pCameraMngr->GetProjectionMatrix(), m_pCameraMngr->GetViewMatrix(), glm::translate(IDENTITY_M4, vector3(-1.0f + value, 7.0f, 0.0f)));
	m_pMesh1->Render(m_pCameraMngr->GetProjectionMatrix(), m_pCameraMngr->GetViewMatrix(), glm::translate(IDENTITY_M4, vector3(4.0f + value, 6.0f, 0.0f)));
	m_pMesh1->Render(m_pCameraMngr->GetProjectionMatrix(), m_pCameraMngr->GetViewMatrix(), glm::translate(IDENTITY_M4, vector3(5.0f + value, 7.0f, 0.0f)));
	
	value += 0.01f;

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
}
void Application::Release(void)
{
	if (m_pMesh != nullptr)
	{
		delete m_pMesh;
		m_pMesh = nullptr;
	}
	SafeDelete(m_pMesh1);
	//release GUI
	ShutdownGUI();
}