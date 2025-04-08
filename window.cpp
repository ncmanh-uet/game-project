#include "window.h"
#include <algorithm>
#include <iostream>
Window::Window(int w, int h, const string& title)
    :width{w}, height(h)
{
    IMG_INIT_PNG;
    TTF_Init();
    Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,2,2048);
    wind=SDL_CreateWindow(title.c_str(),SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
    ren=SDL_CreateRenderer(wind,-1,SDL_RENDERER_ACCELERATED |SDL_RENDERER_PRESENTVSYNC);
}
Window::~Window()
{
    SDL_DestroyWindow(wind);
    SDL_DestroyRenderer(ren);
}
void Window::setIcon(const string& path)
{
    SDL_Surface* icon=IMG_Load(path.c_str());
    SDL_SetWindowIcon(wind,icon);
    SDL_FreeSurface(icon);
}
void Window::release()
{
    SDL_SetRenderDrawColor( ren, 0xFF, 0xFF, 0xFF, 0xFF ); // đặt lại màu vẽ trắng
    SDL_RenderClear(ren);
}
void Window::update()
{
    SDL_RenderPresent(ren);
}
int Window::getHei()
{
    return height;
}
int Window::getWid()
{
    return width;
}
SDL_Window* Window::getWin()
{
    return wind;
}
SDL_Renderer* Window::getRen()
{
    return ren;
}

