#include <SFML/Graphics.hpp>
#include <iostream>
#include "BounceClassic.h"

int main()
{
    

    Game Bounce;
    Bounce.Start();


    while (Bounce.window.isOpen())
    {


        
        while (Bounce.window.pollEvent(Bounce.event))
        {
            if (Bounce.event.type == sf::Event::Closed)
                Bounce.window.close();
        }


        Bounce.Update();


        //RENDERING PHASE
        Bounce.window.clear();
        Bounce.Render();
        Bounce.window.display();
    }

    return 0;
}