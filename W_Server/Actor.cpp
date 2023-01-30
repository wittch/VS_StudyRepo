//#include "Actor.h"
//
//
//Actor::Actor():X(1), Y(1), Shape(' '), ZOrder(10),MyColor(SDL_Color{ 255,255,255,0 }), TileSize(60), MySurface(nullptr), MyTexture(nullptr)
//{
//}
//
//Actor::Actor(int InX, int InY)
//{
//	X = InX; Y = InY;
//}
//
//Actor::~Actor()
//{
//	SDL_FreeSurface(MySurface);
//	SDL_DestroyTexture(MyTexture);
//}
//void Actor::LoadBMP(std::string FileName)
//{
//	MySurface = SDL_LoadBMP(Filename.c_str());
//	MyTexture = SDL_CreateTextureFromSurface(GEngine->MyRenderer, MySurface);
//}
