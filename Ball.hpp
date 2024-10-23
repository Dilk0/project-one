#pragma once
#include<raylib.h>

class Ball {
public:
	float posX, posY;
	float velX, velY;
	float radius;
	int winWidth, winHeight;

	Ball(int WIDTH, int HEIGHT);

	void draw();

	void update(float deltaTime, Rectangle leftRect, Rectangle rightRec);
};