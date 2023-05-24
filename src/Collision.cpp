#include "Collision.h"

Uint8 a = 255;
long long CurrentTime;
long long LastTime;
void Collision(vector<Enemy*> &Enemy_List,Player &spaceship,vector<Bullet*> &Bullet_List, int &current_score,bool &GameOver,Mix_Chunk* shot_sound,SDL_Renderer* screen)
{

    CurrentTime=SDL_GetTicks();
    for(int i=0;i<Enemy_List.size();i++)
    {
        Enemy *p_enemy=Enemy_List.at(i);
        if(p_enemy!=NULL)
        {
            p_enemy->MoveThreat();
            p_enemy->Show(screen,NULL);

            if(p_enemy->canspawnbullet()==true)
            {
            p_enemy->MakeBullet(Bullet_List,screen,spaceship);
            }
            SDL_Rect spaceshipRect=spaceship.GetHitBox();
            if(p_enemy!=NULL)
            {
                SDL_Rect ThreatRect=p_enemy->GetRect();
                bool Threat_to_Spaceship=CheckCollision(spaceshipRect,ThreatRect);
                if(Threat_to_Spaceship)
                {
                    spaceship.got_hit();
                    Mix_PlayChannel(-1,shot_sound,0);
                    spaceship.SetRect(SCREEN_WIDTH/2,SCREEN_HEIGHT-100);

                     p_enemy->got_hit(200);
                    if(p_enemy->get_heslth()<=0)
                    {
                        current_score+=(p_enemy->get_score());
                        Mix_PlayChannel(-1,shot_sound,0);
                        Enemy_List.erase(Enemy_List.begin()+i);
                        if(p_enemy!=NULL)
                        {
                            delete p_enemy;
                            p_enemy=NULL;
                        }
                    }
                    if(spaceship.get_life()==0)
                    {
                        GameOver=true;
                    }
                }
            }
        }
    }

    for(int i=0;i<Bullet_List.size();i++)
    {
        Bullet*p_bullet=Bullet_List.at(i);
        if(p_bullet!=NULL)
        {
            SDL_Rect BulletRect=p_bullet->GetRect();
            SDL_Rect Main_Rect=spaceship.GetHitBox();

        bool ThreatBullet_to_spaceship=CheckCollision(BulletRect,Main_Rect);
        if(ThreatBullet_to_spaceship && CurrentTime>=LastTime+2000)
        {
               spaceship.got_hit();
                spaceship.set_flick(true);
               // Mix_PlayChannel(-1,shot_sound,0);
                Bullet_List.erase(Bullet_List.begin()+i);
                if(spaceship.get_life()==0)
                {
                    a=255;
                    spaceship.set_flick(false);
                    GameOver=true;
                }
                LastTime=CurrentTime;
        }
        if (spaceship.get_flick()==true)
        {
            if (CurrentTime>=LastTime+2000)
            {
                spaceship.set_flick(false);
                a=255;
            }
            else
            {
                spaceship.flicking(a);
                spaceship.setAlpha(a);
            }
        }

        if (spaceship.get_flick()==false)
            {
                spaceship.setAlpha(255);
            }

        if(p_bullet->get_is_move()==true)
            {
                p_bullet->HandleEnemyMove(SCREEN_WIDTH+500, SCREEN_HEIGHT+500);
                p_bullet->Render(screen,NULL);
            }
            else
            {
                Bullet_List.erase(Bullet_List.begin()+i);
                delete p_bullet;
                p_bullet=NULL;
            }
        }
    }
    vector<Bullet*> spaceship_bullet_arr=spaceship.get_bullet_list();
    for(int i=0;i<spaceship_bullet_arr.size();i++)
    {
        Bullet*p_bullet=spaceship_bullet_arr.at(i);
        if(p_bullet!=NULL)
        {
            for(int j=0;j<Enemy_List.size();j++)
            {
                Enemy* p_enemy=Enemy_List.at(j);
                if(p_enemy!=NULL)
                {
                    SDL_Rect ThreatRect;
                    ThreatRect=p_enemy->GetRect();
                    SDL_Rect BulletRect=p_bullet->GetRect();
                    bool SpaceshipBullet_to_Threat=CheckCollision(ThreatRect,BulletRect);
                    if(SpaceshipBullet_to_Threat)
                    {
                        p_enemy->got_hit(spaceship.get_damage());
                        spaceship.RemoveBullet(i);
                        if(p_enemy->get_heslth()<=0)
                        {
                            current_score+=(p_enemy->get_score());
                            Mix_PlayChannel(-1,shot_sound,0);
                            Enemy_List.erase(Enemy_List.begin()+j);
                            if(p_enemy!=NULL)
                            {
                                delete p_enemy;
                                p_enemy=NULL;
                            }
                        }
                    }
                }
            }
        }
    }

}
