#include "app.h"

App::App()
{
    bool is_sdk_ok = this->initSDL();
    if (!is_sdk_ok)
    {
        this->quit(1);
    }

    this->font = TTF_OpenFont("./res/fonts/Pacifico.ttf", FONT_SIZE);
    if (!this->font)
    {
        std::cout<<"Error loading font"<<std::endl;
        this->quit(1);
    }

    this->color.r = this->color.g = this->color.b = 255;

    this->events_handler = new EventsHandler();

    this->player = new Player( this->get_renderer() );
    this->ball = new Ball( this->get_renderer() );

    this->player->set_height(12);
    this->player->set_width(80); //WINDOW_WIDTH / 4
    this->player->set_y( WINDOW_HEIGHT - this->player->get_height() - 32 );

    this->ball->set_width(SIZE);
    this->ball->set_height(SIZE);

    for (int i=0; i<COLS*ROWS; i++){
        Brick brick = Brick( this->renderer );

        int x = (((i % COLS)+1)*SPACING) + ((i % COLS) * brick.get_width()) - (SPACING / 2);
        int y = brick.get_height()*3 + (((i / COLS)+1)*SPACING) + ((i / COLS) * brick.get_height()) - (SPACING / 2);

        brick.set_position(x, y);

        bricks.push_back( brick );
    }

    this->reset();
}
        
SDL_Renderer* App::get_renderer()
{
    return this->renderer;
}

void App::set_renderer(SDL_Renderer *renderer)
{
    this->renderer = renderer;
}

SDL_Window* App::get_window()
{
    return this->window;
}

void App::set_window(SDL_Window *window)
{
    this->window = window;
}


bool App::initSDL()
{
    int rendererFlags, windowFlags;

    //rendererFlags = SDL_RENDERER_ACCELERATED;
    rendererFlags = 0; // without acclerated rendreder

    windowFlags = 0;

    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        std::cerr << "Couldn't initialize SDL: "<< SDL_GetError() <<"\n";
        return false;
    }

    this->window = SDL_CreateWindow(WINDOW_TITLE, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, windowFlags);

    if (!this->window)
    {
        std::cerr << "Failed to open " << WINDOW_WIDTH << " x " << WINDOW_HEIGHT << "window: "<< SDL_GetError() <<"\n";
        return false;
    }

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");

    this->renderer = SDL_CreateRenderer(this->window, -1, rendererFlags);

    if (!this->renderer)
    {
        std::cerr << "Failed to create renderer: " << SDL_GetError() << "\n";
        return false;
    }

    IMG_Init(IMG_INIT_PNG);
    TTF_Init();

    return true;
}

//Update ....
void App::prepareScene()
{
    SDL_SetRenderDrawColor( this->get_renderer(), 96, 128, 255, 255 );
    SDL_RenderClear( this->get_renderer() );

    SDL_SetRenderDrawColor( this->get_renderer(), 255, 255, 255, 255 );

    this->player->draw();
    this->ball->draw();

    SDLUtils::SDL_write_str(this->get_renderer(), "Lives : " + std::to_string( this->player->get_lives_count() ), WINDOW_WIDTH - 25/*(WINDOW_WIDTH+FONT_SIZE)/2*/ , 35, this->font, this->color, this->lives_box);

    SDLUtils::SDL_write_str(this->get_renderer(), "Socre : " + std::to_string( this->player->get_score() ), 125 , 35, this->font, this->color, this->lives_box);

    for (int i=0; i<bricks.size(); i++)
    {
        Brick brick = this->bricks.at(i);
        if ( brick.exists() )
        {
            brick.draw();
        }
    }
    

    if ( this->player->is_dead() )
    {
        reset();
    }

    //********************************************************
    //Detect collisions between ball and player's paddle
    if (SDL_HasIntersection(this->ball->get_box(), this->player->get_box())) 
    {
        double rel = (player->get_x() + (player->get_width()/2)) - (ball->get_x() + (SIZE/2));
        double norm = rel / (player->get_width() / 2);
        double bounce = norm * (5 * PI / 12);

        this->ball->set_vel_y( -this->ball->get_speed() * cos(bounce) );
        this->ball->set_vel_x( -this->ball->get_speed() * sin(bounce) );
    }

    if (ball->get_y() <= 0) 
    {
        this->ball->set_vel_y( -this->ball->get_vel_y() );
    }

    if (ball->get_y() >= WINDOW_HEIGHT) 
    {
        this->ball->set_vel_x( 0 ); 
        this->ball->set_vel_y( - this->ball->get_vel_y() );

        this->ball->set_position( (WINDOW_WIDTH - SIZE) / 2, this->player->get_y() - this->player->get_height() * 8  );

        this->player->decrease_lives();
    }

    if (ball->get_x() <= 0 || ball->get_x()+SIZE >= WINDOW_WIDTH)
    {
        this->ball->set_vel_x( - this->ball->get_vel_x() );
    }

    this->ball->translate( ball->get_vel_x(), ball->get_vel_y() );

    if (player->get_x() < 0)
    {
        player->set_x( 0 );
    }

    if (player->get_x() + player->get_width() > WINDOW_WIDTH)
    {
        player->set_x( WINDOW_WIDTH - player->get_width() );
    }


    //********************************************************
    //Detect collisions between ball and bricks
    bool reset = true;
    for (int i=0; i<bricks.size(); i++)
    {
        Brick brick = bricks.at(i);

        if (SDL_HasIntersection(this->ball->get_box(), brick.get_box()) && brick.exists()) 
        {
            brick.set_resistence( brick.get_resistence() -1 );
            
            bricks.at(i) = brick;

            player->set_score( player->get_score()+100 );

            //std::cout<<"OK is Touched : "<< brick.get_resistence() << brick.exists() << std::endl;

            if (ball->get_x() >= brick.get_box()->x)
            {
                this->ball->set_vel_x( -this->ball->get_vel_x() );
                //ball->translate_x( -20 );
            }
            
            if (ball->get_x() <= brick.get_box()->x)
            {
                this->ball->set_vel_x( -this->ball->get_vel_x() );
                //ball->translate_x( 20 );
            }
            
            if (ball->get_y() >= brick.get_box()->y)
            {
                this->ball->set_vel_y( -this->ball->get_vel_y() );
                //ball->translate_y( -20 );
            }
            
            if (ball->get_y() <= brick.get_box()->y)
            {
                this->ball->set_vel_y( -this->ball->get_vel_y() );
                //ball->translate_y( +20 );
            }
        }

        if (brick.exists())
        {
            reset = false;
        }
    }

    if (reset)
    {
        this->reset();
    }
}

//Render .....
void App::presentScene()
{
    SDL_RenderPresent(this->get_renderer());
}

//Inputs .....
void App::listen_events(void)
{
    this->running = this->events_handler->handle_events( this->player );
}


void App::reset()
{
    for (int i=0; i<bricks.size(); i++)
    {
        this->bricks.at(i).set_resistence( i % 3 + 1 );
    }

    this->player->set_lives_count(3);
    this->player->set_score(0);
    
    this->player->set_x( (WINDOW_WIDTH - this->player->get_width()) / 2 );

    this->ball->set_position( (WINDOW_WIDTH - SIZE) / 2, this->player->get_y() - this->player->get_height() * 8  );

    this->ball->set_vel_y( -this->ball->get_speed() / 2 );
    this->ball->set_vel_x( 0 );
}

/*
void App::set_bricks(int i)
{
    brick.x = (((i % COLS)+1)*SPACING) + ((i % COLS) * brick.w) - (SPACING / 2);
    //brick.y = brick.h*3 + (((i % ROWS)+1)*SPACING) + ((i % ROWS) * brick.h) - (SPACING / 2);
    brick.y = brick.h*3 + (((i / COLS)+1)*SPACING) + ((i / COLS) * brick.h) - (SPACING / 2);
}
*/

void App::quit(int exit_code)
{
    SDL_DestroyRenderer(this->get_renderer());
    SDL_DestroyWindow(this->get_window());

    SDL_Quit();

    exit( exit_code );
}