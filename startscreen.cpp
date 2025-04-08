#include "startscreen.h"
Background::Background(SDL_Renderer* ren,const string& path)
    : t{ren}, scrollingSpeed{0}
{
    t.loadImage(path);
}

void Background::render()
{
    t.render(scrollingSpeed, 0);
    t.render(scrollingSpeed - t.getWidth(), 0);
}

void Background::scroll(int speed)
{
    scrollingSpeed -= speed;
    if( scrollingSpeed < 0 ) { scrollingSpeed = t.getWidth(); }
}
StartScreen::StartScreen( Window& win)
    :win(win),bac{win.getRen(), BACKGROUND_INTRO},title{win.getRen()},subtitle1{win.getRen()},subtitle2{win.getRen()}
{
    wordFont bigFont, smallFont;
    bigFont.loadFont(FONT_PATH, 48);
    smallFont.loadFont(FONT_PATH, 12);
    title.loadText(WINDOW_TITLE, bigFont, SDL_Color{0xFF,0,0,0xFF});
    subtitle1.loadText("Are you ready???", smallFont, SDL_Color{0xFF,0,0,0xFF});
    subtitle2.loadText("Press to fight!...",smallFont, SDL_Color{0xFF,0,0,0xFF});
}

void StartScreen::render()
{
    bac.scroll(5);
    win.release();
    bac.render();
    title.render((win.getWid() - title.getWidth()) / 2,(win.getHei() - title.getHeight()) / 2);
    subtitle1.render((win.getWid() - subtitle1.getWidth()) / 2,(win.getHei() + title.getHeight() - subtitle1.getHeight()) / 2);
    subtitle2.render((win.getWid() - subtitle2.getWidth()) / 2,(win.getHei() + title.getHeight() + subtitle1.getHeight() + 20 - subtitle2.getHeight()) / 2);

    win.update();
}
