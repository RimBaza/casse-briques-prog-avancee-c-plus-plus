#ifndef __APP_H__
#define __APP_H__

#include <iostream>

#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>

#include "../utils/defs.h"
#include "../utils/sdl_utils.h"

#include "events_handler.h"

#include "player.h"
#include "ball.h"
#include "brick.h"

class App 
{
    private:
        SDL_Renderer *renderer;
        SDL_Window *window;

        EventsHandler* events_handler;

        TTF_Font* font;
        SDL_Color color;

        bool running;

        Player* player;
        Ball* ball;

        SDL_Rect lives_box, brick;

        std::vector<Brick> bricks;

    public:
        App();
        
        bool initSDL();

        SDL_Renderer* get_renderer();
        void set_renderer(SDL_Renderer *renderer);

        SDL_Window* get_window();
        void set_window(SDL_Window *window);

        void prepareScene();
        void presentScene();

        void listen_events(void);

        void reset();

        void delay(int time);

        void quit(int exit_code);

        //=====================================================
        //======= Some inlines methods ========================
        //=====================================================
        inline bool is_running() 
        {
            return this->running;
        }

        inline void set_running(bool running) 
        {
            this->running = running;
        }
};


#endif