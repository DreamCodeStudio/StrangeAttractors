#pragma once
#include <iostream>

/* Framework */
#include "../../../SFML/include/SFML/Graphics.hpp"

class Attractor
{
    public:

        void Create(sf::RenderWindow *Window);

        void Update();
        void Render();

        sf::Vector2f GetPosition();

    private:

        sf::RenderWindow *_AppWindow;
        sf::CircleShape _Attractor;
        bool _IsDragged;
};