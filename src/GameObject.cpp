#include "GameObject.h"

LTexture m_GameObject;

GameObject::GameObject() {


}

 void GameObject::LoadTexture(string path, SDL_Renderer* screen)
{

    m_GameObject.LoadTexture( path, screen);

}


void GameObject::Show(SDL_Renderer* screen )
 {
    SDL_Rect RenderQuad={m_PosX,m_PosY,m_width,m_height};

    SDL_RenderCopy(screen,p_texture,current_clip,&RenderQuad);

}


void GameObject::clean()
{
    m_GameObject.free();
}
