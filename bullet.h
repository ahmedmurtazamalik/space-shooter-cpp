#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string.h>
using namespace std;
using namespace sf;

class Bullet
{
public:
    Texture bullettex;
    Sprite bulletsprite;
    float speed = 1;
    int x, y;

    Bullet()
    {
    }

    Bullet(std::string png_path)
    {
        bullettex.loadFromFile(png_path);
        bulletsprite.setTexture(bullettex);
        bulletsprite.setScale(0.5, 0.5);
    }

    Bullet(std::string png_path, int x, int y)
    {
        this->x = x;
        this->y = y;
        bullettex.loadFromFile(png_path);
        bulletsprite.setTexture(bullettex);
        bulletsprite.setPosition(x, y);
        bulletsprite.setScale(1, 1);
    }

    void set(std::string png_path)
    {
        bullettex.loadFromFile(png_path);
        bulletsprite.setTexture(bullettex);
        bulletsprite.setScale(0.5, 0.5);
    }

    void set(std::string png_path, int x, int y)
    {
        bullettex.loadFromFile(png_path);
        bulletsprite.setTexture(bullettex);
        bulletsprite.setScale(1, 1);
        bulletsprite.setPosition(x, y);
    }

    void updateBullet()
    {
        float delta_x = 0;
        float delta_y = -1;
        delta_x *= speed;
        delta_y *= speed;
        bulletsprite.move(delta_x, delta_y);
    }

    void move(std::string s, bool fire, int ex, int ey)
    {
        float delta_x = 0;
        float delta_y = -1;

        delta_x *= speed;
        delta_y *= speed;

        bulletsprite.move(delta_x, delta_y);
        if (bulletsprite.getPosition().y < 0 && fire == 1)
        {
            bulletsprite.setPosition(ex, ey);
        }
    }
};