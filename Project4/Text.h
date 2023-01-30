#pragma once

#include<string>
#include "Actor.h"
#include"SDL_ttf.h"

using namespace std;

class AText :
    public AActor
{
public:
    AText();
    AText(int NewX, int NewY, string NewContent, int NewFontSize);
    ~AText();

    string Content;
    int FontSize;

    TTF_Font* Font;

    virtual void Render() override;
};

