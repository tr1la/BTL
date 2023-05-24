#include "Bullet.h"

Bullet::Bullet()
{
    x_speed=0;
    y_speed=0;
    is_move=false;
    angle=90;
    //type=1;
    starting_point=0;
}

Bullet::~Bullet()
{

}

void Bullet::HandleMove(const int &x_border,const int &y_border)
{

    y_pos -= y_speed;
    if (y_pos <0)
    {
      is_move = false;
    }
    Rect.x=x_pos;
    Rect.y=y_pos;
}
/*
void Bullet::HandleEnemyMove()
{
    x_pos+=x_speed*cos(angle*PI/180);
    y_pos+=y_speed*sin(angle*PI/180);

    if(y_pos>SCREEN_HEIGHT||y_pos <0)
    {
    is_move=false;
    }
    else if(x_pos>SCREEN_WIDTH|| x_pos< 0)
    {
    is_move=false;
    }

    Rect.x=x_pos;
    Rect.y=y_pos;

}
*/

void Bullet::HandleEnemyMove(const int &x_border,const int &y_border)
{
    x_pos+=x_speed*cos(angle*PI/180);
    y_pos+=y_speed*sin(angle*PI/180);
    if(y_pos+2*height_frame>y_border||y_pos <-500)
    {
    is_move=false;
    }
    if(x_pos+width_frame>x_border||x_pos<-500)
    {
    is_move=false;
    }
    Rect.x=x_pos;
    Rect.y=y_pos;


}



