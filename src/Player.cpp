#include <iostream>
#include "../include/Player.h"

Player::Player()
{

}

Player::~Player()
{
    //dtor
}

sf::RectangleShape Player::getBox()
{
    return this->box;
}

void Player::moveTo(std::vector<int> touches, std::vector<Platform> platforms)
{

    if (std::count(touches.begin(), touches.end(), sf::Keyboard::Right)) {

        if (isFree('R', platforms)) {
            this->posX += speed;
        }
    }
    if (std::count(touches.begin(), touches.end(), sf::Keyboard::Left)) {
        if (isFree('L', platforms)) {
            this->posX -= speed;
        }
    }
    if (std::count(touches.begin(), touches.end(), sf::Keyboard::Up) && !falling) {
        this->posY -= 3.f;
        this->speedY -= this->acceleration * 30;
    }
}

void Player::update(std::vector<int> touches, std::vector<Platform> platforms)
{
    falling = true;

    for (auto &pf : platforms) {
        if (!(posX + area.x < pf.getPosX() + 1.f || posX > pf.getPosX() + pf.getArea().x)) {
            if (posY + area.y >= pf.getPosY() - 2.f && posY + area.y < pf.getPosY() + 10.f) {
                if (speedY > 0.f) {
                    falling = false;
                    posY = pf.getPosY() - area.y;
                    speedY = 0.f;
                }
            }

            if (posY <= pf.getPosY() + pf.getArea().y + 1.f && posY > pf.getPosY() + pf.getArea().y - 7.f) {
                if (speedY < 0.f) {
                    speedY = -speedY / 2;
                }
            }
        }
    }

    if (falling) {
        this->speedY += this->acceleration;
        this->posY += speedY;
    }

    this->moveTo(touches, platforms);


    sf::RectangleShape rect(area);
    rect.setPosition(this->posX, this->posY);
    rect.setFillColor(sf::Color(255, 0, 0, 255));
    this->box = rect;
}

bool Player::isFree(char dir, std::vector<Platform> platforms)
{

    bool freeR = true, freeL = true;

    for (auto &pf : platforms) {
        if (pf.getPosX() <= posX + area.x && posX <= pf.getPosX() + pf.getArea().x && ((pf.getPosY() + pf.getArea().y <= posY + area.y && pf.getPosY() + pf.getArea().y > posY) || (posY + area.y > pf.getPosY() && posY < pf.getPosY())  )) {
            freeR = false;
        }

        if (pf.getPosX() + pf.getArea().x > posX - speed && posX + area.x > pf.getPosX() && ((pf.getPosY() + pf.getArea().y <= posY + area.y && pf.getPosY() + pf.getArea().y > posY) || (posY + area.y > pf.getPosY() && posY < pf.getPosY()))) {
            freeL = false;
        }
    }

    return (dir == 'R') ? freeR : freeL;

}
