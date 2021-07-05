//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2021 Media Design School
//
// File Name      : 
// Description    : 
// Author   :   Lera Blokhina
// Mail     :   valeriia.blokhina@mds.ac.nz
//	

#include "utility.h"

	using namespace std;

	StateArrival::StateArrival()
	{
		Unit* unit = new Unit;
		unit->setPosition(sf::Vector2f(800, 800));
		unit->setTarget(sf::Vector2f(800, 800));
		//unit->loadSpriteTexture("../res/soldier.png", 4);
		units.push_back(unit);
		target = sf::Vector2f(800, 800);
	}

	StateArrival::~StateArrival()
	{
		for (int i = 0; i < (int)units.size(); i++)
		{
			delete units[i];
		}
	}

	void StateArrival::update(float dtime, sf::Event* event)
	{
		/* Keyboard & Mouse events */
		switch (event->type) {
		case sf::Event::MouseMoved:
		case sf::Event::MouseButtonPressed:
			if (event->mouseButton.button == sf::Mouse::Left)
			{
				target = sf::Vector2f((float)(event->mouseButton.x), (float)(event->mouseButton.y));
				units[0]->setTarget(target);
			}
			break;
		default:
			break;
		}
		sf::Vector2f steering_force = units[0]->Behaviour()->Arrive(units[0], units[0]->getTarget(), 325, dtime);
		units[0]->update(steering_force, dtime, event);
	}

	void StateArrival::draw()
	{
		//draw_circle(TheApp::Instance()->getRenderer(), (int)target.x, (int)target.y, 15, 255, 0, 0, 255);
		units[0]->draw();
	}

	const char* StateArrival::getTitle()
	{
		return "SDL Steering Behaviours :: Arrival Demo";
	}