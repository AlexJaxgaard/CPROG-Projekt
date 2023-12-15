#include <string>
#include <iostream>
#include <SDL2/SDL.h>

using namespace std;

int main(int argc, char **argv)
{
    // SDL_image - andra bildformat än BMP
    // SDL_ttf - text
    // SDL_mixer - audio
    // SDL_net - nätverk
    // Se iLearn för mer information

    // SDL_Init(SDL_INIT_EVERYTHING);
    // SDL_INIT returnerar ett heltal, -1 om misslyckats, 0 om lyckats.

    if (SDL_INIT_EVERYTHING < 0)
    {

        cout << "Något eller några av SDL:s initieringar misslyckades. Felsöker." << endl;

        if (SDL_INIT_AUDIO < 0)
        {
            cout << "misslyckad ljud-initialisering" << endl;
        }

        if (SDL_INIT_EVENTS < 0)
        {
            cout << "misslyckad evenemangs-initialisering" << endl;
        }

        if (SDL_INIT_GAMECONTROLLER < 0)
        {
            cout << "misslyckad spelkontrolls-initialisering" << endl;
        }

        if (SDL_INIT_HAPTIC < 0)
        {
            cout << "misslyckad haptic-initalisering" << endl;
        }

        if (SDL_INIT_JOYSTICK < 0)
        {
            cout << "misslyckad joystick-initialisering" << endl;
        }

        if (SDL_INIT_NOPARACHUTE < 0)
        {
            cout << "misslyckad NOPARACHUTE-initialisering" << endl;
        }

        if (SDL_INIT_SENSOR < 0)
        {
            cout << "misslyckad sensor-initialisering" << endl;
        }

        if (SDL_INIT_TIMER < 0)
        {
            cout << "misslyckad timer-initialisering" << endl;
        }

        if (SDL_INIT_VIDEO < 0)
        {
            cout << "misslyckad video-initialisering" << endl;
        }
    }
    else
    {
        cout << "initialisering av system lyckades" << endl;
    }

    return 0;
}