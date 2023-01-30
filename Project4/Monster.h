#pragma once
#include"Actor.h"
#include"MyEngine.h"

class AMonster : public AActor
{
public:
	AMonster();
	~AMonster();
	AMonster(int NewX, int NewY);

	virtual void Tick() override;
	bool PredictCanMove();

	Uint64 ElapsedTime = 0;
	Uint64 ExecuteTime = 0;
};

