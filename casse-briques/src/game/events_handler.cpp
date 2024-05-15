#include "events_handler.h"

EventsHandler::EventsHandler()
{

}

bool EventsHandler::handle_events(Player* player)
{
    SDL_Event event;
    const Uint8 *key_states = SDL_GetKeyboardState(NULL);

    bool play = true;
    while (play && SDL_PollEvent(&event))
    {
        switch (event.type)
        {
            case SDL_QUIT:
                play = false;
                break;

            /* ========= handle the mouse motion events =========*/
            case SDL_MOUSEMOTION:
                int x, y;
                SDL_GetMouseState(&x, &y);
                player->set_middle_position(x);
                
                break;

            default:
                break;
        }
    }

    /* ========= handle the escape keyboard event =========*/
    if (key_states[SDL_SCANCODE_ESCAPE])
    {
        std::cout << "The escape key is pressed .... "<<std::endl;
        play = false;
    }

    /* ========= handle the left keyboard event =========*/
    if (key_states[SDL_SCANCODE_LEFT])
    {
        //std::cout << "The left arrow key is pressed .... "<<std::endl;
        player->set_x( player->get_x() - player->get_move_speed() );
    }

    /* ========= handle the right keyboard event =========*/
    if (key_states[SDL_SCANCODE_RIGHT])
    {
        //std::cout << "The right arrow key is pressed .... "<<std::endl;
        player->set_x( player->get_x() + player->get_move_speed() );
    }

    /* ========= handle the mouse click events =========*/
    /*int x, y;
    if ( SDL_GetMouseState(&x,&y) )
    {
        player->set_middle_position(x);
    }*/


    return play;
}