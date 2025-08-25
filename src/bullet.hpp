#include"phisicVector.hpp"

class bullet
{
private:
    physicVector *velocidad;
    float modifier;
    sf::CircleShape dot;
    bool trayectoryModified=false;
public:
    bullet();
    bullet(float vel,float dir,sf::Vector2f origen);
    ~bullet();
    void move();
    void drawTo(sf::RenderWindow &window);
    void angularModifier(float delta);
};

bullet::bullet(){}

bullet::bullet(float vel,float dir,sf::Vector2f origen)
{
    dot.setRadius(8);
    dot.setPointCount(8);
    dot.setPosition(origen);
    velocidad=new physicVector(vel,dir,origen);
}

bullet::~bullet()
{
}

void bullet::move(){
    if(trayectoryModified){
       velocidad->setDirection(velocidad->getDirection()+modifier);
       velocidad->decompose();
    }    
    velocidad->updateOrigin();
    dot.move(velocidad->getComponents());
}

void bullet::drawTo(sf::RenderWindow &window){
    window.draw(dot);
}

void bullet::angularModifier(float delta){
    this->modifier=delta;
    this->trayectoryModified=true;
}