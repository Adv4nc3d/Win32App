/**
*
* Win32 Application
* by Adv4nc3d
*
* Copyright 2021. All Rights Reserved.
*
* pch.h
*
*/


#ifndef PCH_H
#define PCH_H




// Modern Windows Common Controls
#pragma comment(linker,"\"/manifestdependency:type='win32' \
name='Microsoft.Windows.Common-Controls' version='6.0.0.0' \
processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")

// Hide CRT Secure Warnings
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif




/**
* 
* Windows SDK
* 
*/

// SDK version
#include <WinSDKVer.h>
#define _WIN32_WINNT 0x0A00
#include <SDKDDKVer.h>

// Windows SDK
#include <windows.h>
#include <string>
#include <strsafe.h>




/**
*
* Application
*
*/

// Resources
#include "../resource.h"

// Application
#include "application/application.h"




#endif