#include <iostream>
#include <string>
#include "Constants.h" //gResPath-contains the path to your resources.
// INKLUDERA ALLTID CONSTRAINTS NÄR DU JOBBAR I SDL!!!!!
//  Alla dessa SDL inkluderingsfiler används inte i detta testprogram.
//  Bifogas endast för test av SDL installation!

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>
#define FPS 60
using namespace std;

#define SCREEN_WIDTH 600
#define SCREEN_HEIGHT 400

int main(int argc, char *argv[])
{
    SDL_Init(SDL_INIT_EVERYTHING);
    TTF_Init();

    TTF_Font *font = TTF_OpenFont("./src/Kalnia/Kalnia.ttf", 36);
    SDL_Color color = {0, 0, 0};

    Mix_OpenAudio(22050, AUDIO_S16SYS, 2, 4096);
    // Högsta frekvens, format (S16SYS = 16bitar signed), kanaler, bufferstorlek
//Om ljudet laggar, sänk bufferten.
    Mix_Chunk *sound = Mix_LoadWAV("./src/sounds/bgMusic.wav");

    SDL_Window *win = SDL_CreateWindow("SDL test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
    // Namn, position på skärm X respektive Y, Storlek X respektive Y, Flaggor
    SDL_Renderer *ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
    // Fönster, index, flagga

    SDL_Surface *bgSurf = SDL_LoadBMP("./src/IMG_1694.bmp");
    // C-sträng, om vi skriver ett C++-program måste vi anropa sträng.c_str();

    SDL_Texture *bgTx = SDL_CreateTextureFromSurface(ren, bgSurf);
    // Renderare, Surface

    SDL_FreeSurface(bgSurf);

    SDL_Surface *gubbSurf = SDL_LoadBMP("./src/gubbe.bmp");

    SDL_Rect gubbRect = {0, 0, gubbSurf->w, gubbSurf->h};
    // position på skärmen X resp Y, storlek bredd resp höjd

    Uint32 white = SDL_MapRGB(gubbSurf->format, 255, 255, 255);
    SDL_SetColorKey(gubbSurf, true, white);

    SDL_Texture *gubbTx = SDL_CreateTextureFromSurface(ren, gubbSurf);
    SDL_FreeSurface(gubbSurf);
    // Om SetColorKey görs måste det ske innan Texturen framställs

    SDL_Surface *donkSurf = IMG_Load("./src/donkey.png");
    SDL_Texture *donkTx = SDL_CreateTextureFromSurface(ren, donkSurf);

    SDL_Rect donkRect = {200, 200, donkSurf->w, donkSurf->h};
    // Används för att ange vart den här ska ritas ut
    SDL_FreeSurface(donkSurf);
    /*SDL_Surface *textSurface = TTF_RenderText_Solid(font, text, color);
    SDL_Texture *textTexture = SDL_CreateTextureFromSurface(ren, textSurface);*/
    int varv = 0;
    bool goOn = true;
    bool drag = false;
    const int tickInterval = 1000 / FPS;

    Mix_PlayChannel(-1, sound, -1);

    while (goOn)
    {

        Uint32 nextTick = SDL_GetTicks() + tickInterval;
        // GetTicks - antal ticks sen biblioteket startade
        SDL_Event event;
        // Tar fram händelser i kön, returnerar 0 om händelse, -1 om ingen händelse.
        while (SDL_PollEvent(&event))
        {
            //&event fyller funktioner med instruktioner om vad som inträffat
            switch (event.type)
            {
            case SDL_QUIT:
                goOn = false;

                break;

            case SDL_KEYDOWN:
                switch (event.key.keysym.sym)
                {
                case SDLK_RIGHT:
                    gubbRect.x++;
                    break;

                case SDLK_LEFT:
                    gubbRect.x--;
                    break;

                case SDLK_UP:
                    gubbRect.y--;
                    break;

                case SDLK_DOWN:
                    gubbRect.y++;
                    break;
                }
                break;

            case SDL_MOUSEBUTTONDOWN:
            {
                SDL_Point p = {event.button.x, event.button.y};
                if (SDL_PointInRect(&p, &gubbRect))
                {
                    drag = true;
                }
            }

            case SDL_MOUSEBUTTONUP:
                drag = false;
                break;

            case SDL_MOUSEMOTION:
                if (drag)
                {
                    gubbRect.x += event.motion.xrel;
                    gubbRect.y += event.motion.yrel;
                }

                break;

                goOn = true;

            default:
                break;

            } // switch
        }

        varv++;
        string varvStr = to_string(varv);
        SDL_Surface *varvSurf = TTF_RenderText_Solid(font, varvStr.c_str(), color);
        SDL_Texture *varvTx = SDL_CreateTextureFromSurface(ren, varvSurf);
        SDL_Rect varvRect = {300, 300, varvSurf->w, varvSurf->h};
        SDL_RenderCopy(ren, varvTx, NULL, &varvRect);

        SDL_FreeSurface(varvSurf);
        SDL_RenderClear(ren);
        // Suddar bufferten i renderaren för fönstret

        SDL_RenderCopy(ren, bgTx, NULL, NULL);
        // Renderare, textur, position i fönstret. NULL resp. NULL för hela fönstret
        SDL_RenderCopy(ren, gubbTx, NULL, &gubbRect);
        SDL_RenderPresent(ren);
        // Skriver ut från renderaren till canvas/skärmen

        SDL_DestroyTexture(varvTx);

        int delay = nextTick - SDL_GetTicks();
        // Vi får veta om det finns tid kvar tills nästa tick

        if (delay > 0)
        {
            SDL_Delay(delay);
            // Finns det tid kvar så delayar vi programmet för att få 60fps.
        }

    } // while

    // SDL_Delay(20000);
    //  Delay söver programet i x antal millisekunder, men behövs inte i och med att programmet körs till användaren klickar på X eller avbryter programmet enligt while loop ovan.
    SDL_DestroyTexture(donkTx);
    TTF_CloseFont(font);
    SDL_DestroyTexture(bgTx);
    SDL_DestroyTexture(gubbTx);
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);

    SDL_Quit();

    return 0;
}
