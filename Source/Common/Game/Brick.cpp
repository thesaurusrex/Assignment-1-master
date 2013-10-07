//  Brick.cpp
//  GAM-1514 OSX Game
//  Created by Breanna Henry on 2013-09-27.
//  Copyright (c) 2013 Algonquin College. All rights reserved.

#include "Brick.h"
#include "../Constants/Constants.h"
#include "../Screen Manager/ScreenManager.h"
#include "../OpenGL/OpenGL.h"

Brick::Brick(float x , float y) : GameObject()
{
    setPosition(x, y);
	m_BrickTexture = new OpenGLTexture("GameBrick-Level1");
}

Brick::~Brick()
{
	//Texture
	if(m_BrickTexture != NULL)
	{
		delete m_BrickTexture;
		m_BrickTexture = NULL;
	}
}

void Brick::update(double delta)
{
    
}

void Brick::paint()
{
    //Draw the brick
	OpenGLRenderer::getInstance()->drawTexture(m_BrickTexture, getX(), getY(), getWidth(), getHeight(), false);
}

void Brick::reset()
{
    //Get the screen width and height
    float screenWidth = ScreenManager::getInstance()->getScreenWidth();
    float screenHeight = ScreenManager::getInstance()->getScreenHeight();
    
    //Reset the Brick's width and height
    setWidth(screenWidth * GAME_BRICK_WIDTH_PERCENTAGE);
    setHeight(screenHeight * GAME_BRICK_HEIGHT_PERCENTAGE);
    
    //Reset the brick to active
    setIsActive(true);
}

const char* Brick::getType()
{
    return GAME_BRICK_TYPE;
}

void Brick::setSize(float aWidth, float aHeight)
{
    setWidth(aWidth);
    setHeight(aHeight);
}

void Brick::setWidth(float aWidth)
{
    m_Width = aWidth;
}

void Brick::setHeight(float aHeight)
{
    m_Height = aHeight;
}

void Brick::getSize(float &aWidth, float &aHeight)
{
    aWidth = getWidth();
    aHeight = getHeight();
}

float Brick::getWidth()
{
    return m_Width;
}

float Brick::getHeight()
{
    return m_Height;
}
