
#include "phisicVector.hpp"
#include <cmath>

class bullet
{
private:
    physicVector velocidad; // ¡Ya no es un puntero (*)! Es un objeto directo.
    float modifier;
    sf::CircleShape dot;
    bool trayectoryModified = false;
    float mdX = 0, mdy = 0;

public:
    bullet();
    bullet(float vel, float dir, sf::Vector2f origen);
    ~bullet(); // Ya no requiere lógica especial de borrado
    
    void move();
    void drawTo(sf::RenderWindow &window);
    void angularModifier(float delta);
};

// Constructor por defecto
bullet::bullet() {
    dot.setRadius(4);
    dot.setPointCount(8);
    dot.setPosition({0.f, 0.f});
    // velocidad se inicializa automáticamente usando su constructor por defecto
}

// Constructor con parámetros
bullet::bullet(float vel, float dir, sf::Vector2f origen)
:velocidad(vel, dir, origen)
{
    dot.setRadius(4);
    dot.setPointCount(8);
    dot.setPosition(origen);
    // Inicializamos el objeto directamente
}

bullet::~bullet() {
    // Vacío y seguro. C++ limpia 'velocidad' automáticamente.
}

void bullet::move() {
    if (trayectoryModified) {
        // Al ya no ser puntero, usamos el operador punto (.) en lugar de (->)
        float newVX = velocidad.getComponents().x * mdX - velocidad.getComponents().y * mdy;
        float newVY = velocidad.getComponents().x * mdy + velocidad.getComponents().y * mdX;
        velocidad.setComponents({newVX, newVY});
    }    
    velocidad.updateOrigin();
    
    // SFML .move() acumula movimiento offset, pasamos directamente los componentes
    dot.move(velocidad.getComponents());
}

void bullet::drawTo(sf::RenderWindow &window) {
    window.draw(dot);
}

void bullet::angularModifier(float delta) {
    this->modifier = delta;
    // Usamos la constante estática de la clase para la conversión
    this->mdX = std::cos(delta * physicVector::degsToRads);
    this->mdy = std::sin(delta * physicVector::degsToRads);
    this->trayectoryModified = true;
}