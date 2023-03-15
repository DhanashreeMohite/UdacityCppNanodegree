#ifndef RENDERER_H
#define RENDERER_H
// uses SDL library to render the game to the screen
#include <vector>
#include "SDL.h"
#include "ball.h"
#include "paddle.h"
#include "screen.h"

class Renderer {
 public:
 //creates SDL window and SDL renderer object that can draw the window
  Renderer(Screen &screen);
  ~Renderer();
//Draw the ball and paddle on the window using renderer
  void Render(Ball &ball,Paddle &paddle);
  void UpdateWindowTitle(int score, int fps);

 private:
  SDL_Window *sdl_window;
  SDL_Renderer *sdl_renderer;
};

#endif