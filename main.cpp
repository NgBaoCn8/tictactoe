#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "graphics.h"
#include "defs.h"
#include "logic.h"

using namespace std;

void waitUntilKeyPressed()
{
    SDL_Event e;
    while (true) {
        if ( SDL_PollEvent(&e) != 0 &&
             (e.type == SDL_KEYDOWN || e.type == SDL_QUIT) )
            return;
        SDL_Delay(100);
    }
}

void processClick(int x, int y, Tictactoe& game) {
    int clickedCol = (x -120- BOARD_X) / CELL_SIZE;
    int clickedRow = (y -40- BOARD_Y) / CELL_SIZE;
    game.move(clickedRow, clickedCol);
}

int main(int argc, char *argv[])
{
    Graphics graphics;
    graphics.init();
    SDL_Texture*background=graphics.loadTexture("img//background.png");
    SDL_Texture*win=graphics.loadTexture("img//win.png");
    Tictactoe game;
    game.init();


    int x, y;
    SDL_Event event;
    bool quit = false;
    while (! quit) {
            if(!game.gameover(game))
            {
                graphics.renderTexture(win,0,150);
                graphics.presentScene();
                waitUntilKeyPressed();
                quit=true;
            }
            graphics.renderTexture(background,0,0);
            graphics.render(game);
        SDL_PollEvent(&event);
        switch (event.type) {
            case SDL_QUIT:
                 quit = true;
                 break;
            case SDL_MOUSEBUTTONDOWN:
                 SDL_GetMouseState(&x, &y);
                 processClick(x, y, game);
                 graphics.render(game);
                 break;
        }
        graphics.presentScene();
        SDL_Delay(100);
    }

    graphics.quit();
    return 0;
}
