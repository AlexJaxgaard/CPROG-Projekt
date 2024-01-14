#include "Component.h"
#include <string>
#include "System.h"
#include "Session.h"

class Missile : public cwing::Component
{

private:
    SDL_Rect rect;

    std::string text;
    SDL_Texture *texture;
    bool isExploding = false;
    SDL_Texture *spriteSheet = nullptr;
    std::vector<SDL_Rect> sourceRects;
    int currentFrame = 0;
    Uint32 explosionStart;
    std::string label = "missile";
    cwing::Session &ses;
    bool hasExploded;

protected:
public:
    Missile(int xpos, int ypos, cwing::Session &ses);
    ~Missile();
    void draw() const;
    void moveForward();
    const SDL_Rect &getRect() const { return rect; }
    void hit();
    void tick() override;
    void collision(Component *comp) override;
    std::string getLabel() override { return label; }
};
