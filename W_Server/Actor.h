//#pragma once
//#include"SDL.h"
//#include<iostream>
//
//using namespace std;
//
//class Actor
//{
//public:
//	Actor();
//	Actor(int InX, int InY);
//	virtual ~Actor();
//
//	virtual void Tick();
//	virtual void Render();
//
//	virtual void EndPlay();
//	virtual void BeginPlay();
//
//	int X;
//	int Y;
//	char Shape;
//
//	int ZOrder;
//
//	bool operator<(Actor& RHS)
//	{
//		return (this->ZOrder) < (RHS.ZOrder);
//	}
//
//	static inline bool Compare(Actor* First, Actor* Second)
//	{
//		return (First->ZOrder) < (Second->ZOrder);
//	}
//
//	bool CheckHit(Actor* Other);
//
//
//	SDL_Color MyColor;
//
//	int TileSize = 60;
//	SDL_Surface* MySurface;
//	SDL_Texture* MyTexture;
//
//	void LoadBMP(std::string FileName);
//	SDL_Color MyColorKey;
//};
//
