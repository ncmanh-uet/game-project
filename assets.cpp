#include "assets.h"
using namespace std;
wordFont::wordFont()
    :f{nullptr}{}
wordFont::wordFont(const string& path, int size)
    :f{nullptr}
{
    f=TTF_OpenFont(path.c_str(), size);
}
void wordFont::loadFont(const string& path, int size)
{
    f=TTF_OpenFont(path.c_str(), size);
}
TTF_Font* wordFont::getFont()
{
    return f;
}
Texture::Texture(SDL_Renderer* re)
    :width{0},height{0},ren{re},t{nullptr}{}
void Texture::loadImage(const string& path)
{
    t=IMG_LoadTexture(ren, path.c_str());
    SDL_QueryTexture(t, NULL, NULL, &width , &height);
}
void Texture::loadText(const string& text,wordFont& font, SDL_Color color)
{
    SDL_Surface* textSurface = TTF_RenderText_Solid(font.getFont(), text.c_str(), color);
    t=SDL_CreateTextureFromSurface(ren, textSurface);
    SDL_QueryTexture(t,NULL,NULL,&width,&height);
    SDL_FreeSurface(textSurface);
}
void Texture::render(int x, int y)
{
    SDL_Rect renderQuad = {x, y, width, height };
    SDL_RenderCopyEx(ren, t, nullptr, &renderQuad, 0.0, nullptr, SDL_FLIP_NONE);
}
int Texture::getWidth()
{
    return width;
}
int Texture::getHeight()
{
    return height;
}
Music::Music()
    :music{nullptr}{}
Music::Music(const string& path)
    :music{nullptr}
{
    music=Mix_LoadMUS(path.c_str());
}
void Music::play()
{
    Mix_PlayMusic(music,-1);
}
Sound::Sound()
    :chunk{nullptr}{}
Sound::Sound(const string& path)
    :chunk{nullptr}
{
    chunk=Mix_LoadWAV(path.c_str());
}
void Sound::play()
{
    Mix_PlayChannel(-1,chunk,0);
}

