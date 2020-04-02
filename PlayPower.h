#ifndef PLAY_POWER_H_
#define PLAY_POWER_H_

#include "BaseObject.h"
#include <vector>

class PlayerPower :public BaseObject
{
public:
    PlayerPower();
    ~PlayerPower();
    void SetNumber(const int& num) {number_ = num;};
    void AddPos(const int& xpos;);
    void Render(SDL_Surface* des);
private:

};
#endif // PLAY_POWER_H_
