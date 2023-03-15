#include "controller.h"
#include <iostream>
#include "SDL.h"

void Controller::HandleInput(bool &running, Paddle &paddle, Screen &screen) const {
  SDL_Event e;
  while (SDL_PollEvent(&e)) {
    if (e.type == SDL_QUIT) {
      running = false;
    } else if (e.type == SDL_KEYDOWN) {
      switch (e.key.keysym.sym) {
        case SDLK_LEFT:
          //std::cout<<paddle.x<<"\n";
          if (paddle.x >= (paddle.paddleWidth/2)){
            paddle.x -= screen.grid_width;
          }
          break;

        case SDLK_RIGHT:
          //std::cout<<screen.screen_width <<" "<<paddle.x<<"\n";
          if (paddle.x <= (screen.screen_width-(paddle.paddleWidth/2))){
            paddle.x += screen.grid_width;
          }
          break;
      }
    }
  }
}
