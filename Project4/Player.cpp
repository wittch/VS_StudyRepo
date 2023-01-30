#include "Player.h"
#include <iostream>
#include "MyEngine.h"

using namespace std;

APlayer::APlayer()
{
	Shape = 'P';
	ZOrder = 40;
	CollisionType = ECollisionType::CollisionEnable;
	MyColor = { 0, 255, 0, 0 };

	LoadBMP("data/player.bmp");
}

APlayer::APlayer(int NewX, int NewY)
	: APlayer()
{
	X = NewX;
	Y = NewY;
}

APlayer::~APlayer()
{
}

void APlayer::Tick()
{
	if (GEngine->MyEvent.type != SDL_KEYDOWN)
	{
		return;
	}

	switch (GEngine->MyEvent.key.keysym.sym)
	{
	case SDLK_w:
		Y--;
		PlayerDirection = 3;
		if (PlayerAnimation == 4)
			PlayerAnimation = 1;
		else
			PlayerAnimation++;
		if (!PredictCanMove())
		{
			PlayerAnimation = 0;
			Y++;
		}
		break;

	case SDLK_a:
		X--;
		PlayerDirection = 0;
		if (PlayerAnimation == 4)
			PlayerAnimation = 1;
		else
			PlayerAnimation++;
		if (!PredictCanMove())
		{
			PlayerAnimation = 0;
			X++;
		}
		break;

	case SDLK_s:
		Y++;
		PlayerDirection = 2;
		if (PlayerAnimation == 4)
			PlayerAnimation = 1;
		else
			PlayerAnimation++;
		if (!PredictCanMove())
		{
			PlayerAnimation = 0;
			Y--;
		}
		break;

	case SDLK_d:
		X++;
		PlayerDirection = 1;
		if (PlayerAnimation == 4)
			PlayerAnimation = 1;
		else
			PlayerAnimation++;
		if (!PredictCanMove())
		{
			PlayerAnimation = 0;
			X--;
		}
		break;

	case SDLK_ESCAPE:
		GEngine->QuitGame();

		break;
	}
	
}

bool APlayer::PredictCanMove()
{
	for (AActor* Actor : GEngine->GetAllActors())
	{
		if (X == Actor->X && Y == Actor->Y &&
			dynamic_cast<APlayer*>(Actor) == nullptr)
		{
			if (CheckHit(Actor))
			{
				return false;
			}
		}
	}

	return true;
}

void APlayer::Render()
{
	SDL_Rect MyRect = SDL_Rect({ X * TileSize, Y * TileSize, TileSize, TileSize });
	if (MyTexture == nullptr)
	{
		SDL_SetRenderDrawColor(GEngine->MyRenderer, MyColor.r, MyColor.g, MyColor.b, MyColor.a);
		SDL_RenderFillRect(GEngine->MyRenderer, &MyRect);
	}
	else
	{
		SDL_Rect SourceRect = { PlayerDirection,PlayerAnimation, MySurface->w/5, MySurface->h/5 };
		SDL_RenderCopy(GEngine->MyRenderer, MyTexture, &SourceRect, &MyRect);
	}
	
}
