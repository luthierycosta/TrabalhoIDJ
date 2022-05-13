#include "../include/Game.h"

int main(int argc, char** argv) {

    Game game = Game::GetInstance();
    printf("Jogo instanciado\n");
    game.Run();
    printf("Acabou execução\n");

    return 0;
}