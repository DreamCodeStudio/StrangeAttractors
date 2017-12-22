#include "../../Header/App/App.h"

void App::Create()
{
    /* Create window */
    _AppWindow.create(sf::VideoMode(900, 900), "Strange Attractors");

    /* Create AppBackground */
    _AppBackground.setSize(sf::Vector2f(900, 900));
    _AppBackground.setFillColor(sf::Color(255, 255, 255));

    /* Create Button */
    _CreateAttractor.Create(&_AppWindow, sf::Vector2f(10, 10), sf::Vector2f(150, 50), sf::Color(230, 230, 230), sf::Color(0, 0, 0), "Create", "Data/Font/std.ttf");
    _SingleJump.Create(&_AppWindow, sf::Vector2f(170, 10), sf::Vector2f(150, 50), sf::Color(230, 230, 230), sf::Color(0, 0, 0), "Jump", "Data/Font/std.ttf");
    _Run.Create(&_AppWindow, sf::Vector2f(330, 10), sf::Vector2f(150, 50), sf::Color(230, 230, 230), sf::Color(0, 0, 0), "Run", "Data/Font/std.ttf");
    _Stop.Create(&_AppWindow, sf::Vector2f(490, 10), sf::Vector2f(150, 50), sf::Color(230, 230, 230), sf::Color(0, 0, 0), "Stop", "Data/Font/std.ttf");
    _Clear.Create(&_AppWindow, sf::Vector2f(650, 10), sf::Vector2f(150, 50), sf::Color(230, 230, 230), sf::Color(0, 0, 0), "Clear", "Data/Font/std.ttf");

    /* Create Jumper */
    _Jumper.Create(&_AppWindow, &_Attractors);

    /* Set start values */
    _IsRunning = false;
}

void App::Run()
{
    this->HandleEvents();
    this->Update();
    this->Render();
}

bool App::IsOpen()
{
    return _AppWindow.isOpen();
}

/* ################### Private ################## */

void App::HandleEvents()
{
    /* Handle events e.g if the window gets closed */
    sf::Event event;
    while(_AppWindow.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            _AppWindow.close();
        }
    }
}

void App::Update()
{
    /* Update Buttons */
    _CreateAttractor.Update();
    if (_CreateAttractor.IsPressed())
    {
        /* Add new attractor */
        _Attractors.push_back(new Attractor);   
        _Attractors[_Attractors.size() - 1]->Create(&_AppWindow);
    }

    /* Update jump button */
    _SingleJump.Update();
    if (_SingleJump.IsPressed())
    {
        _Jumper.Jump();
    }

    /* Update run button */
    _Run.Update();
    if (_Run.IsPressed())
    {
        _IsRunning = true;
    }

    /* Update stop button */
    _Stop.Update();
    if (_Stop.IsPressed())
    {
        _IsRunning = false;
    }

    /* Update clear button */
    _Clear.Update();
    if (_Clear.IsPressed())
    {
        _Jumper.Clear();
    }

    /* If the start button was clicked -> run 100 times every frame */
    if (_IsRunning == true)
    {
        for (unsigned int i = 0; i < 100; i++)
        {
            _Jumper.Jump();
        }
    }

    /* Update all Attractors */
    for (unsigned int i = 0; i < _Attractors.size(); i++)
    {
        _Attractors[i]->Update();
    }
}

void App::Render()
{
    _AppWindow.clear();

    /* Draw App Background */
    _AppWindow.draw(_AppBackground);
    
    /* Draw Buttonss */
    _CreateAttractor.Render();
    _SingleJump.Render();
    _Run.Render();
    _Stop.Render();
    _Clear.Render();

    /* Draw Jumper */
    _Jumper.Render();

    /* Draw all Attractors */
    for (unsigned int i = 0; i < _Attractors.size(); i++)
    {
        _Attractors[i]->Render();
    }


    _AppWindow.display();
}