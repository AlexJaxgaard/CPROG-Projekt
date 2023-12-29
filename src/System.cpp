#include "Constants.h"
#include "System.h"
#include <SDL2/SDL.h>
#include <iostream>

namespace cwing
{

	System::System()
	{
		std::cout << "*** System::System()\n";

		SDL_Init(SDL_INIT_EVERYTHING);
		win = SDL_CreateWindow("Game", SDL_WINDOWPOS_CENTERED,
							   SDL_WINDOWPOS_CENTERED, 700, 600, 0);
		ren = SDL_CreateRenderer(win, -1, 0);
		TTF_Init();
		font = TTF_OpenFont((constants::gResPath + "fonts/arial.ttf").c_str(), 36);
		std::cout << "resPath: " << constants::gResPath << std::endl;

		Mix_OpenAudio(20050, AUDIO_S16SYS, 2, 4096);
		// Path to your own 'sounds' folder!
		// musik = Mix_LoadWAV("./resources/sounds/bgMusic.wav");
		music = Mix_LoadWAV((constants::gResPath + "sounds/bgMusic.wav").c_str());
		Mix_PlayChannel(-1, music, -1);
		running = true;
	}

	System::~System()
	{
		std::cout << "*** System::~System()\n";
		Mix_FreeChunk(music);
		Mix_CloseAudio();
		TTF_CloseFont(font);
		TTF_Quit();
		SDL_DestroyWindow(win);
		SDL_DestroyRenderer(ren);
		SDL_Quit();
		running = false;
	}

	SDL_Renderer *System::get_ren() const
	{
		return ren;
	}

	TTF_Font *System::get_font() const
	{
		return font;
	}

	Mix_Chunk *System::get_music() const
	{
		return music;
	}

	bool running;

	System sys; // Statiskt globalt objekt (definierad utanför funktioner.)
}