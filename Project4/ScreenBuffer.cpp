//#include "ScreenBuffer.h"
//
//ScreenBuffer::ScreenBuffer()
//{
//}
//
//ScreenBuffer::~ScreenBuffer()
//{
//}
//
//void ScreenBuffer::ScreenInit()
//{
//	CONSOLE_CURSOR_INFO cci;
//	g_hScreen[0] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
//	g_hScreen[1] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
//
//	cci.dwSize = 1;
//	cci.bVisible = FALSE;
//	SetConsoleCursorInfo(g_hScreen[0], &cci);
//	SetConsoleCursorInfo(g_hScreen[1], &cci);
//}
//
//void ScreenBuffer::ScreenFlipping()
//{
//	SetConsoleActiveScreenBuffer(g_hScreen[g_nScreenIndex]);
//	g_nScreenIndex = !g_nScreenIndex;
//}
//
//void ScreenBuffer::ScreenClear()
//{
//	COORD Coor = { 0,0 };
//	DWORD dw;
//	FillConsoleOutputCharacter(g_hScreen[g_nScreenIndex], ' ', 80 * 40, Coor, &dw);
//}
//
//void ScreenBuffer::ScreenPrint(int CursorX, int CursorY, char* string)
//{
//	DWORD dw;
//	COORD CursorPosition = { CursorX,CursorY };
//	SetConsoleCursorPosition(g_hScreen[g_nScreenIndex], CursorPosition);
//	//WriteFile(g_hScreen[g_nScreenIndex], string, strlen(string), &dw, NULL);
//}
//void ScreenBuffer::ScreenRelease()
//{
//	CloseHandle(g_hScreen[0]);
//	CloseHandle(g_hScreen[1]);
//}
//
//void ScreenBuffer::Release()
//{
//	delete[] FPSTextInfo;
//}
