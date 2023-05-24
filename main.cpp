#include "LTexture.h"
#include "Game_Utils.h"
#include "Menu.h"
#include "Player.h"
#include "Enemy.h"
#include "Enemy_Array.h"
#include "Collision.h"
#include "Text.h"



LTexture m_Background;
LTexture Heart[3];
LTexture MenuUI;
LTexture GameOverUI;
LTexture ChooseUI;
Player spaceship ;

TTF_Font* general_font=NULL;
TTF_Font* GameOver_font=NULL;

Mix_Chunk* MenuBGM=NULL;
Mix_Chunk* BGM=NULL;
Mix_Chunk* GameOverBGM=NULL;
Mix_Chunk* shot=NULL;
Mix_Chunk* explosion=NULL;

Text currentscore;
Text numberofcurrentscore;
Text Score;
Text Highscore;
Text Life;
Text Wave;
Text Wave_number;
Menu PlayButton;
Menu QuitButton;
Menu Choose_Flame;
Menu Choose_Flash;
Menu Choose_Gun;
Menu BackButton;
Menu PlayAgainButton;

;
bool init()
{
     bool success=true;
	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
        success=false;
	}
	else
	{
		//Set texture filtering to linear
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
		{
			printf( "Warning: Linear texture filtering not enabled!" );
            success=false;
		}

		//Create window
		m_Window = SDL_CreateWindow( "Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( m_Window == NULL )
		{
			printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
            success=false;
		}
		else
		{
			//Create vsynced renderer for window
			m_Renderer = SDL_CreateRenderer( m_Window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
			if( m_Renderer == NULL )
			{
				printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
                success=false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor( m_Renderer, 0xFF, 0xFF, 0xFF, 0xFF );

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if( !( IMG_Init( imgFlags ) & imgFlags ) )
				{
					printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
                    success=false;
				}
				//Initialize SDL_ttf
				if( TTF_Init() == -1 )
				{
					printf( "SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError() );
					success = false;
				}
				general_font=TTF_OpenFont("text.ttf",25);
				GameOver_font=TTF_OpenFont("text.ttf",55);
                if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,2,2048)<0)
                {
                    printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
                    success=false;
                }
                MenuBGM=Mix_LoadWAV("MenuBGM.wav");
                BGM=Mix_LoadWAV("BGM.wav");
                shot=Mix_LoadWAV("shot.wav");
                explosion=Mix_LoadWAV("explosion.wav");
                GameOverBGM=Mix_LoadWAV("GameOverBGM.wav");

			}
		}
	}

       return success;
}



void close()
{
    //Destroy window
	SDL_DestroyRenderer( m_Renderer );
	SDL_DestroyWindow( m_Window );
//	m_go.clean();

	m_Window = NULL;
	m_Renderer = NULL;

	m_Background.free();
    GameOverUI.free();

    Mix_FreeChunk(BGM);
    BGM=NULL;
    Mix_FreeChunk(shot);
    shot=NULL;
    Mix_FreeChunk(MenuBGM);
    MenuBGM=NULL;
    Mix_FreeChunk(GameOverBGM);
    GameOverBGM=NULL;
    Mix_FreeChunk(explosion);
    explosion=NULL;
    Mix_Quit();
    IMG_Quit();
    SDL_Quit();


}

int main(int argc, char* argv[])
{
    vector<Enemy*> Enemy_List;
    vector<Bullet*> Bullet_List;
     srand(time(0));
    int score=0;
    int wave=0;
    if(init()==false)
    {
        cout << "SDL init failed" << endl;
        return 0;
    }

    for(int i=0;i<3;i++)
    {
        Heart[i].LoadTexture("img//heart_icon.png",m_Renderer);
        Heart[i].SetRect(SCREEN_WIDTH-25-Heart[i].get_width_frame()*2-32*(i-1),Heart[i]. get_height_frame());
    }
    m_Background.LoadTexture( "img//background2.png" ,m_Renderer);
    MenuUI.LoadTexture("img//Menu.png",m_Renderer);
    GameOverUI.LoadTexture("img//GameOver.png",m_Renderer);
    spaceship.LoadImg("img//flame.png",m_Renderer);
    currentscore.SetColor(Text::RED_COLOR);
    numberofcurrentscore.SetColor(Text::WHITE_COLOR);
    Score.SetColor(Text::YELLOW_COLOR);
    Highscore.SetColor(Text::YELLOW_COLOR);
    Life.SetColor(Text::RED_COLOR);
    Wave.SetColor(Text::WHITE_COLOR);
    Wave_number.SetColor(Text::WHITE_COLOR);


    string str_currentscore="SCORE";
    string str_life="HEALTH";
    string str_wave="WAVE";


    currentscore.Set_Text(str_currentscore);
    currentscore.LoadFromRenderText(general_font,m_Renderer);

    Life.Set_Text(str_life);
    Life.LoadFromRenderText(general_font,m_Renderer);

    Wave.Set_Text(str_wave);
    Wave.LoadFromRenderText(general_font,m_Renderer);

    Mix_VolumeChunk(MenuBGM,MIX_MAX_VOLUME/2);
    Mix_VolumeChunk(BGM,MIX_MAX_VOLUME/3);
    Mix_VolumeChunk(shot,MIX_MAX_VOLUME/2);
    Mix_VolumeChunk(explosion,MIX_MAX_VOLUME/2);
    Mix_VolumeChunk(GameOverBGM,MIX_MAX_VOLUME/3);
    //Main loop flag
    bool InMenu=true;
    bool play=false;
    bool ChooseCharacter=false;
    //Event handler
    SDL_Event g_event;

    while(InMenu)
    {

        if(!Mix_Playing(1))
        {
            Mix_PlayChannel(1,MenuBGM,-1);
        }

            while(SDL_PollEvent(&g_event)!=0)
            {
                if(g_event.type==SDL_QUIT)
                {
                    InMenu=false;
                }
                PlayButton.HandlePlayButton(g_event,m_Renderer,play,InMenu);
                QuitButton.HandleQuitButton(g_event,m_Renderer,InMenu);
            }
            PlayButton.SetRect(SCREEN_WIDTH/2-PlayButton.get_width_frame()/2,SCREEN_HEIGHT/2);
            QuitButton.SetRect(SCREEN_WIDTH/2-QuitButton.get_width_frame()/2,SCREEN_HEIGHT/2+100);
            MenuUI.Render(m_Renderer);
            PlayButton.Render(m_Renderer);
            QuitButton.Render(m_Renderer);
            SDL_RenderPresent(m_Renderer);

    }

    spaceship.set_damage();
    SDL_WarpMouseInWindow(m_Window,SCREEN_WIDTH/2-32,SCREEN_HEIGHT-100);

    bool GameOver=false;

    while(play)
    {

        Mix_HaltChannel(1);
        if(!Mix_Playing(2))
        {
            Mix_PlayChannel(2,BGM,-1);
        }
        if(!GameOver)
        {
            Mix_HaltChannel(3);
            while(SDL_PollEvent(&g_event)!=0)
                {

                    if(g_event.type==SDL_QUIT)
                    {
                        play=false;
                    }

                    spaceship.HandleInputAction(g_event,m_Renderer);
                }

            //Clear screen
            SDL_SetRenderDrawColor( m_Renderer, 0xFF, 0xFF, 0xFF, 0xFF );
            SDL_RenderClear( m_Renderer );

            SDL_ShowCursor(SDL_DISABLE);

            m_Background.MoveBackGround(m_Renderer,NULL);
            GenerateEnemy(Enemy_List,m_Renderer,wave);
            spaceship.Show(m_Renderer,NULL);
            spaceship.SpawnBullet(m_Renderer);
            spaceship.HandleBullet(m_Renderer);

            Collision(Enemy_List,spaceship,Bullet_List,score,GameOver,explosion,m_Renderer);

            currentscore.RenderText(m_Renderer,10,10);
            Life.RenderText(m_Renderer,SCREEN_WIDTH-150,10);
            Wave.RenderText(m_Renderer,SCREEN_WIDTH/2-50,10);
            Wave_number.Set_Text(number_to_string_1(wave));
            Wave_number.LoadFromRenderText(general_font,m_Renderer);
            Wave_number.RenderText(m_Renderer,SCREEN_WIDTH/2,35);
            numberofcurrentscore.Set_Text(number_to_string(score));
            numberofcurrentscore.LoadFromRenderText(general_font,m_Renderer);
            numberofcurrentscore.RenderText(m_Renderer,10,35);
            for(int i=0;i<spaceship.get_life();i++)
            {
                    Heart[i].Render(m_Renderer);
            }

            SDL_RenderPresent(m_Renderer);
        }

        else
        {
            Mix_HaltChannel(2);
            if(!Mix_Playing(3))
            {
                Mix_PlayChannel(3,GameOverBGM,-1);
            }
            SDL_ShowCursor(SDL_ENABLE);
            GameOverUI.Render(m_Renderer);
            if(score>HighScore())
            {
                UpdateHighScore(score);
            }

            while(SDL_PollEvent(&g_event)!=0)
            {
                if(g_event.type==SDL_QUIT)
                {
                    play=false;
                }
                 QuitButton.HandleQuitButton(g_event,m_Renderer,play);
                 PlayAgainButton.HandlePlayAgainButton( g_event,m_Renderer,Enemy_List,spaceship,Bullet_List,wave,score,GameOver);
            }

            Score.Set_Text(number_to_string(score));
            Score.LoadFromRenderText(GameOver_font,m_Renderer);
            Score.RenderText(m_Renderer,300,375);
            Highscore.Set_Text(number_to_string(HighScore()));
            Highscore.LoadFromRenderText(GameOver_font,m_Renderer);
            Highscore.RenderText(m_Renderer,445,478);
            QuitButton.SetRect(SCREEN_WIDTH-QuitButton.get_width_frame()-50,SCREEN_HEIGHT-QuitButton.get_height_frame()-80);
            PlayAgainButton.SetRect(50,SCREEN_HEIGHT-PlayAgainButton.get_height_frame()-80);
            QuitButton.Render(m_Renderer);
            PlayAgainButton.Render(m_Renderer);

            SDL_RenderPresent(m_Renderer);
        }
   }
    //Free resources and close SDL
    Enemy_List.erase(Enemy_List.begin(),Enemy_List.begin()+Enemy_List.size());
    Bullet_List.erase(Bullet_List.begin(),Bullet_List.begin()+Bullet_List.size());
	close();

    return 0;
}












