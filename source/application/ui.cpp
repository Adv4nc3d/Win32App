/**
*
* Win32 Application
* by Adv4nc3d
*
* Copyright 2021. All Rights Reserved.
*
* application/ui.cpp
*
*/


// Pre Header
#include "../pch.h"


/**
*
* void
* HandleButtonCmd
*
* HWND hwnd									# handle to the application window
* WPARAM wParam								# window message information
* HINSTANCE hInstance						# application instance
*
*/

void HandleButtonCmd(HWND hwnd, WPARAM wParam, HINSTANCE hInstance)
{
	switch (wParam)
	{
		/*
			Menu Controls
		*/

		// File -> Exit
		case ID_FILE_EXIT:
		{
			PostMessage(hwnd, WM_CLOSE, 0, 0);
		} break;


		/*
			Button Controls
		*/

		

		/*
			Context Menu Controls
		*/

		// Application
		case ID_CMENU_APPNAME:
		{
			// Show Application Window
			ShowWindow(hwnd, SW_RESTORE);

			// Set Application Window on Foreground
			SetForegroundWindow(hwnd);
		} break;

		// Exit Application
		case ID_CMENU_EXIT:
		{
			PostMessage(hwnd, WM_CLOSE, 0, 0);
		} break;
	}
}


/**
*
* void
* ContextMenu
*
* HWND hwnd									# handle to the application window
*
*/

void ContextMenu(HWND hwnd)
{
	// Mouse Position
	POINT pt;
	GetCursorPos(&pt);

	// Create Context Menu
	HMENU hPopupMenu = CreatePopupMenu();

	// Append Items
	AppendMenu(hPopupMenu, MF_STRING, ID_CMENU_APPNAME, L"Application");
	AppendMenu(hPopupMenu, MF_SEPARATOR, 0, NULL);
	AppendMenu(hPopupMenu, MF_STRING, ID_CMENU_EXIT, L"Exit");

	// Set on Foreground
	SetForegroundWindow(hwnd);

	// Track Events
	TrackPopupMenu(
		hPopupMenu,
		TPM_LEFTALIGN | TPM_BOTTOMALIGN | TPM_VERNEGANIMATION,
		pt.x, pt.y, 0,
		hwnd,
		NULL
	);

	// Destroy Context Menu
	DestroyMenu(hPopupMenu);
}


/**
*
* void
* HandleIconNotify
*
* LPARAM lParam								# window message information
* HWND hwnd									# handle to the application window
*
*/

void HandleIconNotify(LPARAM lParam, HWND hwnd)
{
	switch (lParam)
	{
		// Mouse Left Double Click
		case WM_LBUTTONDBLCLK:
		{
			// Show Application Window
			ShowWindow(hwnd, SW_RESTORE);

			// Set Application Window on Foreground
			SetForegroundWindow(hwnd);
		} break;

		// Mouse Left Single Click
		case WM_LBUTTONUP:
		{

		} break;

		// Mouse Right Single Click
		case WM_RBUTTONUP:
		{
			// Context Menu
			ContextMenu(hwnd);

		} break;
	}
}