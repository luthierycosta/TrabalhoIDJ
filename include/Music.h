#ifndef _music_h_
#define _music_h_

#include "SDL.h"
#include "SDL_image.h"
#include "SDL_mixer.h"
#include "SDL_ttf.h"
#include <string>

class Music {
private:
    Mix_Music* music;

public:
    Music();
    Music(std::string file);
    ~Music();

    void Open(std::string file);
    void Play(int times);
    void Stop(int msToStop);
    bool IsOpen();
};

#endif /*_music_h_*/