#ifndef _state_h_
#define _state_h_

#include "SDL.h"
#include "SDL_image.h"
#include "SDL_mixer.h"
#include "SDL_ttf.h"
#include "Sprite.h"
#include "Music.h"

class State {
private:
    Sprite bg;
    Music music;
    bool quitRequested;

public:
    State();

    void LoadAssets();
    void Update(float dt);
    void Render();
    bool QuitRequested();
};

#endif /*_state_h_*/

