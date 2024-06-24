#pragma once
#include <SFML/Graphics.hpp>
#include "enemy.h"
#include <string.h>
using namespace std;
using namespace sf;

class Dragon : public Enemy
{
public:
    Dragon()
    {
    }

    Dragon(std::string png_path)
    {
        tex.loadFromFile(png_path);
        sprite.setTexture(tex);
        sprite.setPosition(-100, -100);
        sprite.setScale(1, 1);
    }

    void set(std::string png_path)
    {
        tex.loadFromFile(png_path);
        sprite.setTexture(tex);
        sprite.setPosition(-100, -100);
        sprite.setScale(1, 1);
    }

    Dragon(std::string png_path, int x, int y)
    {
        this->x = x;
        this->y = y;
        tex.loadFromFile(png_path);
        sprite.setTexture(tex);
        sprite.setPosition(x, y);
        sprite.setScale(1, 1);
    }
};