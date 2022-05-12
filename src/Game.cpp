#include "../include/Game.h"
#include "SDL_image.h"
#include "SDL_mixer.h"
#include <string>
#include <iostream>

Game* Game::instance;

Game::Game(std::string title, int width, int height) {
    if (Game::instance != nullptr) {
        printf("Game instance already found");
        exit(0);
    }

    Game::instance = this;
 
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER) != 0)  {
        printf("SDL initialization error: %s\n", SDL_GetError());
        exit(0);
    }
    if (IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF) == 0) {
        printf("SDL Image initialization error");
        exit(0);
    }
    if (Mix_Init(MIX_INIT_FLAC | MIX_INIT_MP3 | MIX_INIT_OGG) == 0) {
        printf("SDL Mix init initialization error");
        exit(0);
    }
    if (Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) != 0) {
        printf("SDL Open audio initialization error");
        exit(0);
    };
    Mix_AllocateChannels(32);

    // crian
    this->window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);
    if (this->window == nullptr) {
        printf("Error creating window");
        exit(0);
    }

    this->renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (this->renderer == nullptr) {
        printf("Error creating renderer");
        exit(0);
    }

    this->state = new State();
}

Game::~Game() {
    delete this->state;
    SDL_DestroyRenderer(this->renderer);
    SDL_DestroyWindow(this->window);
    Mix_CloseAudio();
    Mix_Quit();
    IMG_Quit();
    SDL_Quit();
}

Game& Game::GetInstance() {
    if (Game::instance == nullptr)
        new Game("Luthiery Costa Cavalcante - 170040631", 1024, 600);

    return *Game::instance;
}

State& Game::GetState() {
    return *(this->state);
}

SDL_Renderer* Game::GetRenderer() {
    return this->renderer;
}

void Game::Run() {
    while (not this->state->QuitRequested()) {
        this->state->Update(0.0);
        this->state->Render();
        SDL_RenderPresent(this->renderer);
        SDL_Delay(33);
    }
}