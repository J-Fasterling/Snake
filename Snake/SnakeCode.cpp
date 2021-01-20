#include "SnakeCode.h"
#include "GlobalVariables.h"
#include <iostream>

using namespace std;


void Setup()
{
	//Anfangseinstellungen
	gameOver = false;
	dir = STOP;
	score = 0;

	//Startposition der Schlange
	x = width / 2;
	y = height / 2;

	//Frucht zufällig platziern
	fruitX = rand() % width;
	fruitY = rand() % height;

}


void Draw()
{
	
}


void Logic()
{

}


void Input()
{

}
