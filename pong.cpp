#include<raylib.h>
#include"Ball.hpp"
#include"Paddle.hpp"


const int WINDOW_HEIGHT = 720;
const int WINDOW_WIDTH = 1280;

int main()
{
	InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Pong");
	SetTargetFPS(60);
	Ball ball(WINDOW_WIDTH, WINDOW_HEIGHT);
	Paddle leftPaddle(WINDOW_WIDTH, WINDOW_HEIGHT, 50, WINDOW_HEIGHT / 2 - 50);
	Paddle rightPaddle(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_WIDTH - 50, WINDOW_HEIGHT / 2 - 50);
	rightPaddle.speed = 298.5;


	while (!WindowShouldClose())
	{
		//Update & Input Functions
		float dt = GetFrameTime();
		ball.update(dt, leftPaddle.getRec(), rightPaddle.getRec());
		leftPaddle.update(dt);
		rightPaddle.ai(dt, ball.posY, ball.posX, ball.velX);

		//Draw Functions
		BeginDrawing();
		ClearBackground(BLACK);
		DrawLine(WINDOW_WIDTH / 2, 0, WINDOW_WIDTH / 2, WINDOW_HEIGHT, WHITE);
		ball.draw();
		DrawRectangleRounded(leftPaddle.getRec(), 6, 3, WHITE);
		DrawRectangleRounded(rightPaddle.getRec(), 6, 3, WHITE);


		DrawFPS(2, 2);
		EndDrawing();

	}

	CloseWindow();
}