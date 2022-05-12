#include "../include/State.h"
#include "SDL.h"

State::State() {
    this->bg = Sprite("./assets/img/ocean.jpg");
    this->music = Music("./assets/audio/stageState.ogg");
    this->music.Play(-1);
    this->quitRequested = false;
}

void State::LoadAssets() {

}

void State::Update(float dt) {
    bool quit = SDL_QuitRequested();
    if (quit)
        this->quitRequested = true;
}

void State::Render() {
    this->bg.Render(0,0);
}

bool State::QuitRequested() {
    return this->quitRequested;
}