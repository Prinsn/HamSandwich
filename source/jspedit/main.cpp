#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <string>
#include "globals.h"
#include "editor.h"

extern const size_t embed_vera_size;
extern const unsigned char embed_vera[];
extern const size_t embed_fontawesome_size;
extern const unsigned char embed_fontawesome[];
#if !defined(_WIN32) && !defined(__clang__)
extern const size_t embed_game_icon_size;
extern const unsigned char embed_game_icon[];
#endif

using namespace std;

SDL_Window *window;
SDL_Renderer *renderer;
TTF_Font *gFont, *gIconFont;

int DISPLAY_WIDTH = 1024;
int DISPLAY_HEIGHT = 768;

int main(int argc, char** argv) {
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS);
    IMG_Init(IMG_INIT_PNG);
    if (TTF_Init()) printf("TTF_Init: %s\n", TTF_GetError());

    gFont = TTF_OpenFontRW(SDL_RWFromConstMem(embed_vera, embed_vera_size), true, 14);
    if (!gFont) printf("vera.ttf: %s\n", TTF_GetError());
    gIconFont = TTF_OpenFontRW(SDL_RWFromConstMem(embed_fontawesome, embed_fontawesome_size), true, 14);
    if (!gIconFont) printf("fontawesome.ttf: %s\n", TTF_GetError());

    window = SDL_CreateWindow("JspEdit 3", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, DISPLAY_WIDTH, DISPLAY_HEIGHT, SDL_WINDOW_RESIZABLE);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
    SDL_GetWindowSize(window, &DISPLAY_WIDTH, &DISPLAY_HEIGHT);

#if !defined(_WIN32) && !defined(__clang__)
    SDL_Surface *surface = IMG_Load_RW(SDL_RWFromConstMem(embed_game_icon, embed_game_icon_size), true);
    SDL_SetWindowIcon(window, surface);
    SDL_FreeSurface(surface);
#endif

    if (argc > 1) {
        editor::loadOnStartup(argv[1]);
    }

    editor::main();

    TTF_CloseFont(gIconFont);
    TTF_CloseFont(gFont);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    return 0;
}

void DrawText(SDL_Renderer *renderer, TTF_Font *font, int x, int y, Align align, SDL_Color color, const char* text) {
    SDL_Surface *surface = TTF_RenderUTF8_Blended(font, text, color);
    if (!surface) {
        return;
    }
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);

    SDL_Rect rect = { x, y, surface->w, surface->h };
    if (align == ALIGN_RIGHT)
        rect.x -= surface->w;
    else if (align == ALIGN_CENTER)
        rect.x -= surface->w / 2;

    SDL_RenderCopy(renderer, texture, nullptr, &rect);
    SDL_DestroyTexture(texture);
    SDL_FreeSurface(surface);
}
