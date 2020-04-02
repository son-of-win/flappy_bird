#include "Common_function.h"

SDL_Surface* CommonFunc::LoadImage(std::string file_path)
{
	SDL_Surface* image = NULL;
	SDL_Surface* optimize_image = NULL;
	image = IMG_Load(file_path.c_str());
	if (image != NULL)
	{
		optimize_image = SDL_DisplayFormat(image);
		SDL_FreeSurface(image);

		//xoa phong nen cho anh truyen vao
        if (optimize_image != NULL)
        {
            UINT32 color_key = SDL_MapRGB(optimize_image->format, 0, 0xFF, 0xFF);// trong đó (0,255,255)=(0,0xFF,0xFF) là mã màu background cần xóa
            SDL_SetColorKey(optimize_image, SDL_SRCCOLORKEY, color_key);
        }
	}
	return optimize_image;
}

void CommonFunc::ApplySurface(SDL_Surface* src, SDL_Surface* des, int x, int y)
{
	SDL_Rect offset;
	offset.x = x;
	offset.y = y;

	SDL_BlitSurface(src, NULL,des, &offset);
}

void CommonFunc::cleanup()
{
	SDL_FreeSurface(g_screen);
	SDL_FreeSurface(g_background);
}


