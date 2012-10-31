#include "player.h"
#include <iostream>
Player::Player(TextureManager &tManager,float xVal = 0,float yVal = 0)
{
    animTimer = 15;//6
    animRightIndex = 0;
    animLeftIndex = 0;
    animFrontIndex = 0;
    animJumpIndex = 0;
    animRightToNext = 0;
    animLeftToNext= 0;
    animFrontToNext = 0;
    animJumpToNext = 0;
    spriteCount = 3;
    speed = .5f;
    grav = 1;
    float scaleSize = 2;
    playerHeight = (tManager.GetTexture("pFront").getSize().y * scaleSize);
    animRightReset = true;
    animLeftReset = true;
    animFrontReset = true;
    up = false;
    down = false;
    right = false;
    left = false;
    jump = false;
    grounded = false;
    x = xVal;
    y = yVal - playerHeight;

    sf::Sprite playerSprite[spriteCount];
    playerSprite[0].setTexture(tManager.GetTexture("pFront"));
    animFrontLenght = tManager.GetAnimCount("pFront");
    playerSprite[1].setTexture(tManager.GetTexture("pRight"));
    animRightLenght = tManager.GetAnimCount("pRight");
    playerSprite[2].setTexture(tManager.GetTexture("pLeft"));
    animLeftLenght = tManager.GetAnimCount("pLeft");
    playerSprite[3].setTexture(tManager.GetTexture("pJump"));
    animJumpLenght = tManager.GetAnimCount("pJump");

    for (int i = 0; i < spriteCount; ++i)
    {
        self[i] = playerSprite[i];
        self[i].setScale(scaleSize,scaleSize);
        self[i].setPosition(x,y);
    }
}
void Player::draw()
{
    if((!right && !left) || (right && left))
    {
        animFrontToNext++;
        if(animFrontReset)
        {
            self[0].setTextureRect(sf::IntRect(animFrontIndex * 32,0,32,64));
            animFrontReset = false;
        }
        mWindow.draw(self[0]);
        if(animFrontToNext > animTimer)
        {
            animFrontIndex++;
            if(animFrontIndex >= animFrontLenght)
            {
                animFrontIndex = 0;
            }
            animFrontToNext = 0;
            animFrontReset = true;
        }
    }
    else if(right)
    {
        animRightToNext++;
        if(animRightReset)
        {
            self[1].setTextureRect(sf::IntRect(animRightIndex * 32,0,32,64));
            animRightReset = false;
        }
        mWindow.draw(self[1]);
        if(animRightToNext > animTimer)
        {
            animRightIndex++;
            if(animRightIndex >= animRightLenght)
            {
                animRightIndex = 0;
            }
            animRightToNext = 0;
            animRightReset = true;
        }
    }
    else
    {
        animLeftToNext++;
        if(animLeftReset)
        {
            self[2].setTextureRect(sf::IntRect(animLeftIndex * 32,0,32,64));
            animLeftReset = false;
        }
        mWindow.draw(self[2]);
        if(animLeftToNext > animTimer)
        {
            animLeftIndex++;
            if(animLeftIndex >= animLeftLenght)
            {
                animLeftIndex = 0;
            }
            animLeftToNext = 0;
            animLeftReset = true;
        }
    }
}
void Player::update()
{
    grounded = y >= (mWindow.getSize().y - playerHeight);
    ///std::cout << (grounded ? "TRUE" : "FALSE") << std::endl;
    ///std::cout << (jump ? "TRUE" : "FALSE") << std::endl;
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
        ///std::cout << (int)&y << std::endl;
        jump = true;
    }
    if(jump)
    {
        ///std::cout << _force.GetEvent((int)&y) << std::endl;
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

    for (int i = 0; i < spriteCount; ++i)
    {
        self[i].setPosition(x,y);
    }
}
void Player::input()
{
    right = sf::Keyboard::isKeyPressed(sf::Keyboard::D);
    left = sf::Keyboard::isKeyPressed(sf::Keyboard::A);
    up = sf::Keyboard::isKeyPressed(sf::Keyboard::W);
    down = sf::Keyboard::isKeyPressed(sf::Keyboard::S);
}
