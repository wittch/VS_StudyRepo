#include "Actor.h"
#include<iostream>
AActor::AActor():X(1),Y(1),Shape(' '), CollisionType(ECollisionType::NoCollision),ZOrder(10),
MyColor(SDL_Color{255,255,255,0}),TileSize(60),MySurface(nullptr),MyTexture(nullptr)
{
}

AActor::AActor(int InX, int InY):AActor()
{
	X = InX; Y = InY;
}

AActor::~AActor()
{
	SDL_FreeSurface(MySurface);
	SDL_DestroyTexture(MyTexture);
}

void AActor::Render()
{
	HANDLE hConsole;
	CONSOLE_CURSOR_INFO ConsoleCursor;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	ConsoleCursor.bVisible = true;
	ConsoleCursor.dwSize = 1;
	SetConsoleCursorInfo(hConsole, &ConsoleCursor);
	std::cout << Shape;


	SDL_Rect MyRect = SDL_Rect({ X * TileSize, Y * TileSize, TileSize, TileSize });
	if (MyTexture == nullptr)
	{
		SDL_SetRenderDrawColor(GEngine->MyRenderer, MyColor.r, MyColor.g, MyColor.b, MyColor.a);
		SDL_RenderFillRect(GEngine->MyRenderer, &MyRect);
	}
	else
	{
		SDL_RenderCopy(GEngine->MyRenderer, MyTexture, nullptr, &MyRect);
	}

}

void AActor::EndPlay()
{
}

void AActor::BeginPlay()
{
}

void AActor::LoadBMP(std::string Filename)
{
	MySurface = SDL_LoadBMP(Filename.c_str());
	MyTexture = SDL_CreateTextureFromSurface(GEngine->MyRenderer, MySurface);
}

bool AActor::CheckHit(AActor* Other)
{
	if ((int)Other->CollisionType & (int)ECollisionType::PhysicsOnly)
	{
		if (Other->X == X && Other->Y == Y)
		{
			return true;
		}
	}
	return false;
}

void AActor::Tick()
{
}

