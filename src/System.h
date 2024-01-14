#ifndef SYSTEM_H
#define SYSTEM_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include <string>
#include <vector>

namespace cwing
{

	class System
	{

	private:
		SDL_Window *win;
		SDL_Renderer *ren;
		TTF_Font *font;
		Mix_Chunk *music;
		std::vector<Mix_Chunk *> sounds;
		bool running;

	public:
		System();
		~System();

		SDL_Renderer *get_ren() const;
		TTF_Font *get_font() const;
		Mix_Chunk *get_music() const;
		void play_sound(std::string path);
	};

	extern System sys;
}

#endif