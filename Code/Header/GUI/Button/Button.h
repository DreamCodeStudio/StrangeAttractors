#pragma once
#include <iostream>

/* Framework */
#include "../../../SFML/include/SFML/Graphics.hpp"

namespace GUI
{
    class Button
    {
        public:

            void Create(sf::RenderWindow *Window, sf::Vector2f Position, sf::Vector2f Size, sf::Color BackgroundColor, sf::Color LabelColor, std::string Label, std::string FontPath);

            void Update();
            void Render();

            bool IsPressed();

        private:

            sf::RenderWindow *_AppWindow;

            /* Button properties */
            sf::Vector2f _Position;
            sf::Vector2f _Size;
            sf::Color _DefaultColor;
            sf::Font _Font;
            sf::Clock _PressedClock;

            /* Button elements */
            sf::Text _Label;
            sf::RectangleShape _Background;

            bool _IsPressed;

    };

}