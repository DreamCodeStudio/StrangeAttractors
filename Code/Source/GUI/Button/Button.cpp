#include "../../../Header/GUI/Button/Button.h"

namespace GUI
{
    void Button::Create(sf::RenderWindow *Window, sf::Vector2f Position, sf::Vector2f Size, sf::Color BackgroundColor, sf::Color LabelColor, std::string Label, std::string FontPath)
    {
        /* Save pointer to main window */
        _AppWindow = Window;

        /* Save parameters */
        _Position = Position;
        _Size = Size;
        _DefaultColor = BackgroundColor;

        /* Load font */
        _Font.loadFromFile(FontPath);

        /* Create Button elements */
        _Label.setFont(_Font); //Set Font
        _Label.setString(Label);
        _Label.setPosition(_Position.x + ((_Size.x - _Label.getGlobalBounds().width) / 2), _Position.y + ((_Size.y - _Label.getGlobalBounds().height) / 2) - 5);
        _Label.setColor(LabelColor);

        _Background.setFillColor(_DefaultColor);
        _Background.setPosition(_Position);
        _Background.setSize(_Size);

        /* Set start values */
        _IsPressed = false;
    }

    void Button::Update()
    {
        /* Set default values */
        _IsPressed = false;
        _Background.setFillColor(_DefaultColor);

        /* Check if the mouse is hovering over the button */
        if (sf::Mouse::getPosition(*_AppWindow).x > _Position.x && sf::Mouse::getPosition(*_AppWindow).x < _Position.x + _Size.x &&
            sf::Mouse::getPosition(*_AppWindow).y > _Position.y && sf::Mouse::getPosition(*_AppWindow).y < _Position.y + _Size.y)
        {
            /* Check if the button is clicked */
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                _IsPressed = true;
                _Background.setFillColor(sf::Color(100, 100, 100));
            }
            else
            {
                _Background.setFillColor(sf::Color(150, 150, 150));
            }
        }
    }

    void Button::Render()
    {
        _AppWindow->draw(_Background);
        _AppWindow->draw(_Label);
    }

    bool Button::IsPressed()
    {
        if (_IsPressed == true && _PressedClock.getElapsedTime().asMilliseconds() > sf::milliseconds(500).asMilliseconds())
        {
            _PressedClock.restart();
            _IsPressed = false;
            return true;
        }
        else
        {
            return false;
        }
    }
}