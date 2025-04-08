#include "pipe.h"

PipeSystem::PipeSystem(Texture* texture,const int gap, int speed)
    : pipeTexture(texture), gapSize(gap), scrollSpeed(speed) {}

void PipeSystem::generate(int count, int windowWidth)
{
    pipes.clear();
    for (int i = 0; i < count; i++) {
        int height = 80 + rand() % 150;
        pipes.push_back({
            {windowWidth + i * 300, -height, pipeTexture->getWidth(), pipeTexture->getHeight()},
            {windowWidth + i * 300, -height + pipeTexture->getHeight() + gapSize, pipeTexture->getWidth(), pipeTexture->getHeight()},
            false
        });
    }
}

void PipeSystem::update()
{
    for (auto& pipe : pipes) {
        pipe.top.x -= scrollSpeed;
        pipe.bottom.x -= scrollSpeed;
    }

    if (pipes.front().top.x + pipeTexture->getWidth() < 0) {
        pipes.erase(pipes.begin());
        int height = 80 + rand() % 150;
        pipes.push_back({
            {pipes.back().top.x + 300, -height, pipeTexture->getWidth(), pipeTexture->getHeight()},
            {pipes.back().bottom.x + 300, -height + pipeTexture->getHeight() + gapSize, pipeTexture->getWidth(), pipeTexture->getHeight()},
            false
        });
    }
}

void PipeSystem::render(SDL_Renderer* renderer)
{
    for (const auto& pipe : pipes) {
        pipeTexture->render(pipe.top.x, pipe.top.y);
        pipeTexture->render(pipe.bottom.x, pipe.bottom.y);
    }
}

bool PipeSystem::checkCollision(const SDL_Rect& rect) const
{
    for (const auto& pipe : pipes) {
        if (SDL_HasIntersection(&rect, &pipe.top) ||
            SDL_HasIntersection(&rect, &pipe.bottom)) {
            return true;
        }
    }
    return false;
}

bool PipeSystem::checkPass(const SDL_Rect& rect, int index)
{
    if (index >= 0 && index < pipes.size() && !pipes[index].passed) {
        if (rect.x > pipes[index].top.x + pipeTexture->getWidth()) {
            pipes[index].passed = true;
            return true;
        }
    }
    return false;
}

void PipeSystem::reset()
{
    for (auto& pipe : pipes) {
        pipe.passed = false;
    }
}
