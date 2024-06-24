#pragma once
#include <SFML/Graphics.hpp>
#include <string.h>
using namespace std;
using namespace sf;

class Enemy
{
public:
    Texture tex;
    Sprite sprite;
    int x, y;
    bool leftEndreached = 0;
    bool rightEndreached = 0;
    int speed = 0.3;

    Enemy()
    {
    }

    Enemy(std::string png_path)
    {
        tex.loadFromFile(png_path);
        sprite.setTexture(tex);
        sprite.setPosition(-100, -100);
        sprite.setScale(0.5, 0.5);
        rightEndreached = 0;
        leftEndreached = 0;
    }

    void setRectangularEnemies(Enemy *enemies, float *xPos, float *yPos1)
    {
        for (int i = 0; i < 16; i++)
        {
            enemies[i].sprite.setPosition(xPos[i], yPos1[i]);
        }
    }

    void setTriangularEnemies(Enemy *enemies, float *xPos, float *yPos)
    {
        for (int i = 0; i < 12; i++)
        {
            enemies[i].sprite.setPosition(xPos[i], yPos[i]);
        }
    }

    void setMixedEnemies(Enemy *enemies[18], float *xPos, float *yPos)
    {
        for (int i = 0; i < 18; i++)
        {
            enemies[i]->sprite.setPosition(xPos[i], yPos[i]);
        }
    }

    virtual void updateMonsterRight()
    {
    }

    virtual void updateMonsterLeft()
    {
    }

    virtual void set(std::string png_path) = 0;
};