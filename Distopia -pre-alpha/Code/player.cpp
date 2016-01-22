#include "player.h"
#include <iostream>
#include <vector>
#define FRONT 0
#define RIGHT 1
#define LEFT 2

Player::Player(float xVal,float yVal)
{
    name = "player";
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
    m_render = new Renderer(name,this);
}
void Player::Update()
{

    reRect();
    M_Rect tmp = position;

    if(right && !left && !c_left) tmp.c_x += (speed * scale);
    if(!right && left && !c_right) tmp.c_x -= (speed * scale);
    if(up && !down) tmp.c_y -= (speed * scale);
    if(!up && down) tmp.c_y += (speed * scale);
    position = tmp;
    reRect();
}
void Player::mouseEvent(sf::Vector2i mPos)
{
    if(position.Contain(mPos))
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
