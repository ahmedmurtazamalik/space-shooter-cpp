#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string.h>
using namespace std;
using namespace sf;

class Addon
{
public:
    Texture addontex;
    Sprite addonsprite;
    float speed = 0.3;
    int x, y;

    Addon()
    {
    }

    Addon(std::string png_path)
    {
        addontex.loadFromFile(png_path);
        addonsprite.setTexture(addontex);
        addonsprite.setScale(0.5, 0.5);
    }

    Addon(std::string png_path, int x, int y)
    {
        cout << "ADDON CONST" << endl;
        this->x = x;
        this->y = y;
        addontex.loadFromFile(png_path);
        addonsprite.setTexture(addontex);
        addonsprite.setPosition(x, y);
        addonsprite.setScale(1, 1);
    }

    void set(std::string png_path)
    {
        addontex.loadFromFile(png_path);
        addonsprite.setTexture(addontex);
        addonsprite.setScale(0.5, 0.5);
    }

    virtual void set(std::string png_path, int x, int y) = 0;

    void updateAddon()
    {
        float delta_x = 0;
        float delta_y = 1;
        delta_x *= speed;
        delta_y *= speed;
        addonsprite.move(delta_x, delta_y);
    }

    void move(std::string s, bool fire, int ex, int ey)
    {
        float delta_x = 0;
        float delta_y = -1;

        delta_x *= speed;
        delta_y *= speed;

        addonsprite.move(delta_x, delta_y);
        if (addonsprite.getPosition().y < 0 && fire == 1)
        {
            addonsprite.setPosition(ex, ey);
        }
    }
};