#pragma once
#include <SFML/Graphics.hpp>
#include "enemy.h"
#include <string.h>
using namespace std;
using namespace sf;

class Monster : public Enemy
{
public:
    int speed = 0.3;
    bool leftEndreached;
    bool rightEndreached;

    Monster()
    {
    }

    Monster(std::string png_path)
    {
        tex.loadFromFile(png_path);
        sprite.setTexture(tex);
        sprite.setPosition(-100, -100);
        sprite.setScale(0.5, 0.5);
        leftEndreached = 0;
        rightEndreached = 0;
    }

    Monster(std::string png_path, int x, int y)
    {
        this->x = x;
        this->y = y;
        tex.loadFromFile(png_path);
        sprite.setTexture(tex);
        sprite.setPosition(x, y);
        sprite.setScale(0.1, 0.1);
    }

    void set(std::string png_path)
    {
        tex.loadFromFile(png_path);
        sprite.setTexture(tex);
        sprite.setPosition(-100, -100);
        sprite.setScale(0.5, 0.5);
        leftEndreached = 0;
        rightEndreached = 0;
    }

    virtual void updateMonsterRight()
    {
        float delta_x = 1;
        float delta_y = 0;
        delta_x *= speed;
        delta_y *= speed;
        sprite.move(delta_x, delta_y);
    }

    virtual void updateMonsterLeft()
    {
        float delta_x = -1;
        float delta_y = 0;
        delta_x *= speed;
        delta_y *= speed;
        sprite.move(delta_x, delta_y);
    }
    // if (leftEndreached == 0 && rightEndreached == 0)
    // {
    //     float delta_x = 1;
    //     float delta_y = 0;
    //     delta_x *= speed;
    //     delta_y *= speed;
    //     while (sprite.getPosition().x > 0 && sprite.getPosition().x < 700)
    //     {
    //         sprite.move(delta_x, delta_y);
    //         if (sprite.getPosition().x >= 700)
    //         {
    //             rightEndreached = 1;
    //             leftEndreached = 0;
    //         }
    //     }
    // }
    // else if (leftEndreached == 0 && rightEndreached == 1)
    // {
    //     float delta_x = -1;
    //     float delta_y = 0;
    //     delta_x *= speed;
    //     delta_y *= speed;
    //     while (sprite.getPosition().x > 0 && sprite.getPosition().x < 700)
    //     {
    //         sprite.move(delta_x, delta_y);
    //         if (sprite.getPosition().x <= 0)
    //         {
    //             rightEndreached = 0;
    //             leftEndreached = 1;
    //         }
    //     }
    // }
};