#ifndef BASE_OBJECT_H_
#define BASE_OBJECT_H_

#include "common_function.h"
class BaseObject
{
public:
    BaseObject();
    ~BaseObject();
    void Show(SDL_Surface* des);
    bool LoadImg(const char* file_name);

    void SetRect(int x, int y) {rect_.x = x; rect_.y = y;};
    SDL_Rect GetRect() const {return rect_;};
    SDL_Surface* GetObject() {return p_object_;};
protected:
    SDL_Rect rect_;  // khởi tạo vị trí bạn đầu , chiều dài , chiều rộng cho đối tượng
    SDL_Surface* p_object_;

};
#endif // BASE_OBJECT_H_
