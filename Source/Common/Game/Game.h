#ifndef GAME_H
#define GAME_H

#include <vector>
#include "../Screen Manager/Screen.h"

class GameObject;
class OpenGLTexture;

extern int NumOfBricks;
extern int GameLevel;

class Game : public Screen
{
public:
	Game();
	~Game();

	//Game lifecycle methods
	void update(double delta);
	void paint();
	void reset();
	void Level2();

	//Game Over method, call this when to end the game
	void gameOver();

	//Screen name, must be implemented, it's a pure
	//virtual method in the Screen class
	const char* getName();
  
	//Screen event method, inherited from the screen class
	void screenWillAppear();

	//GameObject Methods
	void addGameObject(GameObject* gameObject);
	GameObject* getGameObjectByType(const char* type);

private:
	  //Mouse Events
	  void mouseMovementEvent(float deltaX, float deltaY, float positionX, float positionY);

	  //Texture Pointer
	  OpenGLTexture* m_BackgroundTexture;

	  //Key Events
	  void keyUpEvent(int keyCode);

	  //Vector to hold the GameObjects
	  std::vector<GameObject*> m_GameObjects;
  
	  //Timer variable to delay reseting the game has ended
	  double m_GameOverTimer;
};

#endif