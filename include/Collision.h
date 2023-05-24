#ifndef COLLISION_H
#define COLLISION_H


#include "Enemy.h"
#include "Player.h"
#include "Bullet.h"
#include "Game_Utils.h"
void Collision(vector<Enemy*> &Enemy_List,Player &spaceship,vector<Bullet*> &Bullet_List,int &current_score,bool &GameOver,Mix_Chunk* shot_sound,SDL_Renderer* screen);


#endif // COLLISION_H
