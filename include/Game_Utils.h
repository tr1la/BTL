#ifndef GAME_UTILS_H
#define GAME_UTILS_H

#include <cstdlib>
#include <iostream>
#include <ctime>
#include <vector>
#include<iomanip>
#include <sstream>
#include <fstream>
#include<cmath>
#include<string>
#include<SDL.h>
#include<SDL_image.h>
#include<SDL_mixer.h>
#include<SDL_ttf.h>
using namespace std;

static const int SCREEN_WIDTH = 720;
static const int SCREEN_HEIGHT = 720;
const double PI =3.141592653589793238462643383279;

bool CheckCollision(const SDL_Rect &object1,const SDL_Rect &object2);
void UpdateHighScore(int score);
int RandomNumber(int min, int max);
int HighScore();

string number_to_string(int number);
string number_to_string_1(int number);


static SDL_Window* m_Window=NULL;
static SDL_Renderer* m_Renderer=NULL;



#endif // GAME_UTILS_H
