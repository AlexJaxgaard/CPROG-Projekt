/*
---------
Alexander Jaxgård ALJA9460
Elias Bennaceur ELBE7219
---------
*/
#include "Constants.h"
#include "System.h"

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
		for (int i = 0; i < MIX_CHANNELS; i++)
		{
			if (sounds[i] != NULL)
			{
				Mix_FreeChunk(sounds[i]);
			}
		}
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

	void System::play_sound(std::string path)
	{
		Mix_Chunk *sound = Mix_LoadWAV((constants::gResPath + "sounds/" + path).c_str());
		if (sound == NULL)
		{
			std::cout << "Failed to load sound: " << Mix_GetError() << std::endl;
			return;
		}
		int channel = Mix_PlayChannel(-1, sound, 0);
		if (channel == -1)
		{
			std::cout << "Failed to play sound: " << Mix_GetError() << std::endl;
			Mix_FreeChunk(sound);
			return;
		}

		if (channel >= (int)sounds.size())
		{
			sounds.resize(channel + 1, nullptr);
		}

		sounds[channel] = sound;
	}

	bool running;

	System sys; // Statiskt globalt objekt (definierad utanför funktioner.)
}