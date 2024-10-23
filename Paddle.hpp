#pragma once

#include<raylib.h>

class Paddle {

public:
	float posX, posY;
	float speed;
	float width, height;
	int winWidth, winHeight;

	Rectangle getRec();

	Paddle(int WINDOW_WIDTH, int WINDOW_HEIGHT, float x, float y);

	void draw();

	void update(float deltaTime);

	void ai(float deltaTime, float ballY, float ballX, float velX);

};