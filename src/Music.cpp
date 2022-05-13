#include "../include/Music.h"

Music::Music() {
    this->music = nullptr;
}

Music::Music(std::string file) {
    this->music = nullptr;
    Open(file);
}

Music::~Music() {
    Stop(1500);
    Mix_FreeMusic(this->music);
}

void Music::Open(std::string file) {
    this->music = Mix_LoadMUS(file.c_str());
    if (!IsOpen())
        printf("Error loading music: %s\n", SDL_GetError());
}

void Music::Play(int times) {
    if (Mix_PlayMusic(this->music, times) != 0)
        printf("Error playing music: %s\n", SDL_GetError());
}

void Music::Stop(int msToStop) {
    Mix_FadeOutMusic(msToStop);
}

bool Music::IsOpen() {
    return this->music != nullptr;
}