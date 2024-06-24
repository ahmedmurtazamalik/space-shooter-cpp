#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string.h>
using namespace std;
using namespace sf;

class Bomb
{
public:
    Texture bombtex;
    Sprite bombsprite;
    float speed = 0.6;
    int x, y;

    Bomb()
    {
    }

    Bomb(std::string png_path)
    {
        bombtex.loadFromFile(png_path);
        bombsprite.setTexture(bombtex);
        //        bulletsprite.setPosition(x, y);
        bombsprite.setScale(0.5, 0.5);
    }

    Bomb(std::string png_path, int x, int y)
    {
        this->x = x;
        this->y = y;
        bombtex.loadFromFile(png_path);
        bombsprite.setTexture(bombtex);
        bombsprite.setPosition(x, y);
        bombsprite.setScale(0.35, 0.35);
    }

    void set(std::string png_path)
    {
        bombtex.loadFromFile(png_path);
        bombsprite.setTexture(bombtex);
        bombsprite.setScale(0.35, 0.35);
    }

    void set(std::string png_path, int x, int y)
    {
        bombtex.loadFromFile(png_path);
        bombsprite.setTexture(bombtex);
        bombsprite.setScale(0.35, 0.35);
        bombsprite.setPosition(x, y);
    }

    void updateBomb()
    {
        float delta_x = 0;
        float delta_y = 1;
        delta_x *= speed;
        delta_y *= speed;
        bombsprite.move(delta_x, delta_y);
    }

    void move(std::string s, bool fire, int ex, int ey)
    {
        float delta_x = 0;
        float delta_y = 1;

        delta_x *= speed;
        delta_y *= speed;

        bombsprite.move(delta_x, delta_y);
        if (bombsprite.getPosition().y > 780 && fire == 1)
        {
            bombsprite.setPosition(ex, ey);
        }
    }
};