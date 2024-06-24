#pragma once
#include <SFML/Graphics.hpp>
#include "invader.h"
#include <string.h>
using namespace std;
using namespace sf;

class Alpha : public Invader
{
public:
    Alpha()
    {
    }

    Alpha(std::string png_path)
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