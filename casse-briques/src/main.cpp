#include "main.h"

int main(int argc, char *argv[])
{
    App* app = new App();

    app->set_running(true);

    while ( app->is_running() )
    {
        app->prepareScene(); //Update the scene ...

        app->listen_events(); //Handle events (user inputs)

        app->presentScene(); //Rendrer (redraw the scene ...)

        SDLUtils::delay(16);
    }
    
    app->quit(0);
}