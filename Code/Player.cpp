#include "player.h"
#include <iostream>
#include <vector>
#define FRONT 0
#define RIGHT 1
#define LEFT 2
Player::Player(TextureManager &tManager,float xVal = 0,float yVal = 0)
{
    name = "Player";
    tmp = 1;
    scale = 1;
    speed = 1.25f;
    grav = .5f;
    up = false;
    down = false;
    right = false;
    left = false;
    c_right = false;
    c_left = false;
    jump = false;
    grounded = false;
    position.c_x = xVal;
    position.c_y = yVal;
    position.w = 32;
    position.h = 64;
    position.calc();
    m_render = new Renderer(name);
}
void Player::update()
{

    reRect();
    m_rect tmp = position;

    if(right && !left && !c_left) tmp.c_x += (speed * scale);
    if(!right && left && !c_right) tmp.c_x -= (speed * scale);
    if(up && !down) tmp.c_y -= (speed * scale);
    if(!up && down) tmp.c_y += (speed * scale);
    position = tmp;
    reRect();
}
void Player::mouseEvent(sf::Vector2i mPos)
{
    if(position.contain(mPos))
    {
        cout << "Player clicked!" << endl;
    }
}
void Player::input()
{
    right = sf::Keyboard::isKeyPressed(sf::Keyboard::D);
    left = sf::Keyboard::isKeyPressed(sf::Keyboard::A);
    up = sf::Keyboard::isKeyPressed(sf::Keyboard::W);
    down = sf::Keyboard::isKeyPressed(sf::Keyboard::S);
}
