#include "SnakeCode.h"
#include "GlobalVariables.h"
#include <iostream>
#include <conio.h>

using namespace std;

const int width = 20;
const int height = 20;
bool gameOver = false;
int x, y;
int fruitX, fruitY;
int score;
int tailX[100], tailY[100];
int iTail;
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
				bool print = false;
				for (int k = 0; k < iTail; k++)
				{
					//
					if (tailX[k] == j && tailY[k] == i)
					{
						cout << "o";
						print = true;
					}
				}
				if (!print)
				{
					cout << " ";
				}
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

	cout << endl;
	cout << "Score: " << score << endl;
}



void Input()
{
	//Kontrollieren, ob Eingabe auf Tastatur getätigt wurde
	if (_kbhit())
	{
		//Richtung bestimmen
		switch (_getch())
		{
		case 'w':
			dir = UP;
			break;

		case 'a':
			dir = LEFT;
			break;

		case 's':
			dir = DOWN;
			break;

		case 'd':
			dir = RIGHT;
			break;

		case 'q':
			gameOver = true;
			break;

		default:
			break;
		}
	}
}




void Logic()
{
	int prevX = tailX[0];
	int prevY = tailY[0];
	int prev2X, prev2Y;

	//Anfangswerte des Schwanz dem Kopf zuordnen
	tailX[0] = x;
	tailY[0] = y;

	//Schwanz in Reihenfolge zuordnen
	for (int i = 1; i < iTail; i++)
	{
		prev2X = tailX[i];
		prev2Y = tailY[i];
		tailX[i] = prevX;
		tailY[i] = prevY;
		prevX = prev2X;
		prevY = prev2Y;
	}

	//Schlange bewegen
	switch (dir)
	{
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

	default:
		break;
	}

	//Game Over, wenn man über den Spielfeldrand hinaus geht
	if (x > width || x < 0 || y > height || y < 0)
	{
		gameOver = true;
	}


	//Game Over wenn man sich selbst in den Schwanz beißt
	for (int i = 0; i < iTail; i++)
	{
		if (tailX[i] == x && tailY[i] == y)
		{
			gameOver = true;
		}
	}

	//Beim essen einer Frucht Score erhöhen und neue Frucht plaziernas
	if (x == fruitX && y == fruitY)
	{
		score += 10;
		fruitX = rand() % width;
		fruitY = rand() % height;
		iTail++;
	}
}

