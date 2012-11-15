#include "main.h"

using namespace std;

sf::RenderWindow mWindow;
sf::Sprite bgSprite;
Player *mPlayer;
static TextureManager textureManager("data/imgList");
static World myWorld("data/world.map");
const float FPS = 120;
void init()
{
    bgSprite.setTexture(textureManager.GetTexture("background"));
    bgSprite.setScale((float)800 / textureManager.GetTexture("background").getSize().x,
                      (float)500 / textureManager.GetTexture("background").getSize().y);
    bgSprite.setPosition(0,0);
    mWindow.setMouseCursorVisible(false);
    mWindow.create(sf::VideoMode(800,500,32),"'Distopia'  -pre.alpha",!sf::Style::Resize | sf::Style::Close);
}
void drawUpdate()
{
    mWindow.clear(sf::Color(255,0,0));
    mWindow.draw(bgSprite);
    myWorld.draw(mWindow,textureManager);
    //mPlayer->draw();
    mWindow.display();
}
void update()
{
    //mPlayer->update();
}
int main()
{
    init();
    UpdateEvent uFrame;
    //mPlayer = new Player(textureManager,400,250);
    bool windowActive = true;
    uFrame.AddFunction(update);
    uFrame.AddFunction(drawUpdate);
    sf::Clock fpsClock;
    fpsClock.restart();
    while(mWindow.isOpen())
    {
        sf::Event ev;
        while(mWindow.pollEvent(ev))
        {
            switch(ev.type)
            {
            case sf::Event::Closed:
                mWindow.close();
                break;
            case sf::Event::LostFocus:
                windowActive = false;
                break;
            case sf::Event::GainedFocus:
                windowActive = true;
                break;
            case sf::Event::KeyPressed:
            case sf::Event::KeyReleased:
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) mWindow.close();
                //mPlayer->input();
                break;
            case sf::Event::MouseButtonPressed:
                GameObject::m_event(sf::Mouse::getPosition(mWindow));
                //mPlayer->mouseEvent(sf::Mouse::getPosition(mWindow));
                break;
            }
        }
        if(windowActive && fpsClock.getElapsedTime().asSeconds() > (1.f / 60))//120))
        {
            frameRate = fpsClock.getElapsedTime().asSeconds();
            uFrame.Update();
            fpsClock.restart();
        }
    }
    return 0;
}
