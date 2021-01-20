#pragma once


//Game Over
extern bool gameOver;

//Dimensionen des Bildschirms
extern const int width;
extern const int height;

//Variablen für den Kopf der Schlange
extern int x, y;

//Variable für die Früchte
extern int fruitX, fruitY;

//Score
extern int score;

//Bewegungsrichtungen der Schlange
enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN};
extern eDirection dir;