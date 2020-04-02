#include "Common_function.h"
#include "Bird.h"
#include "threat_object.h"

bool Init()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
    {
        return FALSE;
    }
    g_screen = SDL_SetVideoMode( SCREEN_WIDTH,SCREEN_HEIGHT,SCREEN_BFF, SDL_SWSURFACE);
    if (g_screen == NULL)
    {
        return false;
    }
    return true;
}
#undef main
int main(int arc, char *argv[])
{
    bool is_quit = false ;
    if (Init() == false)
    {
        return 0;
    }
    g_background = CommonFunc::LoadImage("background.png"); //load anh nen
    if (g_background == NULL)
        return 0;
    //CommonFunc::ApplySurface(g_background, g_screen, 0, 0);
    /*g_object = CommonFunc::LoadImage("plane.png");
    if(g_object == NULL)
        return 0;
    CommonFunc::ApplySurface(g_object, g_screen,300,200);*/

    // khởi tạo đối tượng chính
    Bird bird_object;
    bird_object.SetRect(300,200);
    bool rec = bird_object.LoadImg("bird.png");
    if(rec == NULL)
        return 0;
    bird_object.Show(g_screen);

    // khởi tạo đói tượng threat

    Threat* p_threats2 = new Threat[NUMS_THREAT];
   // Threat* p_threats = new Threat[NUMS_THREAT];

    for(int t = 0;t < NUMS_THREAT;t++)
    {
        Threat* p_threat2 = (p_threats2 + t);
        bool ret2 = p_threat2->LoadImg("threat_one.png");
        if(ret2 == NULL )
            return 0;
        int rand_y2 = rand()%50;
        p_threat2->SetRect(SCREEN_WIDTH + t*250,rand_y2);
        p_threat2->set_x_val(3);
    }
   /* for(int i = 0;i < NUMS_THREAT;i++)
    {
        Threat* p_threat = p_threats + i;
        bool ret = p_threat->LoadImg("threat_second.png");
        if(ret == NULL )
            return 0;
        int rand_y = rand()%50;
        p_threat->SetRect(SCREEN_WIDTH + i*250,SCREEN_HEIGHT - rand_y - HEIGHT_THREAT);
        p_threat->set_x_val(3);
    }*/

    while (!is_quit)
    {
        while (SDL_PollEvent(&g_event))
        {
            if (g_event.type == SDL_QUIT)
            {
                is_quit = true;
                break;
            }
            bird_object.HandleInputAction(g_event);

        }
        CommonFunc::ApplySurface(g_background, g_screen, 0, 0);
        bird_object.Show(g_screen);
        bird_object.HandleMove();

        //khởi chạy threat
       /* for(int i = 0; i < NUMS_THREAT;i++)
        {
            Threat* p_threat = p_threats + i;
            {
                p_threat->Show(g_screen);
                p_threat->HandleMove(SCREEN_WIDTH,SCREEN_HEIGHT);
            }
        }**/
        for(int tt = 0; tt < NUMS_THREAT;tt++)
        {
            Threat* p_threat2 = p_threats2 + tt;
            if(p_threat2 != NULL)
            {
                 p_threats2->Show(g_screen);
                 p_threats2->HandleMove(SCREEN_WIDTH,SCREEN_HEIGHT);
            }
        }


        if (SDL_Flip(g_screen) == -1)
            return 0;
    }

    CommonFunc::cleanup();
    SDL_Quit();
    return 0;
}
