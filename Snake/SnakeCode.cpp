#include "SnakeCode.h"
#include "GlobalVariables.h"
#include <iostream>

using namespace std;

const int width = 20;
const int height = 20;
bool gameOver = false;
int x, y;
int fruitX, fruitY;
int score;
eDirection dir;

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
	//Konsole "clearen"
	system("cls");

	//Obere Grenze des Spielfelds zeichnen
	for (int i = 0; i < width + 2; i++)
	{
		cout << "#";
	}
	cout << endl;

	//Seitlichen Grenzen des Spielfelds zeichnen
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			//Kontrollieren, ob man sich am Spielfeldrand befindet
			//Linker Spielfeldrand
			if (j == 0)
			{
				cout << "#";
			}

			//Schlangenkopf erzeugen
			if (i == y && j == x)
			{
				cout << "0";
			}

			//Frucht erzeugen
			else if (i == fruitX && j == fruitX)
			{
				cout << "X";
			}

			else
			{
				cout << " ";
			}

			//Rechter Spielfeldrand
			if (j == width - 1)
			{
				cout << "#";
			}
		}
		cout << endl;
	}

	//Untere Grenze des Spielfelds zeichnen
	for (int i = 0; i < width + 2; i++)
	{
		cout << '#';
	}
}


void Logic()
{

}


void Input()
{

}
