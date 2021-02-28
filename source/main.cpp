/**
* 
* Win32 Application
* by Adv4nc3d
* 
* Copyright 2021. All Rights Reserved.
* 
* main.cpp
* 
*/


// Pre Header
#include "pch.h"




/**
* 
* int
* WINAPI (__stdcall)
* wWinMain
* 
* HINSTANCE hInstance						#
* HINSTANCE hPrevInstance					#
* PWSTR pCmdLine							#
* int nCmdShow								#
* 
*/

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
{
	// Un-reference params
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(pCmdLine);
	UNREFERENCED_PARAMETER(nCmdShow);

	// Copy Application Class into Memory
	try {
		Application = new theApp();
	}
	catch (...) {

	}

	// Create & Run Application
	if (Application != nullptr)
	{
		Application->Initialize(hInstance);
		Application->SetWindowSize(1024, 768);
		Application->CreateWnd();
		Application->Run();
		Application->Shutdown();

		Application = 0;
		delete Application;
	}

	return 0;
}