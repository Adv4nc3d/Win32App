/**
*
* Win32 Application
* by Adv4nc3d
*
* Copyright 2021. All Rights Reserved.
*
* application/ui.h
*
*/


#ifndef UI_H
#define UI_H


// Context Menu
#define ID_CMENU_EXIT		200
#define ID_CMENU_APPNAME	201


/**
*
* extern
*
*/

void HandleButtonCmd(HWND hwnd, WPARAM wParam, HINSTANCE hInstance);
void HandleIconNotify(LPARAM lParam, HWND hwnd);


#endif