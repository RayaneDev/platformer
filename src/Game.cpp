#include "../include/Game.h"
#include "../include/Player.h"
#include "../include/Platform.h"

#include <algorithm>


Game::Game(std::string name, int width, int height) : name(name)
{

    this->m_videoMode.height = height;
    this->m_videoMode.width = width;
    this->m_window = new sf::RenderWindow(this->m_videoMode, name);

    this->m_window->setFramerateLimit(frameRateLimit);
    this->joueur = Player();
}

Game::~Game()
{
    delete this->m_window;
}

void Game::updateMouse()
{
    this->m_mouseWindowPosition = sf::Mouse::getPosition(*this->m_window);
}

void Game::pollEvents()
{
    sf::Event event;
    while (m_window->pollEvent(event)) {
        switch (event.type) {
            case sf::Event::Closed:
                m_window->close();
                break;
            case sf::Event::KeyPressed:

                if (event.key.code == sf::Keyboard::Right && !std::count(touches.begin(), touches.end(), sf::Keyboard::Right)) {
                    this->touches.push_back(sf::Keyboard::Right);
                }

                if (event.key.code == sf::Keyboard::Left && !std::count(touches.begin(), touches.end(), sf::Keyboard::Left)) {
                    this->touches.push_back(sf::Keyboard::Left);
                }

                if (event.key.code == sf::Keyboard::Up && !std::count(touches.begin(), touches.end(), sf::Keyboard::Up)) {
                    this->touches.push_back(sf::Keyboard::Up);
                }

                if (event.key.code == sf::Keyboard::Down && !std::count(touches.begin(), touches.end(), sf::Keyboard::Down)) {
                    this->touches.push_back(sf::Keyboard::Down);
                }
                break;
            case sf::Event::KeyReleased:

                if (event.key.code == sf::Keyboard::Right) {
                    this->touches.erase(std::remove(touches.begin(), touches.end(), sf::Keyboard::Right), touches.end());
                }

                if (event.key.code == sf::Keyboard::Left) {
                    this->touches.erase(std::remove(touches.begin(), touches.end(), sf::Keyboard::Left), touches.end());
                }

                if (event.key.code == sf::Keyboard::Up) {
                    this->touches.erase(std::remove(touches.begin(), touches.end(), sf::Keyboard::Up), touches.end());
                }
        }

    }
}

void Game::update()
{
    this->pollEvents();

    this->updateMouse();

    this->joueur.update(this->touches, this->getPlatforms());

    for (auto &pf : platforms) {
        pf.update();
    }

    frame++;

    float div = (float) frame / (float) frameRateLimit;


}

void Game::render()
{
    m_window->clear();


    for (auto &i : elements) {
        m_window->draw(i);
    }

    for (auto &pf : platforms) {
        m_window->draw(pf.getBox());
    }

    m_window->draw(this->joueur.getBox());

    m_window->display();
}

void Game::run()
{


    while (m_window->isOpen())
    {
        this->update();

        this->render();

    }

}

sf::RenderWindow* Game::GetWindow()
{
    return m_window;
}

void Game::init()
{

    std::ifstream ifs ("map.txt", std::ifstream::in);

    char c = ifs.get();

    int row = 0;
    int column = 0;

    while (ifs.good()) {

        if (c == '\n') {
            row++;
            column = -1;
        } else if (c == '-') {

            this->addPlatform(Platform(grid.x * column, grid.y * row, grid.x, grid.y));
        }

        c = ifs.get();
        column++;
    }

    ifs.close();
}

void Game::addPlatform(Platform p)
{
    this->platforms.push_back(p);
}

std::vector<Platform> Game::getPlatforms()
{

    return this->platforms;
}

