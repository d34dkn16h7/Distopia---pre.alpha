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
    speed = 1.25f;
    grav = 1;
    up = false;
    down = false;
    right = false;
    left = false;
    jump = false;
    grounded = false;
    position.c_x = xVal;
    position.c_y = yVal;
    position.w = 32;
    position.h = 64;
    position.calc();
    self[FRONT] = new Animation(tManager.GetAnimCount("pFront"),10,tManager.GetTextureVar("pFront"));
    self[RIGHT] = new Animation(tManager.GetAnimCount("pRight"),10,tManager.GetTextureVar("pRight"));
    self[LEFT] = new Animation(tManager.GetAnimCount("pLeft"),10,tManager.GetTextureVar("pLeft"));
}
void Player::draw()
{
    if(left && !right) self[LEFT]->draw(mWindow,position);
    else if(right && !left) self[RIGHT]->draw(mWindow,position);
    else self[FRONT]->draw(mWindow,position);
}
void Player::update()
{
    self[FRONT]->c_update();
    self[RIGHT]->c_update();
    self[LEFT]->c_update();
    //grounded = y >= (mWindow.getSize().y - playerHeight);
    if(right && !left) position.c_x += speed;
    if(!right && left) position.c_x -= speed;
    if(up && !down) position.c_y -= speed;
    if(!up && down) position.c_y += speed;

    /*if(up && !jump)
    {
        targetY = position.c_y - 200;
        _force.AddEvent((int)&position.c_y,"JumpEvent-Test.String",100,1.2f);
        jump = true;
    }
    if(jump)
    {
        if(targetY < position.c_y)
        {
            jump = false;
            position.c_y -= _force.GetUpdate((int)&position.c_y);//Force::Push(y,.5);
            position.c_y -= grav;
        }
        else
            jump = false;
    }
    else*/ if(!up &&position.bottom < (mWindow.getSize().y) && !grounded) // simple grav,
    {
        position.c_y += grav;
    }
    position.calc();
}
void Player::input()
{
    right = sf::Keyboard::isKeyPressed(sf::Keyboard::D);
    left = sf::Keyboard::isKeyPressed(sf::Keyboard::A);
    up = sf::Keyboard::isKeyPressed(sf::Keyboard::W);
    down = sf::Keyboard::isKeyPressed(sf::Keyboard::S);
}
void Player::onCollision(vector<Collider> vec)
{
    grounded = false;
    for(unsigned int i = 0;i < vec.size();i++)
    {
        switch(vec[i].side)
        {
            case Bottom:/*
            if(vec[i].tag == "wDirt")
            {

            }*/
            grounded = true;
            break;
        }

    }
}
