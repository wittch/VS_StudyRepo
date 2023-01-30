#include "SDL.h"
#include <iostream>
#include<conio.h>
#pragma comment(lib, "SDL2.lib")
#pragma comment(lib, "SDL2main.lib")

#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80


int SDL_main(int argc, char* argv[])
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) // SDL �ʱ�ȭ. SDL_INITEVERYTHING: ������ �ʱ�ȭ �÷���
	{
		SDL_Log("SDL_Init_Error");
		exit(-1);
	}

	SDL_Window* MyWindow = SDL_CreateWindow("MyGame", 100, 100, 600, 600, SDL_WINDOW_VULKAN); // �Ķ����: ������ ȭ�� �̸�, ��ǥ ������ x,y , ������ �ʺ� ���� w,h, ������ ���� �÷���(SDL_WINDOW_VULKAN); ���ϰ�: ������ ������

	SDL_Renderer* MyRenderer = SDL_CreateRenderer(MyWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_TARGETTEXTURE); // Ÿ�� �����쿡 ����� x��° ������ �����Ͽ� ����, �Ӽ��÷��� ����(���� �ϵ���� ���� & Ÿ���ؽ���)

	// DrawCall

	int X = 0;
	int Y = 0;
	char c = '\0';

	SDL_Event MyEvent;
	SDL_PollEvent(&MyEvent);
	switch (MyEvent.key.keysym.sym)
	{
	case SDLK_w:
		Y--;
		break;

	case SDLK_a:
		X--;
		break;

	case SDLK_s:
		Y++;
		break;

	case SDLK_d:
		X++;
		break;

	case SDLK_ESCAPE:
		return 0;

		break;
	}
	

	while (1)
	{
		SDL_SetRenderDrawColor(MyRenderer, 0, 0, 0, 0); // ������ ���� ���� (Ÿ�귣����, r, g, b, a)
		SDL_RenderClear(MyRenderer); // �ش� ���������� ȭ�� ����� ��Ŵ




		// �簢�� �׸���
		if (X > 500)
		{
			X = 0;
		}
		if (Y > 500)
		{
			Y = 0;
		}

		SDL_SetRenderDrawColor(MyRenderer, 0xff, 0xff, 0xff, 0);
		SDL_Rect MyRect = { X,Y,10,10 };
		SDL_RenderDrawRect(MyRenderer, &MyRect);

		// ȭ�鿡 �׸���
		SDL_RenderPresent(MyRenderer);

		SDL_Event MyEvent; // �̺�Ʈ ����
		SDL_PollEvent(&MyEvent);
	}


	SDL_DestroyRenderer(MyRenderer); // ������ ����
	SDL_DestroyWindow(MyWindow); // ������ ����


	SDL_Quit(); // SDL Quit �Ͽ� �޸� ���� 

	return 0;
}