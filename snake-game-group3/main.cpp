#include <iostream>

using namespace std;

// Khoi tao chieu rong và cao cho man hinh game
const int width = 80;
const int height = 20;

// Snake head coordinates of snake (x-axis, y-axis)
int x, y;
// Food coordinates
int fruitCordX, fruitCordY;
// variable to store the score of he player
int playerScore;
// Array to store the coordinates of snake tail (x-axis,
// y-axis)
int snakeTailX[100], snakeTailY[100];
// variable to store the length of the sanke's tail
int snakeTailLen;
// for storing snake's moving snakesDirection
enum snakesDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
// snakesDirection variable
snakesDirection sDir;
// boolean variable for checking game is over or not
bool isGameOver;

// Function for updating the game state
void UpdateGame()
{
	int prevX = snakeTailX[0];
	int prevY = snakeTailY[0];
	int prev2X, prev2Y;
	snakeTailX[0] = x;
	snakeTailY[0] = y;

	for (int i = 1; i < snakeTailLen; i++) {
		prev2X = snakeTailX[i];
		prev2Y = snakeTailY[i];
		snakeTailX[i] = prevX;
		snakeTailY[i] = prevY;
		prevX = prev2X;
		prevY = prev2Y;
	}

	switch (sDir) {
	case LEFT:
		x--;
		break;
	case RIGHT:
		x++;
		break;
	case UP:
		y--;
		break;
	case DOWN:
		y++;
		break;
	}

	// Checks for snake's collision with the wall (|)
	if (x >= width || x < 0 || y >= height || y < 0)
		isGameOver = true;

	// Checks for collision with the tail (o)
	for (int i = 0; i < snakeTailLen; i++) {
		if (snakeTailX[i] == x && snakeTailY[i] == y)
			isGameOver = true;
	}

	// Checks for snake's collision with the food (#)
	if (x == fruitCordX && y == fruitCordY) {
		playerScore += 10;
		fruitCordX = rand() % width;
		fruitCordY = rand() % height;
		snakeTailLen++;
	}
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
