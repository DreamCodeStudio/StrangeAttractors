#pragma once
#include <iostream>
#include <vector>

/* Framework */
#include "../../SFML/include/SFML/Graphics.hpp"

/* Buttons */
#include "../GUI/Button/Button.h"

/* Sliders */
#include "../GUI/Slider/Slider.h"

/* Attractors */
#include "Attractor/Attractor.h"

/* Jumper */
#include "Jumper/Jumper.h"

class App
{
    public:

        void Create();

        void Run();
        bool IsOpen();

    private:

        void HandleEvents();
        void Update();
        void Render();

        sf::RenderWindow _AppWindow;
        sf::RectangleShape _AppBackground;

        /* Buttons */
        GUI::Button _CreateAttractor;
        GUI::Button _SingleJump;
        GUI::Button _Run;
        GUI::Button _Stop;
        GUI::Button _Clear;

        /* Sliders */
        GUI::Slider _Distance;

        bool _IsRunning;

        /* Attractors */
        std::vector<Attractor*> _Attractors;

        /* Jumper */
        Jumper _Jumper;

};