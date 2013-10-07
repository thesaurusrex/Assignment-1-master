//  Brick.h
//  GAM-1514 OSX Game
//  Created by Breanna Henry on 2013-09-27.
//  Copyright (c) 2013 Algonquin College. All rights reserved.

#ifndef GAM_1514_OSX_Game_Brick_h
#define GAM_1514_OSX_Game_Brick_h

#include "GameObject.h"

class OpenGLTexture;

class Brick : public GameObject
{
public:
    Brick(float x , float y);
    ~Brick();
    
    void update(double delta);
    void paint();
    
    void reset();
    
    const char* getType();

    void setSize(float width, float height);
    void setWidth(float width);
    void setHeight(float height);

    void getSize(float &width, float &height);
    float getWidth();
    float getHeight();

	OpenGLTexture* m_BrickTexture;

protected:
    float m_Width;
    float m_Height;
};

#endif
