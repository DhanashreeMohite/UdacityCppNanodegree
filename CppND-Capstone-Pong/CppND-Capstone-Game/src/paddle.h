#ifndef PADDLE_H
#define PADDLE_H
// snake class contains the attribute to keep track of speed size and location of snake
#include "SDL.h"
#include "screen.h"

class Paddle {
 public:
  Paddle(Screen &screen);
  
  //Draw paddle on screen
  void renderPaddle(SDL_Renderer *sdl_renderer);
  //paddle Attributes
  //paddle co-ordinates
  int x;
  int y;
  int paddleWidth;
  int paddleHeight;
  
};

#endif