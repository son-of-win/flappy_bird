#include "Bird.h"


Bird::Bird()
{
    rect_.x = 0;
    rect_.y = 0;
    rect_.w = WIDTH_BIRD;
    rect_.h = HEIGHT_BIRD;
    x_val_ = 0;
    y_val_ = 0;
}

Bird::~Bird()
{
    ;
}

void Bird::HandleInputAction(SDL_Event events)
{
    if(events.type == SDL_KEYDOWN)
    {
        if(events.key.keysym.sym == SDLK_SPACE)
        {
            y_val_ -= 10;

        }

    }
    else if(events.type == SDL_KEYUP)
    {
        if(events.key.keysym.sym == SDLK_SPACE)
        {
            y_val_ += 10;
        }
    }
    else
    {
        y_val_ += 1;
    }
}

void Bird::HandleMove()
{
    rect_.y += y_val_;
    /*if(rect_.y < 0)
        y_val_ +=1;*/
}
