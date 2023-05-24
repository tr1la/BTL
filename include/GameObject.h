#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include "LTexture.h"

class GameObject
{
    public:
        GameObject();

        void LoadTexture(string path, SDL_Renderer* screen);
        void Show(SDL_Renderer* des);
        void set_positions(const int x,const int y)
    {
        m_PosX=x;
        m_PosY=y;
    }
        //void update();
        void clean();
    protected:
        int m_PosX;
        int m_PosY;
        int m_width;
		int m_height;
		LTexture m_GameObject;
        string m_textureID;
};

#endif // GAMEOBJECT_H
