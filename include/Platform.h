#ifndef PLATFORM_H
#define PLATFORM_H

#include <SFML/Graphics.hpp>

class Platform
{
    public:
        Platform(int posX, int posY, int width, int height);
        virtual ~Platform();

        sf::RectangleShape getBox();

        void update();

        int getPosX();
        int getPosY();
        sf::Vector2f getArea();

    protected:

    private:
        int posX;
        int posY;
        sf::Vector2f area;
        sf::RectangleShape box;
};

#endif // PLATFORM_H
