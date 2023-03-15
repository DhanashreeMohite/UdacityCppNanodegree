#ifndef SCREEN_H
#define SCREEN_H
typedef struct Screen{
  //number of frames per second
  int kFramesPerSecond{60};
  int kMsPerFrame{1000 / kFramesPerSecond};
  //Screen width and height
  int screen_width{640};
  int screen_height{520};
  //game runs on grid.. hence grid width and height
  int grid_width{10};
  int grid_height{10};
}Screen;
#endif