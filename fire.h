#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string.h>
#include "addon.h"
using namespace std;
using namespace sf;

class Fire : public Addon
{
public:
    Fire()
    {
    }

    Fire(std::string png_path)
    {
        addontex.loadFromFile(png_path);
        addonsprite.setTexture(addontex);
        addonsprite.setScale(0.5, 0.5);
    }

    Fire(std::string png_path, int x, int y)
    {
        this->x = x;
        this->y = y;
        addontex.loadFromFile(png_path);
        addonsprite.setTexture(addontex);
        addonsprite.setPosition(x, y);
        addonsprite.setScale(1, 1);
    }

    virtual void set(std::string png_path, int x, int y)
    {
        addontex.loadFromFile(png_path);
        addonsprite.setTexture(addontex);
        addonsprite.setScale(1, 1);
        addonsprite.setPosition(x, y);
    }
};