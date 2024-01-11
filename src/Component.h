#ifndef COMPONENT_H
#define COMPONENT_H
#include <SDL2/SDL.h>
#include <string>


namespace cwing
{
    class Session;
    class Component
    {
    public:
        Component(int x, int y, int w, int h, std::string txt);
        Component();
        ~Component();
        virtual void mouseDown(const SDL_Event &eve) {}
        virtual void mouseUp(const SDL_Event &) {}
        virtual void keyDown(const SDL_Event &) {}
        virtual void keyUp(const SDL_Event &) {}
        virtual void mouseMotion(const SDL_Event &) {}
        virtual void draw() const = 0;
        virtual void tick() = 0;
        virtual void collision(Component *comp) = 0;
        virtual std::string getLabel() { return label; }
        const SDL_Rect& getRect() const { return rect; }


    protected:
        Component(int x, int y, int w, int h);
        void setRect(int x, int y, int w, int h)
        {
            rect = {x, y, w, h};
        }
        bool drag;
    private:
        SDL_Rect rect;
        Component(const Component &) = delete;
        const Component &operator=(const Component &) = delete;
		std::string text;
		SDL_Texture *texture;

        std::string label = "";
    };
}

#endif