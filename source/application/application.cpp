/**
*
* Win32 Application
* by Adv4nc3d
*
* Copyright 2021. All Rights Reserved.
*
* application/application.cpp
*
*/


// Pre Header
#include "../pch.h"



/**
*
* bool
* theApp (class)
* Initialize
*
* HINSTANCE hAppInstance					# handle to the current instance of the application
*
*/

bool theApp::Initialize(HINSTANCE hAppInstance)
{
	// Check Instance
	if (hAppInstance == NULL)
	{
		//MessageBox(NULL, L"ERROR APP hInstance", L"ERROR", MB_OK);
		return false;
	}

	// Set Application Instance
	SetInstance(hAppInstance);

	return true;
}


/**
*
* void
* theApp (class)
* NotifyIcon
*
*/

void theApp::NotifyIcon()
{
	// Notify Icon Data
	nid.cbSize = sizeof(nid);
	nid.hWnd = hwnd;
	nid.uID = 1;
	nid.uFlags = NIF_ICON | NIF_TIP | NIF_MESSAGE;
	nid.uCallbackMessage = APPWM_ICONNOTIFY;
	nid.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON));

	// Icon Tooltip Text
	StringCchCopy(nid.szTip, ARRAYSIZE(nid.szTip), lpTitle);

	// Show Notify Icon
	Shell_NotifyIcon(NIM_ADD, &nid);
}


/**
*
* LRESULT (LONG_PTR)
* CALLBACK (__stdcall)
* WindowProc
*
* HWND hwnd									# handle to the application
* UINT uMsg									# application window messages
* WPARAM wParam								# additional message information
* LPARAM lParam								# additional message information
*
*/

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
		// WM DESTROY
		case WM_DESTROY:
		{
			// Shutdown Application
			if (Application)
				Application->Shutdown();

			return 0;
		} break;

		// WM PAINT
		case WM_PAINT:
		{
			PAINTSTRUCT ps;
			HDC hdc = BeginPaint(hwnd, &ps);

			FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW + 1));

			EndPaint(hwnd, &ps);
		} break;

		// WM COMMAND
		case WM_COMMAND:
		{
			// Handle Button Commands
			if (Application)
				HandleButtonCmd(hwnd, wParam, Application->GetInstance());

			DefWindowProc(hwnd, uMsg, wParam, lParam);
		} break;

		// APPWM ICONNOTIFY
		case APPWM_ICONNOTIFY:
		{
			// Handle Icon Notify
			HandleIconNotify(lParam, hwnd);
		} break;

		// DEFAULT
		default:
		{
			return DefWindowProc(hwnd, uMsg, wParam, lParam);
		}
	}

	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}


/**
*
* void
* theApp (class)
* NotifyIcon
*
*/

ATOM theApp::RegisterAppClass()
{
	// Window Class Information
	WNDCLASSEX wndClassEx = { 0 };

	wndClassEx.cbSize = sizeof(WNDCLASSEX);
	wndClassEx.cbClsExtra = 0;
	wndClassEx.cbWndExtra = 0;
	wndClassEx.hbrBackground = (HBRUSH)CreateSolidBrush(RGB(52, 55, 60));
	wndClassEx.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON));
	wndClassEx.hCursor = LoadCursor(hInstance, IDC_ARROW);
	wndClassEx.hIconSm = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON));
	wndClassEx.hInstance = hInstance;
	wndClassEx.lpfnWndProc = WindowProc;
	wndClassEx.lpszClassName = lpWindowClass;
	wndClassEx.lpszMenuName = MAKEINTRESOURCE(IDR_MENU);
	wndClassEx.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;

	// Register Window Class
	return RegisterClassEx(&wndClassEx);
}


/**
*
* bool
* theApp (class)
* CreateWnd
*
*/

bool theApp::CreateWnd(int width, int height)
{
	// Register Application Window Class
	if (!RegisterAppClass())
	{
		return false;
	}

	// Get Desktop Resolution
	RECT rc;
	GetWindowRect(GetDesktopWindow(), &rc);

	// Create Window
	hwnd = CreateWindowEx(
		0,
		lpWindowClass,
		lpTitle,
		WS_EX_OVERLAPPEDWINDOW | WS_SIZEBOX | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX | WS_MAXIMIZEBOX | WS_VISIBLE,
		(((rc.left + rc.right) / 2) - width / 2),
		(((rc.top + rc.bottom) / 2) - height / 2),
		width, height,
		NULL,
		hMenu,
		hInstance,
		NULL
	);

	if (!hwnd)
	{
		//MessageBox(NULL, L"ERROR CreateWindowEx", L"ERROR", MB_OK);
		return false;
	}

	return true;
}


/**
*
* void
* theApp (class)
* Run
*
*/

void theApp::Run()
{
	// Window Status
	ShowWindow(hwnd, SW_SHOW);

	// Update Window
	UpdateWindow(hwnd);

	// Create Taskbar Notify Icon
	NotifyIcon();

	// Clear Messages
	ZeroMemory(&msg, sizeof(msg));

	// Message Loop
	while (msg.message != WM_QUIT)
	{
		if (PeekMessage(&msg, hwnd, NULL, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}
}


/**
*
* void
* theApp (class)
* Shutdown
*
*/

void theApp::Shutdown()
{
	// Remove Tray Icon
	Shell_NotifyIcon(NIM_DELETE, &nid);
	nid = {};

	// Destroy Menu
	DestroyMenu(hMenu);

	// Destroy Application Window
	DestroyWindow(hwnd);

	// Reset Handle to Application Window
	hwnd = NULL;

	// Unregister class
	BOOL unRegisterWndClass = UnregisterClass(
		lpWindowClass,
		hInstance
	);

	if (!unRegisterWndClass)
	{
		int err_code = GetLastError();
		//MessageBox(NULL, to_string(err_code).c_str(), "ERROR", NULL);
	}

	// Reset Application Instance
	hInstance = NULL;

	// Post Quit Message
	PostQuitMessage(0);
}