#pragma once
#include "Engine.h"


class MyEngine : public Engine
{
private:
	MyEngine();
	
public:
	virtual ~MyEngine();
	virtual void Initialize() override;
	virtual void Terminalize() override;

	static inline MyEngine* GetEngine()
	{
		if (Instance == nullptr)
		{
			new MyEngine();
		}

		return Instance;
	}
	
	static MyEngine* Instance;
};

#define GEngine MyEngine::GetEngine()
