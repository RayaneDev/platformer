#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

#include "Player.h"
#include "Platform.h"


class Game
{
    public:
        Game(std::string name, int width = 1000, int height = 500);
        virtual ~Game();

        // Fenêtre

        sf::RenderWindow* GetWindow();

        void init();
        void run();

        void addPlatform(Platform p);
        std::vector<Platform> getPlatforms();

    protected:

    private:
        std::vector<int> touches;
        Player joueur;
        std::string name;
        std::vector<Platform> platforms;
        std::vector<sf::RectangleShape> elements;
        sf::RenderWindow* m_window;
        sf::VideoMode m_videoMode;
        sf::Vector2i m_mouseWindowPosition;
        sf::Vector2i grid = sf::Vector2i(25, 25);
        int frameRateLimit = 60;
        int frame = 0;

        void updateMouse();
        void pollEvents();
        void update();
        void render();
};

#endif // GAME_H
