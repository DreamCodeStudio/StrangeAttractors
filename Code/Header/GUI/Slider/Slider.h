#include <iostream>

/* Framework */
#include "../../../SFML/include/SFML/Graphics.hpp"

namespace GUI
{
    class Slider
    {
        public:

            void Create(sf::RenderWindow *Window, sf::Vector2f Position, sf::Vector2f Size, int MaxValue, int MinValue);

            void Update();
            void Render();

            float GetValue();

        private:

            sf::RenderWindow *_AppWindow;
            
            sf::RectangleShape _Background;
            sf::RectangleShape _Slider;

            int _MaxValue, _MinValue;

    };
}