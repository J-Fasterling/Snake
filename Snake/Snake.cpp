// Snake.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>
#include "SnakeCode.h"
#include "GlobalVariables.h"

int main()
{
	Setup();

	while (!gameOver)
	{
		Draw();
		Input();
		Logic();
	}
}

