#include "Enemy_Array.h"


void EnemyArray_Type1(vector<Enemy*> &EnemyArray,SDL_Renderer* screen)
{
    for(int i=0;i<3;i++)
    {
        Enemy* p_enemy1=new Enemy();
        p_enemy1->set_type_threat(1);
        p_enemy1->set_stats(screen);
        p_enemy1->set_x_pos(SCREEN_WIDTH/2-(p_enemy1->get_width_frame())/2-120*(i-1));
        p_enemy1->set_y_limit(50);
        p_enemy1->set_y_pos(-3*p_enemy1->get_height_frame());

        p_enemy1->set_health(100);
        EnemyArray.push_back(p_enemy1);
    }
}

void EnemyArray_Type2(vector<Enemy*> &EnemyArray,SDL_Renderer* screen)
{
    for(int i=0;i<4;i++)
    {
        Enemy* p_enemy1=new Enemy();
        p_enemy1->set_type_threat(1);
        p_enemy1->set_stats(screen);
        if (i <= 1)
        {
            p_enemy1->set_x_pos(SCREEN_WIDTH/2-((p_enemy1->get_width_frame())+60)*(i+1));
            p_enemy1->set_y_limit(50-p_enemy1->get_height_frame()*(i-1));
            p_enemy1->set_y_pos((50-p_enemy1->get_height_frame()*(i-1))-3*p_enemy1->get_height_frame());
        }
        else if (i > 1)
        {
            p_enemy1->set_x_pos(SCREEN_WIDTH/2+60*(i-1)+(p_enemy1->get_width_frame())*(i-2));
            p_enemy1->set_y_limit(50-p_enemy1->get_height_frame()*(i-3));
            p_enemy1->set_y_pos(50-p_enemy1->get_height_frame()*(i-3)-3*p_enemy1->get_height_frame());
        }

        p_enemy1->set_health(100);
        EnemyArray.push_back(p_enemy1);
    }

        Enemy* p_enemy2=new Enemy();
        p_enemy2->set_type_threat(4.3);
        p_enemy2->set_stats(screen);
        p_enemy2->set_x_pos(SCREEN_WIDTH/2-p_enemy2->get_width_frame()/2);
        p_enemy2->set_y_limit(30);
        p_enemy2->set_y_pos(-3*p_enemy2->get_height_frame()/2-50);
        p_enemy2->set_health(100);
        EnemyArray.push_back(p_enemy2);

}
void EnemyArray_Type3(vector<Enemy*> &EnemyArray,SDL_Renderer* screen)
{
    for(int i=0;i<3;i++)
    {
        Enemy* p_enemy1=new Enemy();
        p_enemy1->set_type_threat(3.1);
        p_enemy1->set_stats(screen);
        p_enemy1->set_x_pos(SCREEN_WIDTH/2-(p_enemy1->get_width_frame())/2-200*(i-1));
        p_enemy1->set_y_limit(50);
        p_enemy1->set_y_pos(-3*p_enemy1->get_height_frame()/2);
        p_enemy1->set_health(100);
        EnemyArray.push_back(p_enemy1);
    }
}

void EnemyArray_Type4(vector<Enemy*> &EnemyArray,SDL_Renderer* screen)
{
        Enemy* p_enemy1=new Enemy();
        p_enemy1->set_type_threat(2.3);
        p_enemy1->set_stats(screen);
        p_enemy1->set_x_pos(SCREEN_WIDTH/2-(p_enemy1->get_width_frame())/2);
        p_enemy1->set_y_limit(50);
        p_enemy1->set_y_pos(-3*p_enemy1->get_height_frame()/2);
        p_enemy1->set_health(100);
        EnemyArray.push_back(p_enemy1);

        Enemy* p_enemy2=new Enemy();
        p_enemy2->set_type_threat(2.1);
        p_enemy2->set_stats(screen);
        p_enemy2->set_x_pos(SCREEN_WIDTH/2-(p_enemy2->get_width_frame())/2-200);
        p_enemy2->set_y_limit(50);
        p_enemy2->set_y_pos(-3*p_enemy2->get_height_frame()/2);
        p_enemy2->set_health(100);
        EnemyArray.push_back(p_enemy2);

        Enemy* p_enemy3=new Enemy();
        p_enemy3->set_type_threat(2.2);
        p_enemy3->set_stats(screen);
        p_enemy3->set_x_pos(SCREEN_WIDTH/2-(p_enemy2->get_width_frame())/2+200);
        p_enemy3->set_y_limit(50);
        p_enemy3->set_y_pos(-3*p_enemy2->get_height_frame()/2);
        p_enemy3->set_health(100);
        EnemyArray.push_back(p_enemy3);

}
void EnemyArray_Type5(vector<Enemy*> &EnemyArray,SDL_Renderer* screen)
{
        Enemy* p_enemy1=new Enemy();
        p_enemy1->set_type_threat(4.3);
        p_enemy1->set_stats(screen);
        p_enemy1->set_x_pos(SCREEN_WIDTH/2-p_enemy1->get_width_frame()/2);
        p_enemy1->set_y_limit(50);
        p_enemy1->set_y_pos(-SCREEN_HEIGHT/2-2*p_enemy1->get_height_frame()/2);
        p_enemy1->set_health(100);
        EnemyArray.push_back(p_enemy1);
}
void EnemyArray_Type6(vector<Enemy*> &EnemyArray,SDL_Renderer* screen)
{
        Enemy* p_enemy1=new Enemy();
        p_enemy1->set_type_threat(4.1);
        p_enemy1->set_stats(screen);
        p_enemy1->set_x_limit(SCREEN_WIDTH-p_enemy1->get_width_frame()-50);
        p_enemy1->set_x_pos(3*SCREEN_WIDTH/2-p_enemy1->get_width_frame());
        p_enemy1->set_y_pos(50);
        p_enemy1->set_health(100);
        EnemyArray.push_back(p_enemy1);

        Enemy* p_enemy2=new Enemy();
        p_enemy2->set_type_threat(4.2);
        p_enemy2->set_stats(screen);
        p_enemy2->set_x_limit(50);
        p_enemy2->set_x_pos(-SCREEN_WIDTH/2);
        p_enemy2->set_y_pos(50);
        p_enemy2->set_health(100);
        EnemyArray.push_back(p_enemy2);

        Enemy* p_enemy3=new Enemy();
        p_enemy3->set_type_threat(2.3);
        p_enemy3->set_stats(screen);
        p_enemy3->set_x_pos(SCREEN_WIDTH/2-(p_enemy3->get_width_frame())/2);
        p_enemy3->set_y_limit(50);
        p_enemy3->set_y_pos(-3*p_enemy1->get_height_frame()/2);
        p_enemy3->set_health(100);
        EnemyArray.push_back(p_enemy3);
}
void EnemyArray_Type7(vector<Enemy*> &EnemyArray,SDL_Renderer* screen)
{
        Enemy* p_enemy1=new Enemy();
        p_enemy1->set_type_threat(2.3);
        p_enemy1->set_stats(screen);
        p_enemy1->set_x_pos(SCREEN_WIDTH/2-p_enemy1->get_width_frame()/2);
        p_enemy1->set_y_limit(50);
        p_enemy1->set_y_pos(2-2*p_enemy1->get_height_frame()/2);
        p_enemy1->set_health(100);
        EnemyArray.push_back(p_enemy1);
}
void EnemyArray_Type0(vector<Enemy*> &EnemyArray,SDL_Renderer* screen)
{
       Enemy* p_enemy=new Enemy();
    p_enemy->set_type_threat(5);
    p_enemy->set_stats(screen);
    p_enemy->set_x_pos(SCREEN_WIDTH/2-(p_enemy->get_width_frame())/2);
    p_enemy->set_y_pos(-3*p_enemy->get_height_frame());
    p_enemy->set_health(5000);
    p_enemy->set_y_limit(0);
    EnemyArray.push_back(p_enemy);
}

void EnemyBoss(vector<Enemy*> &EnemyArray,SDL_Renderer* screen)
{
    Enemy* p_enemy=new Enemy();
    p_enemy->set_type_threat(5);
    p_enemy->set_stats(screen);
    p_enemy->set_x_pos(SCREEN_WIDTH/2-(p_enemy->get_width_frame())/2);
    p_enemy->set_y_pos(-3*p_enemy->get_height_frame());
    p_enemy->set_health(5000);
    p_enemy->set_y_limit(0);
    EnemyArray.push_back(p_enemy);
}


void GenerateEnemy(vector<Enemy*> &Enemy_List,SDL_Renderer* screen,int &wave)
{
    if(Enemy_List.size()<=0)
    {
        wave++;

        if(wave==1)
        {
           EnemyArray_Type1(Enemy_List,screen);
        }
        else if(wave==2)
        {
           EnemyArray_Type2(Enemy_List,screen);
        }
        else if(wave==3)
        {
           EnemyArray_Type3(Enemy_List,screen);
        }
        else if(wave==4)
        {
           EnemyArray_Type4(Enemy_List,screen);
        }
        else if(wave==5)
        {
           EnemyArray_Type5(Enemy_List,screen);
        }
        else if(wave==6)
        {
           EnemyArray_Type6(Enemy_List,screen);
        }
        else if(wave==7)
        {
           EnemyArray_Type7(Enemy_List,screen);
        }
        else
        {
            EnemyBoss(Enemy_List,screen);
        }
    }


}
