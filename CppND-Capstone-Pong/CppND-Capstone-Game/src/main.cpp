#include <iostream>
#include "controller.h"
#include "game.h"
#include "screen.h"
#include "renderer.h"


int main() {
  Screen screen;
  //Create renderer, controller and game objects
  Renderer renderer(screen);
  Controller controller;
  Game game(screen);
  //call Game::Run method to start the game loop
  game.Run(controller, renderer, screen);
  // show the result
  std::cout << "Game has terminated successfully!\n";
  std::cout << "Score: " << game.GetScore() << "\n";
  return 0;
}