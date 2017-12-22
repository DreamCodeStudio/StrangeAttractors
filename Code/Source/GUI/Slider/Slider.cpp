#include "../../../Header/GUI/Slider/Slider.h"

namespace GUI
{
    void Slider::Create(sf::RenderWindow *Window, sf::Vector2f Position, sf::Vector2f Size, int MaxValue, int MinValue)
    {
        /* Save pointer to window */
        _AppWindow = Window;

        /* Create Slider */
        _Background.setFillColor(sf::Color(150, 150, 150));
        _Background.setSize(Size);
        _Background.setPosition(Position);

        _Slider.setFillColor(sf::Color(0, 0, 0));
        _Slider.setSize(sf::Vector2f(5, Size.y));
        _Slider.setOrigin(3, 0);
        _Slider.setPosition(Position);
    
        /* Save parameter */
        _MaxValue = MaxValue;
        _MinValue = MinValue;
    }

    void Slider::Update()
    {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            if (sf::Mouse::getPosition(*_AppWindow).x > _Background.getPosition().x && sf::Mouse::getPosition(*_AppWindow).x < _Background.getPosition().x + _Background.getGlobalBounds().width &&
                sf::Mouse::getPosition(*_AppWindow).y > _Background.getPosition().y && sf::Mouse::getPosition(*_AppWindow).y < _Background.getPosition().y + _Background.getGlobalBounds().height)
            {
                _Slider.setPosition(sf::Mouse::getPosition(*_AppWindow).x, _Slider.getPosition().y);
            }
        }
    }

    void Slider::Render()
    {
        _AppWindow->draw(_Background);
        _AppWindow->draw(_Slider);
    }

    float Slider::GetValue()
    {
        float ValuePerPixel = (_MaxValue - _MinValue) / _Background.getSize().x;
        
        float CurrentValue = ((_Slider.getPosition().x - _Background.getPosition().x) * ValuePerPixel) + _MinValue; 

        return CurrentValue; 
    }


}