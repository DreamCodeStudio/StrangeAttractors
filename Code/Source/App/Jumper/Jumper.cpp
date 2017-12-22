#include "../../../Header/App/Jumper/Jumper.h"

void Jumper::Create(sf::RenderWindow *Window, std::vector<Attractor*>* AttractorList)
{
    /* Save pointer to window */
    _AppWindow = Window;

    /* Save parameter */
    _AttractorList = AttractorList;

    /* Random seed */
    srand(time(NULL));

    /* Create Jumper */
    _Jumper.setFillColor(sf::Color(0, 0, 255));
    _Jumper.setRadius(5);
    _Jumper.setPosition(450, 450);

    /* Set start values */
    _JumpPercentage = 0.5;
}

void Jumper::Jump()
{
    /* Get random attractor */
    int RandomAttractor = rand() % _AttractorList->size();

    /* Jump part of the way */
    float XDistance = (_AttractorList->at(RandomAttractor)->GetPosition().x - _Jumper.getPosition().x) / 2;
    float YDistance = (_AttractorList->at(RandomAttractor)->GetPosition().y - _Jumper.getPosition().y) / 2;

    _OldPositions.push_back(new sf::CircleShape);
    _OldPositions[_OldPositions.size() - 1]->setFillColor(sf::Color(255, 0, 0));
    _OldPositions[_OldPositions.size() - 1]->setPosition(_Jumper.getPosition());
    _OldPositions[_OldPositions.size() - 1]->setRadius(2);

    _Jumper.move(XDistance, YDistance);
}

void Jumper::Render()
{
    for (unsigned int i = 0; i < _OldPositions.size(); i++)
    {
        _AppWindow->draw(*_OldPositions[i]);
    }

    _AppWindow->draw(_Jumper);
}

void Jumper::Clear()
{
    for (unsigned int i = 0; i < _OldPositions.size(); i++)
    {
        delete _OldPositions[i];
    }
    _OldPositions.clear();
}