/*This "main.cpp" file is divided by sections, each section contains an example about 
the usage of the classes of this little library. 
To run each example, just uncomment the content of the section you wanna test. :3 */

#include <SFML/Graphics.hpp>
#include<iostream>
#include"bullet.hpp"

sf::CircleShape _bullet(8,16);
sf::Vector2f origen;
bullet *bu1[16];


int main()
{
    auto window = sf::RenderWindow(sf::VideoMode({1200,608}), "CMake SFML Project");
    window.setFramerateLimit(30);
    origen={window.getSize().x/2,window.getSize().y/2};
/************************** Here Starts the parabolic shoot example ****************/
    //declaring and instansing a physicVector:
    physicVector *Velocity,*gravity,*velCaida;
    // just a SFML's Circle shape to manipulate it.
    _bullet.setOrigin({8,8});
    //let's instance the vectors, they recibe a magnitude, a direction, and optionaly, origin.
    Velocity=new physicVector(10,315,origen);
    gravity=new physicVector(0.1,90);
    velCaida=gravity;// You can even igualate a vector to another vector
    velCaida->setMagnitude(0);//and modify its atributes by setters.
    _bullet.setPosition({0,304});

    //the "while" bellow, is something from SFML, 
    //you can see:https://www.sfml-dev.org/tutorials/3.0 for more info.
    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
        }

        gravity->integrate(*velCaida);//this will acumulate the magnitud by iteration.
        //Then we can add the fallingVelocity to our object velocity vector:
        Velocity->add(*velCaida);
        std::cout<<Velocity->getMagitude()<<"\t"<<Velocity->getDirection()<<std::endl;
        //and we can move a SFML shape object by its "move" method
        _bullet.move(Velocity->getComponents());

        window.clear();
        window.draw(_bullet);//just draw the object to the renderWindow.
        window.display();
        if(_bullet.getPosition().y>=window.getSize().y)break;;
    }
/********************** Here ends the parabolic shoot expamle ****************************/    


}
