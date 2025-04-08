#ifndef PIPE_H
#define PIPE_H

#include "assets.h"
#include "window.h"

class PipeSystem {
    struct PipePair {
        SDL_Rect top;
        SDL_Rect bottom;
        bool passed;
    };
    Texture* pipeTexture;
    vector<PipePair> pipes;
    int gapSize;
    int scrollSpeed;
public:
    PipeSystem(Texture* texture, const int gap = 150, int speed = 3);
    void generate(int count, int windowWidth);
    void update();
    void render(SDL_Renderer* renderer);
    void reset();
    bool checkCollision(const SDL_Rect& rect) const;
    bool checkPass(const SDL_Rect& rect, int index);
    int getPipeCount() const { return pipes.size(); }
};

#endif // PIPE_H
