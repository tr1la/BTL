#ifndef TEXT_H
#define TEXT_H

#include "Game_Utils.h"
class Text
{
    public:
    Text();
    ~Text();
    enum ColorType
    {
        WHITE_COLOR=0,
        RED_COLOR=1,
        YELLOW_COLOR=2,
    };

    bool LoadFromRenderText(TTF_Font* font,SDL_Renderer* screen);
    void Free();
    void SetColor(Uint8 red,Uint8 green, Uint8 blue);
    void SetColor(const int& type);

    void RenderText(SDL_Renderer*screen,int x_pos_,int y_pos_,SDL_Rect* clip=NULL, double angle=0.0,SDL_Point* center=NULL,SDL_RendererFlip flip=SDL_FLIP_NONE);
    int get_width_() const {return width_;}
    int get_height_() const {return height_;}
    void Set_Text(const string& text) {str_val_=text;}
    string GetText() const {return str_val_;}


    private:
    string str_val_;
    SDL_Color text_color_;
    SDL_Texture* texture_;
    int width_;
    int height_;


};

#endif // TEXT_H
