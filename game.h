#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "player.h"
#include "enemy.h"
#include "addon.h"
#include "powerup.h"
#include "fire.h"
#include "lives.h"
#include "danger.h"
#include "bomb.h"
#include "alpha.h"
#include "beta.h"
#include "gamma.h"
#include "monster.h"
#include "dragon.h"
#include "menu.h"
#include <time.h>
#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;
const char title[] = "OOP-Project, Spring-2023";
using namespace sf;

class Game
{
public:
    string scores;
    Sprite background; // Game background sprite
    Sprite number1;
    Texture num1;
    Texture num2;
    Texture num3;
    Sprite number2;
    Sprite number3;
    Texture bg_texture;
    Text scoreText;
    Text highscoreTitleText;
    Font TextFont;
    Text livesText;
    Text gameOverText;
    bool menuscreen;
    bool gamescreen;
    bool instructionsscreen;
    bool highscorescreen;
    bool pausescreen;
    bool gameOver;
    int destCount;
    bool powerupActive;
    unsigned long long int powerupActiveCounter;
    bool fireActive;
    unsigned long long int fireActiveCounter;
    int score;
    int numBullet;
    Player ship; // player
    Bullet **bulletArray;
    bool invaderTime;
    bool monsterTime;
    bool dragonTime;
    Enemy *monster;
    Enemy *dragon;
    Enemy *gammawave[18];
    Bomb *bomb;
    unsigned long long int gammaBombCounter;
    unsigned long long int betaBombCounter;
    unsigned long long int alphaBombCounter;
    Addon *pwrup;
    unsigned long long int powerupCounter;
    Addon *fire;
    unsigned long long int fireCounter;
    Addon *life;
    unsigned long long int lifeCounter;
    Addon *danger;
    unsigned long long int dangerCounter;

    // filled rectangle + diamond + triangle
    float xPos[18] = {350, 150, 250, 350, 450, 550, 150, 250, 350, 450, 550, 50, 150, 250, 350, 450, 550, 650};
    float yPos[18] = {20, 100, 100, 100, 100, 100, 180, 180, 180, 180, 180, 260, 260, 260, 260, 260, 260, 260};

    Menu menu;

    bool isColliding(const Sprite &spriteA, const Sprite &spriteB)
    {
        FloatRect rectA = spriteA.getGlobalBounds();
        FloatRect rectB = spriteB.getGlobalBounds();
        float leftA = rectA.left;
        float leftB = rectB.left;
        float rightA = rectA.left + rectA.width;
        float rightB = rectB.left + rectB.width;
        float topA = rectA.top;
        float topB = rectB.top;
        float bottomA = rectA.top + rectA.height;
        float bottomB = rectB.top + rectB.height;
        return (leftA <= rightB && rightA >= leftB && topA <= bottomB && bottomA >= topB);
    }

    void writeToFile_score(string fileName)
    {
        ofstream out(fileName);
        out << score;
        out << endl;
    }

    void readFromFile_scores(string filename)
    {
        std::ifstream file;
        file.open("filename");
        file >> scores;
    }

    Game()
    {
        srand(time(0));
        score = 0;
        destCount = 0;
        numBullet = 0;

        TextFont.loadFromFile("img/BrunoAceSC-Regular.ttf");
        scoreText.setFont(TextFont);
        scoreText.setString("Score: " + to_string(score));
        scoreText.setPosition(450, 660);
        scoreText.setFillColor(Color::Green);
        scoreText.setCharacterSize(40);

        livesText.setFont(TextFont);
        livesText.setString("Lives: " + to_string(ship.numberOfLives));
        livesText.setPosition(10, 10);
        livesText.setFillColor(Color::Green);
        livesText.setCharacterSize(40);

        gameOverText.setFont(TextFont);
        gameOverText.setString("Game OVER");
        gameOverText.setPosition(220, 350);
        gameOverText.setFillColor(Color::White);
        gameOverText.setCharacterSize(50);

        highscoreTitleText.setFont(TextFont);
        highscoreTitleText.setString("High Scores");
        highscoreTitleText.setPosition(60, 80);
        highscoreTitleText.setFillColor(Color::Red);
        highscoreTitleText.setCharacterSize(60);

        menuscreen = 1;
        gamescreen = 0;
        instructionsscreen = 0;
        highscorescreen = 0;
        pausescreen = 0;
        gammaBombCounter = 0;
        betaBombCounter = 0;
        alphaBombCounter = 0;
        powerupCounter = 0;
        gameOver = 0;
        fireCounter = 0;
        lifeCounter = 0;
        dangerCounter = 0;
        powerupActive = 0;
        invaderTime = 1;
        monsterTime = 0;
        dragonTime = 0;
        powerupActiveCounter = 0;
        fireActive = 0;
        fireActiveCounter = 0;

        ship.set("img/player_ship.png");

        // filled rectangle + diamond + triangle
        gammawave[0] = new Gamma;
        gammawave[0]->set("img/enemy_3.png");
        gammawave[0]->sprite.setPosition(xPos[0], yPos[0]);

        gammawave[1] = new Gamma;
        gammawave[1]->set("img/enemy_3.png");
        gammawave[1]->sprite.setPosition(xPos[1], yPos[1]);

        gammawave[2] = new Gamma;
        gammawave[2]->set("img/enemy_3.png");
        gammawave[2]->sprite.setPosition(xPos[2], yPos[2]);

        gammawave[3] = new Gamma;
        gammawave[3]->set("img/enemy_3.png");
        gammawave[3]->sprite.setPosition(xPos[3], yPos[3]);

        gammawave[4] = new Gamma;
        gammawave[4]->set("img/enemy_3.png");
        gammawave[4]->sprite.setPosition(xPos[4], yPos[4]);

        gammawave[5] = new Gamma;
        gammawave[5]->set("img/enemy_3.png");
        gammawave[5]->sprite.setPosition(xPos[5], yPos[5]);

        gammawave[6] = new Beta;
        gammawave[6]->set("img/enemy_2.png");
        gammawave[6]->sprite.setPosition(xPos[6], yPos[6]);

        gammawave[7] = new Beta;
        gammawave[7]->set("img/enemy_2.png");
        gammawave[7]->sprite.setPosition(xPos[7], yPos[7]);

        gammawave[8] = new Beta;
        gammawave[8]->set("img/enemy_2.png");
        gammawave[8]->sprite.setPosition(xPos[8], yPos[8]);

        gammawave[9] = new Beta;
        gammawave[9]->set("img/enemy_2.png");
        gammawave[9]->sprite.setPosition(xPos[9], yPos[9]);

        gammawave[10] = new Beta;
        gammawave[10]->set("img/enemy_2.png");
        gammawave[10]->sprite.setPosition(xPos[10], yPos[10]);

        gammawave[11] = new Alpha;
        gammawave[11]->set("img/enemy_1.png");
        gammawave[11]->sprite.setPosition(xPos[11], yPos[11]);

        gammawave[12] = new Alpha;
        gammawave[12]->set("img/enemy_1.png");
        gammawave[12]->sprite.setPosition(xPos[12], yPos[12]);

        gammawave[13] = new Alpha;
        gammawave[13]->set("img/enemy_1.png");
        gammawave[13]->sprite.setPosition(xPos[13], yPos[13]);

        gammawave[14] = new Alpha;
        gammawave[14]->set("img/enemy_1.png");
        gammawave[14]->sprite.setPosition(xPos[14], yPos[14]);

        gammawave[15] = new Alpha;
        gammawave[15]->set("img/enemy_1.png");
        gammawave[15]->sprite.setPosition(xPos[15], yPos[15]);

        gammawave[16] = new Alpha;
        gammawave[16]->set("img/enemy_1.png");
        gammawave[16]->sprite.setPosition(xPos[16], yPos[16]);

        gammawave[17] = new Alpha;
        gammawave[17]->set("img/enemy_1.png");
        gammawave[17]->sprite.setPosition(xPos[17], yPos[17]);

        monster = new Monster("img/monster.png", 300, 50);
        dragon = new Dragon("img/dragon1.png", 300, 50);

        bulletArray = new Bullet *[5];
        for (int i = 0; i < 5; i++)
        {
            bulletArray[i] = nullptr;
        }

        bomb = new Bomb("img/meteorBrown_big4.png", gammawave[0]->sprite.getPosition().x + 25, gammawave[0]->sprite.getPosition().y + 50);
        pwrup = new Powerup("img/powerupGreen_bolt.png", rand() % 770, 0);
        fire = new Fire("img/powerupRed_bolt.png", rand() % 770, 0);
        life = new Lives("img/life_heart.png", rand() % 770, 0);
        danger = new Danger("img/dangerSign.png", rand() % 770, 0);

        bg_texture.loadFromFile("img/background.jpg");
        background.setTexture(bg_texture);
        background.setScale(2, 1.5);

        num1.loadFromFile("img/numeral1.png");
        num2.loadFromFile("img/numeral2.png");
        num3.loadFromFile("img/numeral3.png");

        number1.setTexture(num1);
        number2.setTexture(num2);
        number3.setTexture(num3);

        number1.setScale(3, 3);
        number2.setScale(3, 3);
        number3.setScale(3, 3);

        number1.setPosition(100, 250);
        number2.setPosition(100, 450);
        number3.setPosition(100, 650);
    }

    void start_game()
    {
        srand(time(0));
        RenderWindow window(VideoMode(780, 780), title);

        Clock clock;
        float timer = 0;
        int count = 0;
        bool spacebarPressed = 0;

        while (window.isOpen())
        {
            gammaBombCounter++;
            betaBombCounter++;
            alphaBombCounter++;
            powerupCounter++;
            fireCounter++;
            if (fireActive)
            {
                fireActiveCounter++;
            }
            if (powerupActive)
            {
                powerupActiveCounter++;
            }
            lifeCounter++;
            dangerCounter++;
            float time = clock.getElapsedTime().asSeconds();
            clock.restart();
            timer += time;

            Event e;
            while (window.pollEvent(e))
            {
                if (e.type == Event::Closed) // If cross/close is clicked/pressed
                    window.close();          // close the game
                if (e.type == Event::KeyPressed)
                {
                    if (e.key.code == Keyboard::Escape)
                    {
                        if (menuscreen)
                        {
                            window.close();
                        }
                        else if (gamescreen)
                        {
                            gamescreen = 0;
                            menuscreen = 1;
                        }
                        else if (instructionsscreen)
                        {
                            instructionsscreen = 0;
                            menuscreen = 1;
                        }
                        else if (highscorescreen)
                        {
                            highscorescreen = 0;
                            menuscreen = 1;
                        }
                    }
                    if (e.key.code == Keyboard::G)
                    {
                        if (menuscreen)
                        {
                            menuscreen = 0;
                            gamescreen = 1;
                        }
                    }
                    if (e.key.code == Keyboard::H)
                    {
                        if (menuscreen)
                        {
                            menuscreen = 0;
                            highscorescreen = 1;
                        }
                    }
                    if (e.key.code == Keyboard::I)
                    {
                        if (menuscreen)
                        {
                            menuscreen = 0;
                            instructionsscreen = 1;
                        }
                    }
                    if (e.key.code == Keyboard::E)
                    {
                        if (menuscreen)
                        {
                            window.close();
                        }
                    }
                    if (e.key.code == Keyboard::P)
                    {
                        if (gamescreen)
                        {
                            gamescreen = 0;
                            pausescreen = 1;
                        }
                    }
                    if (e.key.code == Keyboard::U)
                    {
                        if (pausescreen)
                        {
                            pausescreen = 0;
                            gamescreen = 1;
                        }
                    }
                }
            }

            if (menuscreen)
            {
                window.clear(Color::Black);
                window.draw(menu.gametitle);
                window.draw(menu.startgame);
                window.draw(menu.instructions);
                window.draw(menu.highscores);
                window.draw(menu.exit);
            }

            if (instructionsscreen)
            {
                window.clear(Color::Black);
                window.draw(menu.instructiontitle);
                window.draw(menu.instructionline1);
                window.draw(menu.instructionline2);
                window.draw(menu.instructionline3);
                window.draw(menu.instructionline4);
                window.draw(menu.instructionline5);
                window.draw(menu.instructionline6);
                window.draw(menu.instructionline7);
                window.draw(menu.instructionline8);
            }

            if (highscorescreen)
            {
                window.clear(Color::Black);
                window.draw(highscoreTitleText);
                window.draw(number1);
                window.draw(number2);
                window.draw(number3);
            }

            if (pausescreen)
            {
                window.clear(Color::Black);
                window.draw(menu.pausetext);
            }

            if (gamescreen)
            {
                if (Keyboard::isKeyPressed(Keyboard::Up))
                {
                    if (Keyboard::isKeyPressed(Keyboard::Right))
                    {
                        ship.tex.loadFromFile("/home/murtaza/Documents/Spaceshooter/img/playership_rotatedright.png");
                        ship.sprite.setTexture(ship.tex);
                        ship.sprite.setScale(1, 1);
                        ship.speed = 1;
                    }
                }
                else
                {
                    ship.tex.loadFromFile("/home/murtaza/Documents/Spaceshooter/img/player_ship.png");
                    ship.sprite.setTexture(ship.tex);
                    ship.sprite.setScale(0.75, 0.75);
                    ship.speed = 0.5;
                }

                if (Keyboard::isKeyPressed(Keyboard::Up))
                {
                    if (Keyboard::isKeyPressed(Keyboard::Left))
                    {
                        ship.tex.loadFromFile("/home/murtaza/Documents/Spaceshooter/img/playership_rotatedleft.png");
                        ship.sprite.setTexture(ship.tex);
                        ship.sprite.setScale(1, 1);
                        ship.speed = 1;
                    }
                }
                else
                {
                    ship.tex.loadFromFile("/home/murtaza/Documents/Spaceshooter/img/player_ship.png");
                    ship.sprite.setTexture(ship.tex);
                    ship.sprite.setScale(.75, .75);
                    ship.speed = 0.5;
                }

                if (Keyboard::isKeyPressed(Keyboard::Left))
                { // If left key is pressed
                    ship.speed = 0.3;
                    ship.move("l"); // Player will move to left
                }
                if (Keyboard::isKeyPressed(Keyboard::Right))
                { // If right key is pressed
                    ship.speed = 0.3;
                    ship.move("r"); // player will move to right
                }
                if (Keyboard::isKeyPressed(Keyboard::Up))
                { // If up key is pressed
                    ship.speed = 0.3;
                    ship.move("u"); // player will move upwards
                }
                if (Keyboard::isKeyPressed(Keyboard::Down))
                { // If down key is pressed
                    ship.speed = 0.3;
                    ship.move("d"); // player will move downwards
                }
                if (Keyboard::isKeyPressed(Keyboard::Space))
                {
                    if (!spacebarPressed)
                    {

                        for (int i = 0; i < 5; i++)
                        {
                            if (bulletArray[i] == nullptr)
                            {
                                if (!fireActive)
                                {
                                    bulletArray[i] = new Bullet("/home/murtaza/Documents/Spaceshooter/img/laserBlue15.png", ship.sprite.getPosition().x + 34, ship.sprite.getPosition().y - 60);
                                    break;
                                }
                                if (fireActive)
                                {
                                    bulletArray[i] = new Bullet("/home/murtaza/Documents/Spaceshooter/img/fire.png", ship.sprite.getPosition().x + 25, ship.sprite.getPosition().y - 60);
                                    break;
                                }
                            }
                        }
                    }
                    spacebarPressed = 1;
                }
                else if (e.type == Event::KeyReleased && e.key.code == Keyboard::Space)
                {
                    spacebarPressed = 0;
                }

                ////////////////////////////////////////////////
                /////  Call your functions here            ////
                ship.wrapAround();

                //////////////////////////////////////////////

                window.clear(Color::Black); // clears the screen
                window.draw(background);    // setting background
                window.draw(ship.sprite);   // setting player on screen
                scoreText.setString("Score: " + to_string(score));
                livesText.setString("Lives: " + to_string(ship.numberOfLives));
                window.draw(scoreText);
                window.draw(livesText);

                if (powerupCounter > 15000)
                {
                    if (pwrup == nullptr)
                    {
                        pwrup = new Powerup("/home/murtaza/Documents/Spaceshooter/img/powerupGreen_bolt.png", rand() % 770, 0);
                    }
                    powerupCounter = 0;
                }
                if (pwrup != nullptr)
                {
                    window.draw(pwrup->addonsprite);
                    pwrup->updateAddon();

                    if (isColliding(ship.sprite, pwrup->addonsprite))
                    {
                        powerupActive = 1;
                        pwrup->addonsprite.setPosition(1000, 500);
                    }

                    if (powerupActiveCounter > 5000)
                    {
                        powerupActive = 0;
                        powerupActiveCounter = 0;
                    }

                    if (pwrup->addonsprite.getPosition().y > 780)
                    {
                        pwrup = nullptr;
                    }
                }

                if (gammaBombCounter > 2000)
                {
                    int enemyNumber = rand() % 6;
                    if (bomb == nullptr)
                    {
                        bomb = new Bomb("/home/murtaza/Documents/Spaceshooter/img/meteorBrown_big4.png", gammawave[enemyNumber]->sprite.getPosition().x + 25, gammawave[enemyNumber]->sprite.getPosition().y + 50);
                    }
                    gammaBombCounter = 0;
                }

                if (betaBombCounter > 2500)
                {
                    int enemyNumber = (10 - (rand() % 5));
                    if (bomb == nullptr)
                    {
                        bomb = new Bomb("/home/murtaza/Documents/Spaceshooter/img/meteorBrown_big4.png", gammawave[enemyNumber]->sprite.getPosition().x + 25, gammawave[enemyNumber]->sprite.getPosition().y + 50);
                    }
                    betaBombCounter = 0;
                }

                if (alphaBombCounter > 5000)
                {
                    int enemyNumber = (17 - (rand() % 7));
                    if (bomb == nullptr)
                    {
                        bomb = new Bomb("/home/murtaza/Documents/Spaceshooter/img/meteorBrown_big4.png", gammawave[enemyNumber]->sprite.getPosition().x + 25, gammawave[enemyNumber]->sprite.getPosition().y + 50);
                    }
                    alphaBombCounter = 0;
                }

                if (bomb != nullptr)
                {
                    window.draw(bomb->bombsprite);
                    bomb->updateBomb();

                    if (isColliding(bomb->bombsprite, ship.sprite))
                    {
                        if (!powerupActive)
                        {
                            ship.numberOfLives -= 1;
                            bomb->bombsprite.setPosition(1000, 500);
                        }
                    }

                    if (bomb->bombsprite.getPosition().y > 780)
                    {
                        bomb = nullptr;
                    }
                }

                if (fireCounter > 9000)
                {
                    if (fire == nullptr)
                    {
                        fire = new Fire("/home/murtaza/Documents/Spaceshooter/img/powerupRed_bolt.png", rand() % 770, 0);
                    }
                    fireCounter = 0;
                }
                if (fire != nullptr)
                {
                    window.draw(fire->addonsprite);
                    fire->updateAddon();

                    if (isColliding(ship.sprite, fire->addonsprite))
                    {
                        fireActive = 1;
                        fire->addonsprite.setPosition(1000, 500);
                    }

                    if (fireActiveCounter > 5000)
                    {
                        fireActive = 0;
                        fireActiveCounter = 0;
                    }

                    if (fire->addonsprite.getPosition().y > 780)
                    {
                        fire = nullptr;
                    }
                }

                if (lifeCounter > 10000)
                {
                    if (life == nullptr)
                    {
                        life = new Lives("/home/murtaza/Documents/Spaceshooter/img/life_heart.png", rand() % 770, 0);
                    }
                    lifeCounter = 0;
                }
                if (life != nullptr)
                {
                    window.draw(life->addonsprite);
                    life->updateAddon();

                    if (isColliding(ship.sprite, life->addonsprite))
                    {
                        ship.numberOfLives += 1;
                        life->addonsprite.setPosition(800, 200);
                    }

                    if (life->addonsprite.getPosition().y > 780)
                    {
                        life = nullptr;
                    }
                }

                if (dangerCounter > 6500)
                {
                    if (danger == nullptr)
                    {
                        danger = new Danger("/home/murtaza/Documents/Spaceshooter/img/dangerSign.png", rand() % 770, 0);
                    }
                    dangerCounter = 0;
                }
                if (danger != nullptr)
                {
                    window.draw(danger->addonsprite);
                    danger->updateAddon();

                    if (isColliding(ship.sprite, danger->addonsprite))
                    {
                        if (!powerupActive)
                        {
                            ship.numberOfLives -= 1;
                            danger->addonsprite.setPosition(800, 200);
                        }
                    }

                    if (danger->addonsprite.getPosition().y > 780)
                    {
                        if (!gameOver)
                        {
                            score += 5;
                        }
                        danger = nullptr;
                    }
                }

                if (invaderTime)
                {
                    for (int i = 0; i < 5; i++)
                    {
                        if (bulletArray[i] != nullptr)
                        {
                            window.draw(bulletArray[i]->bulletsprite);
                            bulletArray[i]->updateBullet();

                            for (int j = 0; j < 18; j++)
                            {
                                if (isColliding(bulletArray[i]->bulletsprite, gammawave[j]->sprite))
                                {
                                    destCount += 1;
                                    gammawave[j]->sprite.setPosition(1000, 700);
                                    if (!fireActive)
                                    {
                                        bulletArray[i]->bulletsprite.setPosition(1200, 400);
                                    }
                                    if (j >= 0 && j <= 5)
                                        score += 30;
                                    if (j >= 6 && j <= 10)
                                        score += 20;
                                    if (j >= 11 && j <= 17)
                                        score += 10;
                                }
                            }

                            if (bulletArray[i]->bulletsprite.getPosition().y < 0)
                            {
                                bulletArray[i] = nullptr;
                            }
                        }
                    }

                    for (int i = 0; i < 18; i++)
                    {
                        if (isColliding(ship.sprite, gammawave[i]->sprite))
                        {
                            if (!powerupActive)
                            {
                                ship.numberOfLives -= 1;
                                ship.sprite.setPosition(340, 700);
                            }
                        }
                    }
                }

                if (destCount == 18)
                {
                    invaderTime = 0;
                    monsterTime = 1;
                }

                if (monsterTime)
                {
                    window.draw(monster->sprite);
                    for (int i = 0; i < 5; i++)
                    {
                        if (bulletArray[i] != nullptr)
                        {
                            window.draw(bulletArray[i]->bulletsprite);
                            bulletArray[i]->updateBullet();

                            if (isColliding(bulletArray[i]->bulletsprite, monster->sprite))
                            {
                                numBullet++;
                                if (!fireActive)
                                {
                                    bulletArray[i]->bulletsprite.setPosition(1200, 400);
                                }
                                if (numBullet == 10)
                                {
                                    monster->sprite.setPosition(900, 300);
                                    score += 40;
                                    dragonTime = 1;
                                }
                            }

                            if (bulletArray[i]->bulletsprite.getPosition().y < 0)
                            {
                                bulletArray[i] = nullptr;
                            }
                        }
                    }

                    if (isColliding(ship.sprite, monster->sprite))
                    {
                        if (!powerupActive)
                        {
                            ship.numberOfLives -= 1;
                            ship.sprite.setPosition(340, 700);
                        }
                    }
                }

                if (dragonTime)
                {
                    window.draw(dragon->sprite);
                    for (int i = 0; i < 5; i++)
                    {
                        if (bulletArray[i] != nullptr)
                        {
                            window.draw(bulletArray[i]->bulletsprite);
                            bulletArray[i]->updateBullet();

                            if (isColliding(bulletArray[i]->bulletsprite, dragon->sprite))
                            {
                                numBullet++;
                                if (!fireActive)
                                {
                                    bulletArray[i]->bulletsprite.setPosition(1200, 400);
                                }
                                if (numBullet == 35)
                                {
                                    dragon->sprite.setPosition(900, 300);
                                    score += 50;
                                    gameOver = 1;
                                }
                            }

                            if (bulletArray[i]->bulletsprite.getPosition().y < 0)
                            {
                                bulletArray[i] = nullptr;
                            }
                        }
                    }

                    if (isColliding(ship.sprite, dragon->sprite))
                    {
                        if (!powerupActive)
                        {
                            ship.numberOfLives -= 1;
                            ship.sprite.setPosition(340, 700);
                        }
                    }
                }

                for (int i = 0; i < 18; i++)
                {
                    window.draw(gammawave[i]->sprite);
                }

                if (ship.numberOfLives == 0)
                {
                    gameOver = 1;
                }
            }

            if (gameOver)
            {
                window.clear(Color::Black);
                window.draw(gameOverText);
                window.draw(scoreText);
                writeToFile_score("highscores.txt");
                readFromFile_scores("highscores.txt");
            }

            window.display(); // Displying all the sprites
        }
    }
};