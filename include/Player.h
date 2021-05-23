#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include <string>
#include "Platform.h"

class Player
{
    public:
        Player();
        virtual ~Player();

        sf::RectangleShape getBox();

        void moveTo(std::vector<int> touches, std::vector<Platform> platforms);
        void update(std::vector<int>touches, std::vector<Platform> platforms);
        bool isFree(char dir, std::vector<Platform> platforms);

    private:
        float speed = 5.f;
        float speedY = 0;
        float acceleration = 0.2f;
        float maxSpeed = 10.f;
        int posX = 120;
        int posY = 45;
        bool falling = true;
        sf::Vector2f area = sf::Vector2f(20.f, 20.f);
        sf::RectangleShape box;

};

#endif // PLAYER_H
