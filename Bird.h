#ifndef BIRD_H_
#define BIRD_H_
#include "common_function.h"
#include "BaseObject.h"

#define WIDTH_BIRD 80
#define HEIGHT_BIRD 80

class Bird : public BaseObject
{
public:
    Bird();
    ~Bird();

    void HandleMove();
    void HandleInputAction(SDL_Event events);
private:
    int x_val_;
    int y_val_;
};
#endif // BIRD_H_
