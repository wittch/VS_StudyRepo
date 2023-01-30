#include "stdafx.h"
#include "D3D12Practice.h"

_Use_decl_annotations_
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, int nCmdShow)
{
	D3D12Practice practice(1280, 720, L"Hello World!");
	return Win32Application::Run(&practice, hInstance, nCmdShow);
}