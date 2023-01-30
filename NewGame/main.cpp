#include"SDL.h"
#include<iostream>

#pragma comment(lib, "SDL2main.lib")
#pragma comment(lib, "SDL2.lib")

using namespace std;

int SDL_main(int argc,char* argv[])
{
	SDL_Init(SDL_INIT_EVERYTHING);

	
	SDL_Window* MyWindow = SDL_CreateWindow("Game", 100,100, 800, 600, SDL_WINDOW_OPENGL);
	SDL_Renderer* MyRenderer = SDL_CreateRenderer(MyWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_TARGETTEXTURE);

	SDL_Surface* BackGroundSurface = SDL_LoadBMP("Data\\_Map.bmp");
	SDL_Texture* BackGroundTexture = SDL_CreateTextureFromSurface(MyRenderer,BackGroundSurface);

	SDL_Surface* PlayerSurface = SDL_LoadBMP("Data\\Stand_R_01.bmp");
	SDL_SetColorKey(PlayerSurface, SDL_TRUE, SDL_MapRGB(PlayerSurface->format, 0xff,0xff,0xff));
	SDL_Texture* PlayerTexture = SDL_CreateTextureFromSurface(MyRenderer, PlayerSurface);
	

	bool bRunning = true;
	int playerX = 0;
	int playerY = 0;
	while (bRunning)
	{
		


		SDL_Event MyEvent;
		SDL_PollEvent(&MyEvent);

		if (MyEvent.type == SDL_QUIT)
		{
			bRunning = false;
			
		}
		else if (MyEvent.type == SDL_KEYDOWN) {
			switch (MyEvent.key.keysym.sym)
			{
			case SDLK_ESCAPE:
				bRunning = false;
				break;
			case SDLK_w:
				playerY-=3;
				break;
			case SDLK_s:
				playerY+=3;
				break;
			case SDLK_a:
				playerX-=3;
				break;
			case SDLK_d:
				playerX+=3;
				break;

			}
		}
		
		SDL_SetRenderDrawColor(MyRenderer, 0xff, 0, 0, 0);
		SDL_RenderClear(MyRenderer);
		SDL_Rect BackGroundRect = SDL_Rect{ 0,0,800,600 };
		SDL_RenderCopy(MyRenderer, BackGroundTexture, nullptr, &BackGroundRect);

		SDL_Rect MyRect = SDL_Rect{ playerX, playerY, PlayerSurface->w, PlayerSurface->h};
		SDL_RenderCopy(MyRenderer, PlayerTexture, nullptr, &MyRect);
		
		SDL_RenderPresent(MyRenderer);


	}
	


	SDL_Quit();

	return 0;
}