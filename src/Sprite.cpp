#include "../include/Sprite.h"
#include "../include/Game.h"
#include "SDL_image.h"
#include <string>

Sprite::Sprite() {
    this->texture = nullptr;
}

Sprite::Sprite(std::string file) {
    this->texture = nullptr;
    Open(file);
}

Sprite::~Sprite() {
    if (IsOpen())
        SDL_DestroyTexture(this->texture);
}

void Sprite::Open(std::string file) {
    if (IsOpen())
        SDL_DestroyTexture(this->texture);
    
    SDL_Renderer* renderer = Game::GetInstance().GetRenderer();
    this->texture = IMG_LoadTexture(renderer, file.c_str());
    if (this->texture == nullptr) {
        printf("Error loading texture: %s\n", SDL_GetError());
    }

    int query = SDL_QueryTexture(this->texture, nullptr, nullptr, &(this->width), &(this->height));
    if (query != 0) {
        printf("Error loading texture dimensions: %s\n", SDL_GetError());
        exit(0);
    }

    SetClip(0, 0, this->width, this->height);
}

void Sprite::SetClip(int x, int y, int w, int h) {
    this->clipRect.x = x;
    this->clipRect.y = y;
    this->clipRect.w = w;
    this->clipRect.h = h;
}

void Sprite::Render(int x, int y) {
    
    SDL_Renderer* renderer = Game::GetInstance().GetRenderer();
    SDL_Rect dst;
    dst.x = x;
    dst.y = y;
    dst.w = this->clipRect.w;
    dst.h = this->clipRect.h;
    SDL_RenderCopy(renderer, this->texture, &(this->clipRect), &dst);
}

int Sprite::GetWidth() {
    return this->width;
}

int Sprite::GetHeight() {
    return this->height;
}

bool Sprite::IsOpen() {
    return this->texture != nullptr;
}