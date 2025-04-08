
#include "birb.h"

Bird::Bird(SDL_Renderer* renderer, const char* imagePath, int x, int y)
    : velocity(0), gravity(0.5), jumpForce(-8.0), isAlive(true), birdTexture(renderer)
{
    birdTexture.loadImage(imagePath);
    position = {x, y, birdTexture.getWidth(), birdTexture.getHeight()};
}

void Bird::jump()
{
    if (isAlive) {
        velocity = jumpForce;
    }
}

void Bird::update()
{
    if (isAlive) {
        velocity += gravity;
        position.y += velocity;
    }
}

void Bird::render()
{
    birdTexture.render(position.x, position.y);
}

void Bird::reset(int x, int y)
{
    position.x = x;
    position.y = y;
    velocity = 0;
    isAlive = true;
}

bool Bird::outOfBounds(int screenHeight) const
{
    return position.y < 0 || position.y + position.h > screenHeight;
}
