#include "define.h"

/*
LRESULT CALLBACK LLKeyboardProc(int nCode, WPARAM wParam, LPARAM lParam);

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	static HHOOK hook_keys;

	switch (uMsg)
	{
	case WM_CREATE:
		hook_keys = SetWindowsHookEx(WH_KEYBOARD_LL,
			LLKeyboardProc,
			((LPCREATESTRUCT)lParam)->hInstance,
			0);
		return 0;

	case WM_DESTROY:
		UnhookWindowsHookEx(hook_keys);
		PostQuitMessage(0); 
		return 0;

	default:
		return DefWindowProc(hwnd, uMsg, wParam, lParam);
	}
}

LRESULT CALLBACK LLKeyboardProc(int nCode, WPARAM wParam, LPARAM lParam)
{
	PKBDLLHOOKSTRUCT hookstruct;

	if (nCode == HC_ACTION)
	{
		switch (wParam)
		{
		case WM_KEYDOWN: case WM_SYSKEYDOWN:
		case WM_KEYUP: case WM_SYSKEYUP:

			hookstruct = (PKBDLLHOOKSTRUCT)lParam;

			if (hookstruct->vkCode == KEY_H) {
				printf("h pressszz");
				return 1;
			} else {
				return CallNextHookEx(NULL, nCode, wParam, lParam);
			}
		}
	}
	return CallNextHookEx(NULL, nCode, wParam, lParam);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevIns, LPSTR lpszArgument, int iShow)
{
	TCHAR szClassName[] = _T("Template");
	TCHAR szWindowName[] = _T("Template");
	WNDCLASSEX wc = { 0 };
	MSG messages;
	HWND hWnd;

	wc.lpszClassName = szClassName;
	wc.lpfnWndProc = WindowProc;
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.hbrBackground = (HBRUSH)COLOR_BTNSHADOW;
	wc.hInstance = hInstance;

	_ASSERTE(RegisterClassEx(&wc) != 0);

	hWnd = CreateWindowEx(0, szClassName, szWindowName, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
		HWND_DESKTOP, 0, hInstance, 0);

	_ASSERTE(::IsWindow(hWnd));

	ShowWindow(hWnd, SW_SHOWMAXIMIZED);
	while (GetMessage(&messages, NULL, 0, 0))
	{
		TranslateMessage(&messages);
		DispatchMessage(&messages);
	}

	return static_cast<int>(messages.wParam);
}
*/
