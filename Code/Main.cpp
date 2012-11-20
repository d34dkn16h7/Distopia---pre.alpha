#include "main.h"
#include "debug.h"
using namespace std;
sf::RenderWindow mWindow;
sf::RenderWindow sWindow;
sf::Sprite bgSprite;
Player *mPlayer;
static TextureManager textureManager("data/imgList");
void init()
{
    Debug::Init("data/Delius-Regular.ttf",&sWindow,15,15);
    mPlayer = new Player(textureManager,400,250);
    Renderer::Setup(&mWindow,&textureManager);
    bgSprite.setTexture(textureManager.GetTexture("background"));
    bgSprite.setScale((float)800 / textureManager.GetTexture("background").getSize().x,
                      (float)500 / textureManager.GetTexture("background").getSize().y);
    bgSprite.setPosition(0,0);
    mWindow.setMouseCursorVisible(false);
    mWindow.create(sf::VideoMode(800,500,32),"'Distopia'  -pre.alpha",!sf::Style::Resize | sf::Style::Close);
    sWindow.create(sf::VideoMode(500,300,32),"'Distopia'  -pre.alpha 2!",sf::Style::Resize | sf::Style::Close);
    mWindow.setPosition(sf::Vector2i(100,250));
    sf::Vector2i startPos;
    sWindow.setPosition(sf::Vector2i(mWindow.getPosition().x + (mWindow.getSize().x + 10),mWindow.getPosition().y + (mWindow.getSize().y / 4)));
}
static World myWorld("data/Map/world.map");
void drawUpdate()
{
    mWindow.clear(sf::Color(255,0,0));
    mWindow.draw(bgSprite);
    Renderer::RenderDraw();
    //myWorld.draw(mWindow,textureManager);
    mWindow.display();
    sWindow.clear(sf::Color(0,0,0));
    Debug::Draw();
    sWindow.display();
}
void update()
{
    Renderer::RenderUpdate();
    mPlayer->update();
}
int main()
{
    init();
    UpdateEvent uFrame;
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
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {mWindow.close();}
                mPlayer->input();
                Debug::Event("Keyboard Pressed");
                //KeyboardEvent::Event("KeyPressed");
                break;
            case sf::Event::MouseButtonPressed:
                MouseEvent::Event(sf::Mouse::getPosition(mWindow));
                Debug::Event("Mouse Clicked");
                break;
            }
        }
        sf::Event ev2;
        while(sWindow.pollEvent(ev2))
        {
            switch(ev2.type)
            {
            case sf::Event::KeyPressed:
            case sf::Event::KeyReleased:
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {sWindow.close();}
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::P)) {Renderer::DebugRender();}
                break;
            }
        }
        if(fpsClock.getElapsedTime().asSeconds() > (1.f / 60))//120))
        {
            //if(windowActive)
                uFrame.Update();
            fpsClock.restart();
        }
    }
    return 0;
}
