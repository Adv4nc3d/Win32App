/**
*
* Win32 Application
* by Adv4nc3d
*
* Copyright 2021. All Rights Reserved.
*
* application/application.h
*
*/


#ifndef APPLICATION_H
#define APPLICATION_H

#define APPWM_ICONNOTIFY (WM_APP + 1)


/**
* 
* class
* theApp
* 
*/

class theApp
{
public:
	// Constructor
	theApp()
	{
		lpWindowClass = L"APP_MAIN";
		lpTitle = L"Win32 Application";
		hInstance = NULL;
		hwnd = NULL;
	}

	// Destructor
	~theApp()
	{
		lpWindowClass = L"";
		lpTitle = L"";
		hInstance = NULL;
		hwnd = NULL;
	}

public:
	// Get Application Handle
	HWND GetWindowHandle()
	{
		return hwnd;
	}

	// Set Instance
	HINSTANCE SetInstance(HINSTANCE APP_INSTANCE)
	{
		return hInstance = APP_INSTANCE;
	}

	// Get Instance
	HINSTANCE GetInstance()
	{
		return hInstance;
	}

private:
	// Application Menu
	HMENU hMenu = NULL;

	// Handle to Application Window
	HWND hwnd = NULL;

	// Notify Icon Data
	NOTIFYICONDATA nid = {};

	// Application Instance Module
	HINSTANCE hInstance = NULL;

	// Window Class
	LPCWSTR lpWindowClass = L"";

	// Window Title
	LPCWSTR lpTitle = L"";

	// Window Message Loop
	MSG msg = {};

public:
	bool Initialize(HINSTANCE hAppInstance);
	void NotifyIcon();
	ATOM RegisterAppClass();
	bool CreateWnd(int width, int height);
	void Run();
	void Shutdown();
};

// Application Global Pointer
inline theApp* Application = nullptr;


/**
*
* extern
*
*/

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);


#endif