#include "LTexture.h"


 LTexture::LTexture()
{
	p_texture=NULL;
    Rect.x=0;
    Rect.y=0;
    Rect.w=0;
    Rect.h=0;
}
LTexture::~LTexture()
{
    free();
}
bool LTexture::LoadTexture(string path,SDL_Renderer* screen)
{
    free();
    SDL_Texture* new_texture=NULL;
    SDL_Surface* load_surface=IMG_Load(path.c_str());
    if(load_surface !=NULL)
    {

        SDL_SetColorKey( load_surface, SDL_TRUE, SDL_MapRGB( load_surface->format, 0,255,255 ) );
        new_texture=SDL_CreateTextureFromSurface(screen, load_surface);
        if(new_texture!=NULL)
        {
            Rect.w=load_surface->w;
            Rect.h=load_surface->h;
        }
        SDL_FreeSurface(load_surface);
    }
    width_frame=Rect.w;
    height_frame=Rect.h;
    p_texture=new_texture;
    return p_texture!=NULL;
}
void LTexture::setAlpha( Uint8 alpha )
{
	//Modulate texture alpha
    SDL_SetTextureAlphaMod( p_texture, alpha );
}
void LTexture::MoveBackGround(SDL_Renderer* screen,const SDL_Rect* clip /*- NULL*/)
{
    SDL_Rect renderquad1={Rect.x,Rect.y,Rect.w,Rect.h};
    SDL_RenderCopy(screen,p_texture,clip,&renderquad1);
    SDL_Rect renderquad2={Rect.x,Rect.y-SCREEN_HEIGHT,Rect.w,Rect.h};
    SDL_RenderCopy(screen,p_texture,clip,&renderquad2);
    Rect.y+=1;
    if(Rect.y>=SCREEN_HEIGHT)
    {
        Rect.y=0;
    }
}
void LTexture::Render(SDL_Renderer* screen,const SDL_Rect* clip /*- NULL*/)
{

    SDL_Rect renderquad1={Rect.x,Rect.y,Rect.w,Rect.h};
    SDL_RenderCopy(screen,p_texture,clip,&renderquad1);
}

void LTexture::flicking( Uint8 &alpha )
{
    if( alpha <= 255 && alpha>0 )
    {
        alpha-=15;

    }
    else if (alpha ==0)
    {
        alpha=255;
    }


}

void LTexture::free()
{
    if(p_texture!=NULL)
    {
        SDL_DestroyTexture(p_texture);
        p_texture=NULL;
        Rect.w=0;
        Rect.h=0;
    }
}

