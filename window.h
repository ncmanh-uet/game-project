#ifndef WINDOW_H
#define WINDOW_H
#define WINDOW_ICON "./Assets/birb.png"
#define WINDOW_TITLE "Flappy JJK"
#include <bits/stdc++.h>
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
using namespace std;
class Window{
    int width,height;
    SDL_Window* wind;
    SDL_Renderer* ren;
public:
    Window(int w, int h, const string& title);
    ~Window();
    void setIcon(const string& path);
    void release();
    void update();
    int getWid();
    int getHei();
    SDL_Window* getWin();
    SDL_Renderer* getRen();
};
#endif // WINDOW_H
