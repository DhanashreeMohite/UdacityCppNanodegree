#include "ball.h"
#include <cmath>
#include <iostream>

Ball::Ball(Screen &screen){
  srand((unsigned int)time(NULL));
  ballSize = (screen.grid_width > screen.grid_height)? screen.grid_height : screen.grid_width;
  x = (int)screen.screen_width/2 + (int)ballSize/2;
  y = (int)screen.screen_height/2 + (int)ballSize/2;
  float  speed = 0.5f;//(rand() % 2) + 1;
  x_speed = speed*(flip() ? 1 : -1);
  y_speed = speed*(flip() ? 1 : -1);
}

bool Ball::flip(){
  return ((rand() % 2) == 1) ? true : false;
}

// Render ball: set ball color to white
void Ball::renderBall(SDL_Renderer *sdl_renderer){
  SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0xFF, 0xFF, 0xFF);
  //std::cout<<"renderBall called \n";
  SDL_Rect ballRect = {
    .x = (int)x,
    .y = (int)y,
    .w = ballSize,
    .h = ballSize,
  };
  SDL_RenderFillRect(sdl_renderer, &ballRect);
}

void Ball::updateBall(Screen &screen, Paddle &paddle, bool &isUpdateScore){
  x += x_speed;
  y += y_speed;
  if((fabs(x-screen.screen_width) < ballSize) || (x < ballSize)){
    //std::cout<<fabs(x-screen_width) << "next Co-ordinates: ("<< (x+x_speed)<<","<<(y+y_speed) <<")\n";
    if(x < ballSize){
      isUpdateScore = true;
    }
    x_speed = -(x_speed);
  }
    
  if((fabs(y-screen.screen_height) < ballSize) || (y < ballSize)){
    //std::cout<<fabs(y-screen_height) << "next Co-ordinates: ("<< (x+x_speed)<<","<<(y+y_speed) <<")\n";
    y_speed = -(y_speed);
  }
  //std::cout<<"updateBall called \n";
}