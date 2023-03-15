#include "paddle.h"
#include <cmath>
#include <iostream>

// initialize paddle on lower edge in middle
Paddle::Paddle(Screen &screen){
  paddleWidth = 50;
  paddleHeight = 10;
  x = (int)screen.screen_width/2 + (int)paddleWidth/2;
  y = (int)screen.screen_height - (int)paddleHeight;
}


// Render Paddle: set paddle color to white
void Paddle::renderPaddle(SDL_Renderer *sdl_renderer){
  SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0xFF, 0xFF, 0xFF);
  //std::cout<<"renderBall called \n";
  SDL_Rect paddleRect = {
    .x = x,
    .y = y,
    .w = paddleWidth,
    .h = paddleHeight,
  };
  SDL_RenderFillRect(sdl_renderer, &paddleRect);
}
