#pragma once

//Game Over
extern bool gameOver = false;

//Dimensionen des Bildschirms
const int width = 20;
const int height = 20;

//Variablen für den Kopf der Schlange
int x, y;

//Variable für die Früchte
int fruitX, fruitY;

//Score
int score;

//Bewegungsrichtungen der Schlange
enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN};
eDirection dir;