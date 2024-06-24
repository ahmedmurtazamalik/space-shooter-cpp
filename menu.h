#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class Menu
{
public:
    Font bruno;
    Text gametitle;
    Text startgame;
    Text highscores;
    Text instructions;
    Text exit;
    Text instructiontitle;
    Text instructionline1;
    Text instructionline2;
    Text instructionline3;
    Text instructionline4;
    Text instructionline5;
    Text instructionline6;
    Text instructionline7;
    Text instructionline8;
    Text pausetext;

    Menu()
    {
        bruno.loadFromFile("img/BrunoAceSC-Regular.ttf");

        gametitle.setFont(bruno);
        gametitle.setString("SPACE SHOOTER");
        gametitle.setPosition(60, 80);
        gametitle.setFillColor(Color::Red);
        gametitle.setCharacterSize(60);

        startgame.setFont(bruno);
        startgame.setString("Start Game");
        startgame.setPosition(215, 250);
        startgame.setFillColor(Color::Red);
        startgame.setCharacterSize(50);

        highscores.setFont(bruno);
        highscores.setString("Instructions");
        highscores.setPosition(215, 350);
        highscores.setFillColor(Color::Red);
        highscores.setCharacterSize(50);

        instructions.setFont(bruno);
        instructions.setString("High Scores");
        instructions.setPosition(215, 450);
        instructions.setFillColor(Color::Red);
        instructions.setCharacterSize(50);

        exit.setFont(bruno);
        exit.setString("Exit");
        exit.setPosition(215, 550);
        exit.setFillColor(Color::Red);
        exit.setCharacterSize(50);

        instructiontitle.setFont(bruno);
        instructiontitle.setString("INSTRUCTIONS");
        instructiontitle.setPosition(20, 10);
        instructiontitle.setFillColor(Color::White);
        instructiontitle.setCharacterSize(60);

        instructionline1.setFont(bruno);
        instructionline1.setString("The galaxy has been attacked by enemies.");
        instructionline1.setPosition(20, 100);
        instructionline1.setFillColor(Color::Green);
        instructionline1.setCharacterSize(25);

        instructionline2.setFont(bruno);
        instructionline2.setString("Dodge the enemies' attacks.");
        instructionline2.setPosition(20, 180);
        instructionline2.setFillColor(Color::Green);
        instructionline2.setCharacterSize(25);

        instructionline3.setFont(bruno);
        instructionline3.setString("Destroy them with your spaceship.");
        instructionline3.setPosition(20, 260);
        instructionline3.setFillColor(Color::Green);
        instructionline3.setCharacterSize(25);

        instructionline4.setFont(bruno);
        instructionline4.setString("Invaders/Monsters/Dragons will attack you.");
        instructionline4.setPosition(20, 340);
        instructionline4.setFillColor(Color::Green);
        instructionline4.setCharacterSize(25);

        instructionline5.setFont(bruno);
        instructionline5.setString("You only have three lives.");
        instructionline5.setPosition(20, 420);
        instructionline5.setFillColor(Color::Green);
        instructionline5.setCharacterSize(25);

        instructionline6.setFont(bruno);
        instructionline6.setString("Avail power-up and fire to upgrade spaceship.");
        instructionline6.setPosition(20, 500);
        instructionline6.setFillColor(Color::Green);
        instructionline6.setCharacterSize(25);

        instructionline7.setFont(bruno);
        instructionline7.setString("Avoid Danger Sign at all costs.");
        instructionline7.setPosition(20, 580);
        instructionline7.setFillColor(Color::Green);
        instructionline7.setCharacterSize(25);

        instructionline8.setFont(bruno);
        instructionline8.setString("Best of luck!!");
        instructionline8.setPosition(350, 680);
        instructionline8.setFillColor(Color::Red);
        instructionline8.setCharacterSize(35);

        pausetext.setFont(bruno);
        pausetext.setString("GAME PAUSED.\nPress U to Unpause.");
        pausetext.setPosition(100, 350);
        pausetext.setFillColor(Color::White);
        pausetext.setCharacterSize(50);
    }
};