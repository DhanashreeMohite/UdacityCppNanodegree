#include "renderer.h"
#include <iostream>
#include <string>

Renderer::Renderer(Screen &screen){
  // Initialize SDL
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    std::cerr << "SDL could not initialize.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }

  // Create Window
  sdl_window = SDL_CreateWindow("Pong Game", SDL_WINDOWPOS_CENTERED,
                                SDL_WINDOWPOS_CENTERED, screen.screen_width,
                                screen.screen_height, SDL_WINDOW_SHOWN);

  if (nullptr == sdl_window) {
    std::cerr << "Window could not be created.\n";
    std::cerr << " SDL_Error: " << SDL_GetError() << "\n";
  }

  // Create renderer
  sdl_renderer = SDL_CreateRenderer(sdl_window, -1, SDL_RENDERER_ACCELERATED);
  if (nullptr == sdl_renderer) {
    std::cerr << "Renderer could not be created.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }else{
    SDL_SetRenderDrawColor(sdl_renderer, 0x1E, 0x1E, 0x1E, 0xFF);
    SDL_RenderClear(sdl_renderer);

    // Render ball: set ball color to white
    
    SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_Rect ballRect = {
      .x = (int)screen.screen_width/2 + (int)screen.grid_width/2,
      .y = (int)screen.screen_height/2 + (int)screen.grid_height/2,
      .w = (int)screen.grid_width,
      .h = (int)screen.grid_height,
    };
  }
  //std::cout<<"Renderer Created"<<"\n";
}

Renderer::~Renderer() {
  SDL_DestroyWindow(sdl_window);
  SDL_Quit();
  //std::cout<<"Renderer Destroyed"<<"\n";
}


void Renderer::Render(Ball &ball,Paddle &paddle) {
  //SDL_Rect block;
  //block.w = screen.screen_width / screen.grid_width;
  //block.h = screen.screen_height / screen.grid_height;
  // Set color as a black to screen and Clear screen
  SDL_SetRenderDrawColor(sdl_renderer, 0x1E, 0x1E, 0x1E, 0xFF);
  SDL_RenderClear(sdl_renderer);

  // Render ball: set ball color to white
  ball.renderBall(sdl_renderer);

  // Render paddle: set paddle color to white
  paddle.renderPaddle(sdl_renderer);
  
  // Update Screen
  SDL_RenderPresent(sdl_renderer);
  //std::cout<<"Screen Updated"<<"\n";
}

void Renderer::UpdateWindowTitle(int score, int fps) {
  std::string title{"Score: " + std::to_string(score) + " FPS: " + std::to_string(fps)};
  SDL_SetWindowTitle(sdl_window, title.c_str());
}
