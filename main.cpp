#include "window.h"
#include "startscreen.h"
#include "game.h"
#include "Gamestates.h"
#include "assets.h"
int main(int argc, char* argv[])
{
    Window window(640, 480, WINDOW_TITLE);
    window.setIcon(WINDOW_ICON);
    Music theme(MUSIC_THEME_PATH);
    theme.play();
    gstate = 1;
    while(gstate != 4)
    {
        if(gstate == 1)
        {
            StartScreen start(window);
            SDL_Event e;

            while (true)
            {
                start.render();
                if (SDL_PollEvent(&e))
                {
                    if (e.type == SDL_QUIT)
                    {
                        gstate = 4;
                        break;
                    }
                    if (e.type == SDL_KEYDOWN || e.type == SDL_MOUSEBUTTONDOWN)
                    {
                        gstate = 2;
                        break;
                    }
                }
            }
        }
        if(gstate == 2)
        {
            FlappyGame game(window);
            while (gstate == 2)
            {
                game.handleInput();
                game.update();
                game.render();
                SDL_Delay(16);
            }
            if (gstate == 3)
            {
                int score = game.getScore();
                Texture bg(window.getRen()), text(window.getRen());
                bg.loadImage(BACKGROUND_GAMEOVER);
                wordFont font;
                font.loadFont(FONT_PATH, 30);
                text.loadText("Score: " + to_string(score), font, {255, 0, 0, 255});
                window.release();
                bg.render(0, 0);
                text.render((window.getWid() - text.getWidth())/2, (window.getHei() - text.getHeight())/2);
                window.update();
                gstate = 1;
                SDL_Delay(2000);
            }
        }
    }
    return 0;
}

