#ifndef _game_h_
#define _game_h_

#include "SDL.h"
#include "SDL_image.h"
#include "SDL_mixer.h"
#include "SDL_ttf.h"
#include "State.h"
#include <string>

class Game {
private:    
    static Game* instance;
    SDL_Window* window;
    SDL_Renderer* renderer;
    State* state;
    
public:
    Game(std::string title, int width, int height);
    ~Game();

    static Game& GetInstance();
    SDL_Renderer* GetRenderer();
    State& GetState();
    void Run();
};

#endif /*_game_h_*/

