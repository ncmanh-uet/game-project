#ifndef STARTSCREEN_H
#define STARTSCREEN_H
#define BACKGROUND_INTRO "./Assets/gojo.jpg"
#define BACKGROUND_LEVEL "./Assets/gojo.jpg"
#define BACKGROUND_GAMEOVER "./Assets/gojo.jpg"

#include "window.h"
#include "assets.h"
class Background{
    Texture t;
    int scrollingSpeed;
public:
    Background(SDL_Renderer* ren, const string& path);
    void render();
    void scroll(int speed);
};
class StartScreen{
    Background bac;
    Window& win;
    Texture title;
    Texture subtitle1;
    Texture subtitle2;
public:
    StartScreen(Window& win);
    void render();
};
#endif // STARTSCREEN_H
