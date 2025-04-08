#ifndef BIRB_H
#define BIRB_H

#include "assets.h"
#include "window.h"

class Bird {
    Texture birdTexture;
    SDL_Rect position;
    double velocity;
    double gravity;
    double jumpForce;
    bool isAlive;
public:
    Bird(SDL_Renderer* renderer, const char* imagePath, int x, int y);
    void jump();
    void update();
    void render();
    void reset(int x, int y);
    bool isDead() const {return !isAlive;}
    void kill() {isAlive = false;}
    SDL_Rect getRect() const {return position;}
    bool outOfBounds(int screenHeight) const;
};

#endif // BIRB_H
