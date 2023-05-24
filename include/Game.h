#ifndef GAME_H
#define GAME_H

class Game
{
public:
    Game();

    // simply set the running variable to true
    void init() ;
    void loadmedia();
    void draw();
    void update();
    void handleEvents();
    void close ();
    // a function to access the private running variable
    bool running()
        {
            return m_Running;
        }
    private:


    bool m_Running;


};

#endif // GAME_H
