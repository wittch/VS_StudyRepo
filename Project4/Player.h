#pragma once
#include "Actor.h"


class APlayer : public AActor
{
public:
	APlayer();
	APlayer(int NewX, int NewY);

	~APlayer();

	int PlayerDirection;
	int PlayerAnimation;

	virtual void Tick() override;
	bool PredictCanMove();
	virtual void Render()override;
};