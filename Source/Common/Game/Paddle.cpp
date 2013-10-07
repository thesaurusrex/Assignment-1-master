//
//  Paddle.cpp
//  GAM-1532 OSX Game
//
//  Created by Bradley Flood on 2013-01-09.
//  Copyright (c) 2013 Algonquin College. All rights reserved.
//

#include "Paddle.h"
#include "../Constants/Constants.h"
#include "../Screen Manager/ScreenManager.h"
#include "../OpenGL/OpenGL.h"


Paddle::Paddle() : GameObject()
{
	m_PaddleTexture = new OpenGLTexture("GamePaddle");
}

Paddle::~Paddle()
{
	//Texture
	if(m_PaddleTexture != NULL)
	{
		delete m_PaddleTexture;
		m_PaddleTexture = NULL;
	}
}

void Paddle::update(double aDelta)
{

}

void Paddle::paint()
{
	//Draw Paddle
	OpenGLRenderer::getInstance()->drawTexture(m_PaddleTexture, getX(), getY(), getWidth(), getHeight());
}

void Paddle::reset()
{
	//Get the screen width and height
	float screenWidth = ScreenManager::getInstance()->getScreenWidth();
	float screenHeight = ScreenManager::getInstance()->getScreenHeight();

	//Set the paddle's width and height
	setWidth(150.0f);
	setHeight(125.0f);
  
	//Reset the x and y position
	setX((screenWidth - getWidth()) / 2.0f);
	setY(screenHeight * GAME_PADDLE_Y_PERCENTAGE);

	//Reset the paddle to active
	setIsActive(true);
}

const char* Paddle::getType()
{
	return GAME_PADDLE_TYPE;
}

void Paddle::setSize(float aWidth, float aHeight)
{
	setWidth(aWidth);
	setHeight(aHeight);
}

void Paddle::setWidth(float aWidth)
{
	m_Width = aWidth;
}

void Paddle::setHeight(float aHeight)
{
	m_Height = aHeight;
}

void Paddle::getSize(float &aWidth, float &aHeight)
{
	aWidth = getWidth();
	aHeight = getHeight();
}

float Paddle::getWidth()
{
	return m_Width;
}

float Paddle::getHeight()
{
	return m_Height;
}
  