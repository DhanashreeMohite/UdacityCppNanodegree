#ifndef SNAKE_H
#define SNAKE_H
// snake class contains the attribute to keep track of speed size and location of snake
#include <random>
#include "SDL.h"
#include "screen.h"
#include "paddle.h"

class Ball {
 public:
  Ball(Screen &screen);
  //size of ball
  int ballSize;
  //Draw ball on screen
  void renderBall(SDL_Renderer *sdl_renderer);
  // update ball speed
  void updateBall(Screen &screen, Paddle &paddle, bool &isUpdateScore);
  //get ball co-ordinates
  int getX(){return x;}
  int getY(){return y;}
 private:
  //ball co-ordinates
  float x;
  float y;
  //speed of ball
  float x_speed;
  float y_speed;
  //random start
  bool flip();
};

#endif