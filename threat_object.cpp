#include "threat_object.h"

Threat::Threat()
{
    rect_.x = SCREEN_WIDTH;
    rect_.y = SCREEN_HEIGHT ;
    rect_.w = WIDTH_THREAT;
    rect_.h = HEIGHT_THREAT;

    x_val_ = 0;
    y_val_ = 0;
}
Threat::~Threat()
{

}
void Threat::HandleMove(const int& x_border, const int& y_border)
{
    rect_.x -= x_val_;
    if(rect_.x  < 0)
    {
        rect_.x = SCREEN_WIDTH;
    }
}



