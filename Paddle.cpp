#include "Paddle.hpp"
#include<raylib.h>

Paddle::Paddle(int WINDOW_WIDTH, int WINDOW_HEIGHT, float x, float y)
{
	this->winWidth = WINDOW_WIDTH;
	this->winHeight = WINDOW_HEIGHT;
	this->posX = x;
	this->posY = y;
	height = 100.0f;
	width = 20.0f;
	speed = 300.0f;
}

void Paddle::draw()
{
	DrawRectangle((int)posX, (int)posY, (int)width, (int)height, WHITE);
}

void Paddle::update(float deltaTime)
{
	if (IsKeyDown(KEY_W) && posY > 0)
		posY -= speed * deltaTime;
	if (IsKeyDown(KEY_S) && posY + height <= winHeight)
		posY += speed * deltaTime;
}

void Paddle::ai(float deltaTime, float ballY, float ballX, float ballVelX)
{
	if (ballVelX < 0 && ballX > 900 || ballVelX > 0 && ballX > winWidth / 3.0f)
	{
		if (ballY < posY && posY >0)
			posY -= speed * deltaTime;
		if (ballY > posY && posY + height <= winHeight)
			posY += speed * deltaTime;
	}

}

Rectangle Paddle::getRec()
{
	return Rectangle{ posX,posY,width,height };
}

