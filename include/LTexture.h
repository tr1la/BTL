#ifndef LTEXTURE_H
#define LTEXTURE_H

#include "Game_Utils.h"

class LTexture
{
	public:
		//Initializes variables
		LTexture();

		//Deallocates memory (giai phong bo nho)
		~LTexture();

		void SetRect(const int &x, const int &y)
    {
        Rect.x=x;
        Rect.y=y;
    }
    SDL_Rect GetRect()
    {
        return Rect;
    }
    SDL_Texture* GetTexture()
    {
        return p_texture;
    }
    bool LoadTexture(string path, SDL_Renderer* screen);
    void setAlpha( Uint8 alpha );
    void MoveBackGround(SDL_Renderer* screen,const SDL_Rect* clip=NULL);
    void Render(SDL_Renderer* screen,const SDL_Rect* clip=NULL);
    void flicking( Uint8 &alpha );
    void free();
    //frame
    int get_width_frame() const {return width_frame;}
    int get_height_frame() const {return height_frame;}
    protected:
    SDL_Texture* p_texture;
    SDL_Rect Rect;
    int width_frame;
    int height_frame;
};

#endif // LTEXTURE_H
