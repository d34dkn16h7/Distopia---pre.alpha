#include "player.h"
#include <iostream>
#define FRONT 0
#define RIGHT 1
#define LEFT 2
Player::Player(TextureManager &tManager,float xVal = 0,float yVal = 0)
{
    name = "Player";
    tmp = 1;
    speed = 1.25f;
    grav = 1;
    float scaleSize = 1;
    playerHeight = (tManager.GetTexture("pFront").getSize().y * scaleSize);
    up = false;
    down = false;
    right = false;
    left = false;
    jump = false;
    grounded = false;
    x = xVal;
    y = yVal - playerHeight;
    self[FRONT] = new Animation(tManager.GetAnimCount("pFront"),10,tManager.GetTextureVar("pFront"));
    self[RIGHT] = new Animation(tManager.GetAnimCount("pRight"),10,tManager.GetTextureVar("pRight"));
    self[LEFT] = new Animation(tManager.GetAnimCount("pLeft"),10,tManager.GetTextureVar("pLeft"));
}
void Player::draw()
{
    if(left && !right)
    {
        self[LEFT]->draw(mWindow,x,y);
    }
    else if(right && !left)
    {
        self[RIGHT]->draw(mWindow,x,y);
    }
    else
    {
        self[FRONT]->draw(mWindow,x,y);
    }
}
void Player::update()
{
    self[FRONT]->c_update();
    self[RIGHT]->c_update();
    self[LEFT]->c_update();
    grounded = y >= (mWindow.getSize().y - playerHeight);
    if(right && !left)
    {
        x += speed;
    }
    if(!right && left)
    {
        x -= speed;
    }
    if(up && !jump && grounded)
    {
        targetY = y - 200;
        _force.AddEvent((int)&y,"JumpEvent-Test.String",100,1.2f);
        jump = true;
    }
    if(jump)
    {
        if(targetY < y)
        {
            jump = false;
            y -= _force.GetUpdate((int)&y);//Force::Push(y,.5);
            //y -= grav;
        }
        //else
        //    jump = false;
    }
    else if(y < (mWindow.getSize().y - playerHeight) && !grounded) // simple grav,
    {
        y += grav;
    }

/*    for (int i = 0; i < spriteCount; ++i)
    {
        self[i].setPosition(x,y);
    }*/
}
void Player::input()
{
    right = sf::Keyboard::isKeyPressed(sf::Keyboard::D);
    left = sf::Keyboard::isKeyPressed(sf::Keyboard::A);
    up = sf::Keyboard::isKeyPressed(sf::Keyboard::W);
    down = sf::Keyboard::isKeyPressed(sf::Keyboard::S);
}
