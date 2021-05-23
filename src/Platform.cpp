#include "Platform.h"

Platform::Platform(int posX, int posY, int width, int height)
{
    this->posX = posX;
    this->posY = posY;
    this->area = sf::Vector2f(width, height);

    this->update();
}

Platform::~Platform()
{
    //dtor
}

void Platform::update()
{
    sf::RectangleShape rect(this->area);
    rect.setPosition(this->posX, this->posY);
    rect.setFillColor(sf::Color(0, 255, 0, 255));
    this->box = rect;
}

sf::RectangleShape Platform::getBox()
{
    return this->box;
}

sf::Vector2f Platform::getArea()
{
    return this->area;
}

int Platform::getPosX()
{
    return this->posX;
}

int Platform::getPosY()
{
    return this->posY;
}
