#include <iostream>
#include <SDL3/SDL.h>

int main(int argc, char *argv[])
{
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;

    // Check for SDL init
    if (!SDL_Init(SDL_INIT_VIDEO))
    {
        SDL_Log("Couldn't initialize SDL: %s", SDL_GetError());
        return 1;
    }

    // Check for video/renderer init
    if (!SDL_CreateWindowAndRenderer("Game_test", 600, 600, 0, &window, &renderer))
    {
        SDL_Log("Couldn't create window/renderer: %s", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    bool isRunning = true;
    SDL_Event event;

    while (isRunning)
    {
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_EVENT_QUIT:
                isRunning = false;
                break;

            case SDL_EVENT_KEY_DOWN:
            {
                SDL_KeyboardEvent &keyEvent = event.key;
                if (keyEvent.scancode == SDL_SCANCODE_ESCAPE)
                {
                    isRunning = false;
                }
                break;
            }

            default:
                break;
            }
        }

        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer, 16, 18, 24, 1);

        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
