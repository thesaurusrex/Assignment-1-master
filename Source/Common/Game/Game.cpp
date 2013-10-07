#include "Game.h"
#include "GameObject.h"
#include "Paddle.h"
#include "Ball.h"
#include "Brick.h"
#include "../OpenGL/OpenGL.h"
#include "../Constants/Constants.h"
#include "..//Utils/Utils.h"
#include "../Screen Manager/ScreenManager.h"

int NumOfBricks = 24;
int GameLevel = 1;

Game::Game()
{
	//Background
	m_BackgroundTexture = new OpenGLTexture("BrickBreakerBackground-Level1-3Lives");

    //Create a new paddle and ball
    addGameObject(new Paddle());
    addGameObject(new Ball());
    
	//Set the screen size
    float screenWidth = ScreenManager::getInstance()->getScreenWidth();
    float screenHeight = ScreenManager::getInstance()->getScreenHeight();
    
	screenWidth = 1080.0f;
	screenHeight = 864.0f;

    //Place the bricks
    float x = 2;
    float y = 110;
    for(int i = 0 ; i < 24 ; i ++)
    {
		NumOfBricks == 24;
        addGameObject(new Brick(x , y));
        x +=  screenWidth * GAME_BRICK_WIDTH_PERCENTAGE;
        
        if(i == 7 || i == 15)
        {
            y += screenHeight * GAME_BRICK_HEIGHT_PERCENTAGE;
            x = 2;

				if(NumOfBricks == 0)
				{
					reset();
					Level2();
				}
        }
    }
}

void Game::Level2()
{
	m_BackgroundTexture = new OpenGLTexture("BrickBreakerBackground-Level2-3Lives");

		//Create a new paddle and ball
		addGameObject(new Paddle());
		addGameObject(new Ball());
    
		//Set the screen size
		float screenWidth = ScreenManager::getInstance()->getScreenWidth();
		float screenHeight = ScreenManager::getInstance()->getScreenHeight();
    
		screenWidth = 1080.0f;
		screenHeight = 864.0f;

		//Place the bricks
		float x = 2;
		float y = 110;
		for(int i = 0 ; i < 31 ; i ++)
		{
			NumOfBricks = 31;
			addGameObject(new Brick(x , y));
			NumOfBricks++;
			x +=  screenWidth * GAME_BRICK_WIDTH_PERCENTAGE;
        
			if(i == 7 || i == 15 || i == 25)
			{
				y += screenHeight * GAME_BRICK_HEIGHT_PERCENTAGE;
				x = 2;
			}
		}
}


Game::~Game()
{
	//Delete all the GameObject's in the vector
	for(int i = 0; i < m_GameObjects.size(); i++)
	{
		delete m_GameObjects.at(i);
		m_GameObjects.at(i) = NULL;
	}
  
	//Texture
	if(m_BackgroundTexture != NULL)
	{
		delete m_BackgroundTexture;
		m_BackgroundTexture = NULL;
	}

	//Clear the pointers from the vector
	m_GameObjects.clear();
}

void Game::update(double aDelta)
{
	//If the GameOver Timer is greater that zero, countdown
	if(m_GameOverTimer > 0.0)
	{
		m_GameOverTimer -= aDelta;
	
	if(m_GameOverTimer < 0.0)
    {
		m_GameOverTimer = 0.0;
		reset();
    }
    return;
 }

	//Get the ball GameObject, we'll use this for collision detection
	Ball* ball = (Ball*)getGameObjectByType(GAME_BALL_TYPE);

	//Cycle through all the game objects update them and check their collision detection
	for(int i = 0; i < m_GameObjects.size(); i++)
	{
		//Make sure the GameObject is active
		if(m_GameObjects.at(i)->getIsActive() == true)
		{
			//Update the GameObject
			m_GameObjects.at(i)->update(aDelta);
      
			//Check collision detection against the ball
			if(m_GameObjects.at(i) != ball)
			{
				ball->checkCollision(m_GameObjects.at(i));
			}
		}
	}
}

void Game::paint()
{
	//Draw Background
	OpenGLRenderer::getInstance()->drawTexture(m_BackgroundTexture, 0.0f, 0.0f);

	//Cycle through and draw all the game objects
	for(int i = 0; i < m_GameObjects.size(); i++)
	{
		if(m_GameObjects.at(i)->getIsActive() == true)
		{
			m_GameObjects.at(i)->paint();
		}
	}
}

void Game::reset()
{
  //Cycle through and reset all the game objects
  for(int i = 0; i < m_GameObjects.size(); i++)
  {
    m_GameObjects.at(i)->reset();
  }
  
  //Reset the game over timer to zero
  m_GameOverTimer = 0.0;
}

void Game::gameOver()
{
  m_GameOverTimer = GAME_OVER_TIMER;
}

const char* Game::getName()
{
	return GAME_SCREEN_NAME;
}

void Game::screenWillAppear()
{
  OpenGLRenderer::getInstance()->setBackgroundColor(OpenGLColorCornflowerBlue());
}

void Game::addGameObject(GameObject* aGameObject)
{
  if(aGameObject != NULL)
  {
    m_GameObjects.push_back(aGameObject);
  }
}

GameObject* Game::getGameObjectByType(const char* aType)
{
  //Cycle through a find the game object (if it exists)
  for(unsigned int i = 0; i < m_GameObjects.size(); i++)
  {
    if(strcmp(m_GameObjects.at(i)->getType(), aType) == 0)
    {
      return m_GameObjects.at(i);
    }
  }
  return NULL;
}

void Game::mouseMovementEvent(float aDeltaX, float aDeltaY, float aPositionX, float aPositionY)
{
  //Set the paddle to the x position of the mouse
  Paddle* paddle = (Paddle*)getGameObjectByType(GAME_PADDLE_TYPE);

  //Safety check, paddle could be NULL
  if(paddle != NULL)
  {
    paddle->setX(aPositionX - (paddle->getWidth() / 2.0f));
  }
}

void Game::keyUpEvent(int aKeyCode)
{
    if (aKeyCode == KEYCODE_R)
    {
        reset();
    
    }
}
