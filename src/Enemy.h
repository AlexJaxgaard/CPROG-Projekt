#include "Component.h"
#include <string>
#include "System.h"
#include "Session.h"

class Enemy : public cwing::Component
{

private:
    int lives;
    std::string text;
    SDL_Texture *texture;
    SDL_Rect rectangle;
    std::string label = "enemy";
    cwing::Session &ses;
    double velocity;

protected:
public:
    Enemy(int x, int y, int w, int h, cwing::Session &ses);
    ~Enemy(){}
    void draw() const;
    void hit();
    void moveForward();
    const SDL_Rect &getRect() const { return rectangle; }
    void tick() override;
    void collision(Component *comp) override{}
    std::string getLabel() override { return label; }
    bool isDead() { return lives <= 0; }
};
