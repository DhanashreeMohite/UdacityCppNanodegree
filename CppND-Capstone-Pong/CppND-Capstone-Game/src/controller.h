#ifndef CONTROLLER_H
#define CONTROLLER_H
// handles keyboard input using SDL library and paddles's direction based on input
#include "paddle.h"

class Controller {
 public:
  void HandleInput(bool &running, Paddle &paddle, Screen &screen) const;


 private:
  /*void ChangeDirection(Paddle &paddle, Snake::Direction input,
                       Snake::Direction opposite) const;*/
  
};

#endif