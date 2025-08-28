#include"phisicVector.hpp"

class bullet
{
private:
    physicVector *velocidad;
    float modifier;
    sf::CircleShape dot;
    bool trayectoryModified=false;
    float mdX=0,mdy=0;
public:
    bullet();
    bullet(float vel,float dir,sf::Vector2f origen);
    ~bullet();
    void move();
    void drawTo(sf::RenderWindow &window);
    void angularModifier(float delta);
};

bullet::bullet(){
    dot.setRadius(8);
    dot.setPointCount(8);
    dot.setPosition({0,0});
    velocidad=new physicVector();
}

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
    //    velocidad->setDirection(velocidad->getDirection()+modifier);
    //    velocidad->decompose();
        float newVX= velocidad->getComponents().x*mdX -velocidad->getComponents().y* mdy;
        float newVY=velocidad->getComponents().x*mdy + velocidad->getComponents().y*mdX;
        velocidad->setComponents({newVX,newVY});
    }    
    velocidad->updateOrigin();
    dot.move(velocidad->getComponents());
}

void bullet::drawTo(sf::RenderWindow &window){
    window.draw(dot);
}

void bullet::angularModifier(float delta){
    this->modifier=delta;
    this->mdX=cos(delta*physicVector::degsToRads);
    this->mdy=sin(delta*physicVector::degsToRads);
    this->trayectoryModified=true;
}