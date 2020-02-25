#include <iostream>
#include <memory>
#include "SDL.h"

struct SDLWindowDestroyer
{
    void operator()(SDL_Window *window)
    {
        SDL_DestroyWindow(window);
    }
};

struct SDLRendererDestroyer
{
    void operator()(SDL_Renderer *renderer)
    {
        SDL_DestroyRenderer(renderer);
    }
};

int main(int argc, char **argv)
{
    static constexpr int WIDTH =  600;
    static constexpr int HEIGHT = 400;

    SDL_Init(SDL_INIT_EVERYTHING);

    std::unique_ptr<SDL_Window, SDLWindowDestroyer> window(nullptr);
    std::unique_ptr<SDL_Renderer, SDLRendererDestroyer> renderer(nullptr);

    window.reset(SDL_CreateWindow("SDL Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN));
    renderer.reset(SDL_CreateRenderer(window.get(), -1, 0));

    SDL_SetRenderDrawColor(renderer.get(), 0, 255, 0, 255);
    SDL_RenderClear(renderer.get());
    SDL_RenderPresent(renderer.get());
    SDL_Delay(10000);

    return 0;
}
