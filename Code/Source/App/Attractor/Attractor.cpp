#include "../../../Header/App/Attractor/Attractor.h"

void Attractor::Create(sf::RenderWindow *Window)
{
    /* Save pointer to window */
    _AppWindow = Window;

    /* Create Attractor */
    _Attractor.setRadius(5);
    _Attractor.setFillColor(sf::Color(0, 255, 0));
    _Attractor.setPosition(100, 100);

    /* Set start values */
    _IsDragged = false;
}

void Attractor::Update()
{
    /* Check if the attractor gets dragged */

    if (!sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        _IsDragged = false;
    }

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        if (sf::Mouse::getPosition(*_AppWindow).x > _Attractor.getPosition().x && sf::Mouse::getPosition(*_AppWindow).x < _Attractor.getPosition().x + _Attractor.getRadius() * 2 &&
            sf::Mouse::getPosition(*_AppWindow).y > _Attractor.getPosition().y && sf::Mouse::getPosition(*_AppWindow).y < _Attractor.getPosition().y + _Attractor.getRadius() * 2)
        {
            _IsDragged = true;
        }
    }

    if (_IsDragged == true)
    {
        _Attractor.setPosition(sf::Mouse::getPosition(*_AppWindow).x, sf::Mouse::getPosition(*_AppWindow).y);
    }
}

void Attractor::Render()
{
    _AppWindow->draw(_Attractor);
}

sf::Vector2f Attractor::GetPosition()
{
    return _Attractor.getPosition();
}