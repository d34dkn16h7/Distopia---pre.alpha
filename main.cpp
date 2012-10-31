#include "main.h"
#include <iostream>
using namespace std;
sf::RenderWindow mWindow;
sf::Sprite bgSprite;
Player *mPlayer;
static TextureManager textureManager;
sf::Texture tImg;
const float FPS = 120;
void loadTextures()
{
    ifstream file("imgList");
    string fName,tag;
    int animCount;
    while(file >> fName >> tag >> animCount)
    {
        sf::Texture tempImg;
        tempImg.loadFromFile(fName);
        textureManager.AddTexture(tempImg,tag,animCount);
        cout << fName << " : has loaded with this tag : " << tag << endl;
    }
}
void init()
{
    loadTextures();
    bgSprite.setTexture(textureManager.GetTexture("background"));

    bgSprite.setScale(
                       (float)800 / textureManager.GetTexture("background").getSize().x,
                       (float)500 / textureManager.GetTexture("background").getSize().y);
    bgSprite.setPosition(0,0);
    //mWindow.setFramerateLimit(FPS);
    mWindow.setMouseCursorVisible(false);
    //mWindow.setVerticalSyncEnabled(true);
    mWindow.create(sf::VideoMode(800,//textureManager.GetTexture("background").getSize().x / 2,
                                 500//textureManager.GetTexture("background").getSize().y / 2
                                 ,32),
                   "'Distopia'  -pre.alpha",
                   !sf::Style::Resize | sf::Style::Close);
}
void drawUpdate()
{
    mWindow.clear(sf::Color(255,0,0));
    mWindow.draw(bgSprite);
    mPlayer->draw();
    mWindow.display();
}
void update()
{
    mPlayer->update();
}
int main()
{
    init();
    UpdateEvent uFrame;
    mPlayer = new Player(textureManager,400,0);
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
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                    mWindow.close();
                mPlayer->input();
                break;
            }
        }
        if(windowActive && fpsClock.getElapsedTime().asSeconds() > (1.f / 120))
        {
            cout << fpsClock.getElapsedTime().asSeconds() << endl;
            frameRate = fpsClock.getElapsedTime().asSeconds();
            uFrame.Update();
            fpsClock.restart();
        }
    }
    return 0;
}
