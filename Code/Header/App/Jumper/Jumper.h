#pragma once
#include <iostream>
#include <ctime>

/* Framework */
#include "../../../SFML/include/SFML/Graphics.hpp"

/* Attractors */
#include "../Attractor/Attractor.h"

class Jumper
{
    public:

        void Create(sf::RenderWindow *Window, std::vector<Attractor*>* AttractorList);

        void Jump();
        void Render();
        void Clear();

    private:

        sf::RenderWindow *_AppWindow;
        sf::CircleShape _Jumper;

        int _JumpPercentage;

        /* Attractor List */
        std::vector<Attractor*>* _AttractorList;
        std::vector<sf::CircleShape*> _OldPositions;


};