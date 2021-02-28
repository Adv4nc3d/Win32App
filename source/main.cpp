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
* HINSTANCE hInstance						# handle to the current instance of the application
* HINSTANCE hPrevInstance					# handle to the previous instance of the application
* PWSTR pCmdLine							# command line for the application, excluding the program name
* int nCmdShow								# application run window status (normal, minimized, maximized)
* 
* MSDN: https://docs.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-winmain
* 
*/

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
{
	// Un-reference params
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(pCmdLine);
	UNREFERENCED_PARAMETER(nCmdShow);

	try {
		// Copy Application Class into Memory
		Application = new theApp();
	}
	catch (...) {

	}

	if (Application != nullptr)
	{
		// Initialize Application
		Application->Initialize(hInstance);

		// Set Application Window Size
		Application->SetWindowSize(1024, 768);

		// Create Application Window
		Application->CreateWnd();

		// Run Application
		Application->Run();

		// Shutdown Application
		Application->Shutdown();

		// Reset & Delete Pointer to Application Class
		Application = 0;
		delete Application;
	}

	return 0;
}