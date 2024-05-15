#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

int main(int argc, char** argv) {
  SDL_Init(SDL_INIT_VIDEO);
  IMG_Init(IMG_INIT_PNG);
  TTF_Init();

  SDL_Window* Window{SDL_CreateWindow(
    "Hello Window", 0, 0, 800, 300, 0)
  };

  SDL_Event event;

  bool running = true;
  while (running) {
    SDL_PollEvent(&event);

    switch (event.type)
    {
        case SDL_QUIT:
            running = false;
            break;
    }
  }

  
  SDL_DestroyWindow(Window);

  SDL_Quit();

  return 0;
}