﻿// dllmain.cpp : 定义 DLL 应用程序的入口点。
#include<lbpch.h>
#include "framework.h"
#include<iostream>
#include<filesystem>
LBAPI string GetDataPath(const string& myname) {
	using namespace std::filesystem;
	create_directory("data");
	return "data/" + myname;
}
LBAPI void WaitForDebugger() {
	while (!IsDebuggerPresent())
		Sleep(200);
}

BOOL APIENTRY DllMain(HMODULE hModule,
	DWORD ul_reason_for_call,
	LPVOID lpReserved) { 
	switch (ul_reason_for_call) { 
	case DLL_PROCESS_ATTACH: 
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}
