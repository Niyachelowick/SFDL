#include<SFML/Graphics.hpp>
#include<math.h>


class physicVector{
    private:
    const float degsToRads=0.01745329252, radsToDegs=57.2957795056;
    bool isDeg=true;
    sf::Vector2f resultantPoint,oirigin,components;
    float magnitude;
    float direction;
    public:
    const bool _rad=false,_grad=true;
    physicVector();
    physicVector(float mag,float dir,sf::Vector2f ogn);
    physicVector(float mag,float dir);
    void decompose();
    void setAngularUnit(bool angUnit);
    void updateOrigin();
    void add(physicVector anotherVector);
    sf::Vector2f getComponents();
    sf::Vector2f getResultant();
    void integrate(physicVector recipe);
    void setMagnitude(float mag);
    void recalcMagnitude();
    void recalcDirection();
    float getMagitude();
    void setDirection(float dir);
    void setOrigin(sf::Vector2f ong);
    float getDirection();
};

physicVector::physicVector(){}

physicVector::physicVector(float mag, float dir,sf::Vector2f ogn){
    this->magnitude=mag;
    this->direction=dir;
    this->oirigin=ogn;
    if(this->isDeg)direction=dir*this->degsToRads;
    this->decompose();    
}

physicVector::physicVector(float mag, float dir){
    this->magnitude=mag;
    this->direction=dir;
    this->oirigin.x=0;
    this->oirigin.y=0;
    if(this->isDeg)direction=dir*this->degsToRads;
    this->decompose();    
}

void physicVector::decompose(){
    components.x=magnitude*cos(direction);
    components.y=magnitude*sin(direction);
    resultantPoint.x=oirigin.x+components.x;
    resultantPoint.y=oirigin.y+components.y;
}

void physicVector::setAngularUnit(bool angUnit){
    this->isDeg=angUnit;
}

void physicVector::updateOrigin(){
    oirigin=resultantPoint;
}

void physicVector::add(physicVector anotherVector){
    this->components.x+=anotherVector.components.x;
    this->components.y+=anotherVector.components.y;
    this->recalcMagnitude();
    this->recalcDirection();
}

sf::Vector2f physicVector::getComponents(){
    return this->components;
}

sf::Vector2f physicVector::getResultant(){
    return this->resultantPoint;
}

void physicVector::integrate(physicVector recipe){
    recipe.components.x+=this->components.x;
    recipe.components.y+=this->components.y;
}

void physicVector::setMagnitude(float mag){
    this->magnitude=mag;
}

void physicVector::recalcMagnitude(){
    this->magnitude=hypotf(this->components.x,this->components.y);
}

float physicVector::getMagitude(){
    return this->magnitude;
}

float physicVector::getDirection(){
    return this->direction;
}

void physicVector::recalcDirection(){
    if(this->isDeg){
        direction=450-(atan2f(this->components.x,this->components.y)*radsToDegs);
        if(direction>360){
            direction=direction-360;
        }else if(direction<0){
            direction=360-direction;
        }
    }
   
}

void physicVector::setDirection(float dir){
    this->direction=dir;
}

void physicVector::setOrigin(sf::Vector2f ong){
    this->oirigin=ong;
}