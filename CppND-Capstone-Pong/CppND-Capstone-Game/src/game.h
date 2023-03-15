#ifndef GAME_H
#define GAME_H
// stores the state of the game
//#include <random>
#include "SDL.h"
#include "controller.h"
#include "ball.h"
#include "renderer.h"
#include "screen.h"

class Game {
 public:
  Game(Screen &screen);
  
  void Run(Controller const &controller, Renderer &renderer, Screen &screen);
  Ball ball;
  Paddle paddle;
  //get the total score
  int GetScore() const;
  
 private:
  bool isUpdateScore{true};
  int score{0};
  void Update(Ball &ball, Screen &screen, Paddle &paddle, bool &isGameRunning);
};

#endif