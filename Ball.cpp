#include "Ball.hpp"
#include<raylib.h>


Ball::Ball(int WIDTH, int HEIGHT)
{
	this->winWidth = WIDTH;
	this->winHeight = HEIGHT;
	posX = winWidth / 2.0f;
	posY = winHeight / 2.0f;
	velX = 300.0f;
	velY = 300.0f;
	radius = 10;
}

void Ball::draw()
{
	DrawCircle((int)posX, (int)posY, radius, WHITE);
}

void Ball::update(float deltaTime, Rectangle leftRect, Rectangle rightRect)
{
	posX += velX * deltaTime;
	posY += velY * deltaTime;

	if (posY < 0 || posY + radius >= winHeight)
	{
		velY *= -1;
	}
	if (posX < 0 || posX + radius >= winWidth)
	{
		velX *= -1;
		posX = winWidth / 2.0f;
		posY = winHeight / 2.0f;
	}

	if (CheckCollisionCircleRec(Vector2{ posX,posY }, radius, leftRect) && velX < 0 || CheckCollisionCircleRec(Vector2{ posX,posY }, radius, rightRect) && velX > 0)
		velX *= -1;
}


