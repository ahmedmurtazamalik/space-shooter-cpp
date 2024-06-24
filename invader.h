#pragma once
#include <SFML/Graphics.hpp>
#include "enemy.h"
#include <string.h>
using namespace std;
using namespace sf;

class Invader : public Enemy
{
public:
    Invader()
    {
    }

    Invader(std::string png_path)
    {
        tex.loadFromFile(png_path);
        sprite.setTexture(tex);
        sprite.setPosition(-100, -100);
        sprite.setScale(0.5, 0.5);
    }

    virtual void set(std::string png_path)
    {
        tex.loadFromFile(png_path);
        sprite.setTexture(tex);
        sprite.setPosition(-100, -100);
        sprite.setScale(0.5, 0.5);
    }
};