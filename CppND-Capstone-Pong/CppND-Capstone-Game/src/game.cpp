#include "game.h"
#include <iostream>
#include "SDL.h"

Game::Game(Screen &screen):ball(screen), paddle(screen){
}
//game loop
void Game::Run(Controller const &controller, Renderer &renderer, Screen &screen) {
  Uint32 title_timestamp = SDL_GetTicks();
  Uint32 frame_start;
  Uint32 frame_end;
  Uint32 frame_duration;
  int frame_count = 0;
  bool running = true;

  while (running) {
    frame_start = SDL_GetTicks();

    // Input, Update, Render - the main game loop.
    controller.HandleInput(running,paddle,screen);
    Update(ball,screen, paddle, running);
    renderer.Render(ball,paddle);

    frame_end = SDL_GetTicks();

    // Keep track of how long each loop through the input/update/render cycle
    // takes.
    frame_count++;
    frame_duration = frame_end - frame_start;

    // After every second, update the window title.
    if (frame_end - title_timestamp >= 1000) {
      renderer.UpdateWindowTitle(score, frame_count);
      frame_count = 0;
      title_timestamp = frame_end;
    }

    // If the time for this frame is too small (i.e. frame_duration is
    // smaller than the target ms_per_frame), delay the loop to
    // achieve the correct frame rate.
    if (frame_duration < screen.kMsPerFrame) {
      SDL_Delay(screen.kMsPerFrame - frame_duration);
    }
  }
}


void Game::Update(Ball &ball, Screen &screen, Paddle &paddle, bool &isGameRunning) {
  //std::cout<<"Game update"<<"\n";
  ball.updateBall(screen,paddle,isUpdateScore);
  int ballLowerSurface = (ball.getY()+(ball.ballSize/2));
  int paddleSurface = (screen.screen_height-paddle.paddleHeight);
  if((ballLowerSurface == paddleSurface) && isUpdateScore){
    std::cout<<"Ball:"<<ballLowerSurface <<" Paddle:"<<paddleSurface<<"\n";
    int paddleOffset = paddle.paddleWidth/2;
    if((ball.getX()>(paddle.x+paddleOffset)) || (ball.getX()<(paddle.x-paddleOffset))){
      std::cout<<ball.getX()<<","<<ball.getY() <<" "<<(paddle.x+paddleOffset) << " "<<(paddle.x-paddleOffset)<<"\n";
      isGameRunning = 0;
    }else{
      score++;
    }
    isUpdateScore = false;
  }
}

int Game::GetScore() const { return score; }
