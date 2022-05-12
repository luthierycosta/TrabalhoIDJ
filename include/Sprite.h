#ifndef _sprite_h_
#define _sprite_h_

#include "SDL.h"
#include <string>

class Sprite {
private:
    SDL_Texture* texture;
    int width;
    int height;
    SDL_Rect clipRect;
    
public:
    Sprite();
    Sprite(std::string file);
    ~Sprite();
    
    void Open(std::string file);
    void SetClip(int x, int y, int w, int h);
    void Render(int x, int y);
    int GetWidth();
    int GetHeight();
    bool IsOpen();

};

#endif /*_sprite_h_*/