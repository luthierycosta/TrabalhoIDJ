#include "../include/Game.h"
#include "SDL_image.h"
#include "SDL_mixer.h"
#include "SDL_ttf.h"

int main(int argc, char** argv) {

    Game game = Game::GetInstance();
    printf("Jogo instanciado\n");
    game.Run();
    printf("Acabou execução\n");

    return 0;
}