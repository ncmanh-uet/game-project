#ifndef ASSETS_H
#define ASSETS_H
#define FONT_PATH "./Assets/Purisa-BoldOblique.ttf"
#define MUSIC_THEME_PATH "./Assets/background_sound.mp3"
#define SOUND_JUMP "./Assets/gojo_jump.mp3"
#define SOUND_LOST "./Assets/lost.mp3"
#define PIPE_IMAGE "./Assets/pipe1.png"
#define BIRD_IMAGE "./Assets/birb.png"

#include "window.h"
class wordFont{
    TTF_Font* f;
public:
    wordFont();
    wordFont(const string& path, int size);
    void loadFont(const string& path, int size);
    TTF_Font* getFont();
};
class Texture{
    SDL_Texture* t;
    SDL_Renderer* ren;
    int width,height;
public:
    Texture(SDL_Renderer* re);
    void loadImage(const string& path);
    void loadText(const string& text, wordFont& font,SDL_Color color);
    void render(int x, int y);
    int getWidth();
    int getHeight();

};
class Music{        // phát nhạc dài, lặp vô hạn
    Mix_Music* music;
public:
    Music();
    Music(const string& path);
    void play();
};
class Sound{        //phát nhạc ngắn, hiệu ứng âm thanh
    Mix_Chunk* chunk;
public:
    Sound();
    Sound(const string& path);
    void play();
};
#endif // ASSETS_H
