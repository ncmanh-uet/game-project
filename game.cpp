#include "game.h"
#include <random>

FlappyGame::FlappyGame(Window& window)
    : gameWindow(window),
      player(window.getRen(), BIRD_IMAGE, 100, window.getHei()/2),
      pipe_texture(window.getRen()),
      pipes(&pipe_texture),
      jumpSound(SOUND_JUMP),
      crashSound(SOUND_LOST),
      score(0),
      bac(window.getRen(),BACKGROUND_LEVEL)
{
    pipe_texture.loadImage(PIPE_IMAGE);
    pipes.generate(4, window.getWid());
}

void FlappyGame::handleInput()
{
    SDL_Event e;
    while (SDL_PollEvent(&e)) {
        if (e.type == SDL_QUIT) {
            gstate = 4;
        }
        if ((e.type == SDL_KEYDOWN || e.type == SDL_MOUSEBUTTONDOWN) && !player.isDead()) {
            player.jump();
            jumpSound.play();
        }
    }
}

void FlappyGame::update()
{
    bac.scroll(3);
    if (!player.isDead()) {
        player.update();
        pipes.update();
        checkCollisions();
        updateScore();
    }
    else {
        gstate = 3;
    }
}

void FlappyGame::render()
{
    gameWindow.release();
    bac.render();
    pipes.render(gameWindow.getRen());
    player.render();
    gameWindow.update();
}

void FlappyGame::checkCollisions()
{
    if (pipes.checkCollision(player.getRect()) || player.outOfBounds(gameWindow.getHei())) {
        player.kill();
        crashSound.play();
    }
}

void FlappyGame::updateScore()
{
    for (int i = 0; i < pipes.getPipeCount(); i++) {
        if (pipes.checkPass(player.getRect(), i)) {
            score++;
            break;
        }
    }
}

