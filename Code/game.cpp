#include "game.h"

Game::Game()
{
    textureManager = new TextureManager("data/imgList");
    world = new World("data/Map/world.map");
    Debug::Init("data/Delius-Regular.ttf",15,15);
    player = new Player(400,250);
    window = new RenderWindow(VideoMode(800,500,32),"Game -PRE.ALPHA",!sf::Style::Resize | sf::Style::Close);
    window->setPosition(sf::Vector2i(100,250));
    Renderer::Setup(window,textureManager);
    Run();
}
void Game::Update()
{
    Debug::Update();
    Renderer::RenderUpdate();
    //player->Update();
}
void Game::Draw()
{
    window->clear(sf::Color(150,150,150));
    Renderer::RenderDraw();
    window->display();
    Debug::Draw();
}
int Game::Run()
{
    bool windowActive = true;
    sf::Clock fpsClock;
    fpsClock.restart();
    while(window->isOpen())
    {
        sf::Event ev;
        while(window->pollEvent(ev))
        {
            switch(ev.type)
            {
            case sf::Event::Closed:
                window->close();
                break;/*
            case sf::Event::LostFocus:windowActive = false;break;
            case sf::Event::GainedFocus:windowActive = true;break;*/
            case sf::Event::KeyPressed:
            case sf::Event::KeyReleased:
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {window->close();}//player->input();
                break;
            case sf::Event::MouseButtonPressed:
                break;
            }
        }
        Debug::Update();
        Debug::Draw();
        Draw();
        if(fpsClock.getElapsedTime().asSeconds() > (1.f / 60))//120))
            fpsClock.restart();
    }
    return 0;
}

Game::~Game()
{
    //dtor
}
