#pragma once
#include<Windows.h>
#include<string>
#include"SDL.h"
#include"ScreenBuffer.h"
#include"MyEngine.h"



enum class ECollisionType
{
	NoCollision     = 0, // 0000 0000
	QueryOnly       = 1, // 0000 0001
	PhysicsOnly     = 2, // 0000 0010
	CollisionEnable = (QueryOnly | PhysicsOnly), // 0000 0011
	EnemyOnly       = 4,
};
class AActor
{
public:
	AActor();
	AActor(int InX, int InY);
	virtual ~AActor();
	
	virtual void Tick();
	virtual void Render();

	virtual void EndPlay();
	virtual void BeginPlay();

	int X;
	int Y;
	char Shape;

	int ZOrder;

	bool operator<(AActor& RHS)
	{
		return (this->ZOrder) < (RHS.ZOrder);
	}

	static inline bool Compare(AActor* First, AActor* Second)
	{
		return (First->ZOrder) < (Second->ZOrder);
	}

	bool CheckHit(AActor* Other);

	ECollisionType CollisionType = ECollisionType::NoCollision;

	SDL_Color MyColor;

	int TileSize = 60;
	SDL_Surface* MySurface;
	SDL_Texture* MyTexture;

	void LoadBMP(std::string FileName);
	SDL_Color MyColorKey;

};