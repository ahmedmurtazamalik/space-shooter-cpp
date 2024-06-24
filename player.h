#pragma once
#include <SFML/Graphics.hpp>
#include <string.h>
#include "bullet.h"
using namespace std;
using namespace sf;
class Player
{
public:
	Texture tex;
	Sprite sprite;
	float speed = 0.3;
	int x, y;
	int numberOfLives;

	Player()
	{
	}

	Player(std::string png_path)
	{
		tex.loadFromFile(png_path);
		sprite.setTexture(tex);
		x = 340;
		y = 700;
		sprite.setPosition(x, y);
		sprite.setScale(0.75, 0.75);
		numberOfLives = 3;
	}

	void set(std::string png_path)
	{
		tex.loadFromFile(png_path);
		sprite.setTexture(tex);
		x = 340;
		y = 700;
		sprite.setPosition(x, y);
		sprite.setScale(0.75, 0.75);
		numberOfLives = 3;
	}

	void move(std::string s)
	{
		float delta_x = 0, delta_y = 0;
		if (s == "l")
			delta_x = -1;
		else if (s == "r")
			delta_x = 1;
		if (s == "u")
			delta_y = -1;
		else if (s == "d")
			delta_y = 1;

		delta_x *= speed;
		delta_y *= speed;

		sprite.move(delta_x, delta_y);
	}

	void wrapAround()
	{
		if (sprite.getPosition().x < -84)
		{
			sprite.setPosition(784, sprite.getPosition().y);
		}
		if (sprite.getPosition().y >= 700)
		{
			sprite.setPosition(sprite.getPosition().x, 700);
		}
		if (sprite.getPosition().x > 784)
		{
			sprite.setPosition(-84, sprite.getPosition().y);
		}
		if (sprite.getPosition().y <= 0)
		{
			sprite.setPosition(sprite.getPosition().x, 0);
		}
	}
};