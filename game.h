#ifndef GAME_H
#define GAME_H

#include "birb.h"
#include "pipe.h"
#include "window.h"
#include "Gamestates.h"
#include "assets.h"
#include "startscreen.h"

class FlappyGame {
    Window& gameWindow;
    Bird player;
    PipeSystem pipes;
    Texture pipe_texture;
    Sound jumpSound;
    Sound crashSound;
    Background bac;
    int score;
    void checkCollisions();
    void updateScore();
public:
    FlappyGame(Window& window);
    void handleInput();
    void update();
    void render();
    int getScore() const {return score;}
};

#endif // GAME_H

