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

StatePursue::StatePursue()
{
	Unit* unit = new Unit;
	unit->setTarget(sf::Vector2f(100, 100));
	unit->setMass(0.6f);
	unit->setColor(0, 0, 255, 255);
	//unit->loadSpriteTexture("../res/zombie1.png", 8);
	units.push_back(unit);
	unit = new Unit();
	unit->setPosition(sf::Vector2f(600, 50));
	unit->setTarget(sf::Vector2f(900, 650));
	//unit->loadSpriteTexture("../res/soldier.png", 4);
	units.push_back(unit);
	target = sf::Vector2f(900, 650);
}

StatePursue::~StatePursue()
{
	for (int i = 0; i < (int)units.size(); i++)
	{
		delete units[i];
	}
}

void StatePursue::update(float dtime, sf::Event* event)
{
	/* Keyboard & Mouse events */
	switch (event->type) {
	case sf::Event::MouseMoved:
	case sf::Event::MouseButtonPressed:
		if (event->mouseButton.button == sf::Mouse::Left)
		{
			target = sf::Vector2f((float)(event->mouseButton.x), (float)(event->mouseButton.y));
			units[1]->setTarget(target);
		}
		break;
	default:
		break;
	}

	units[0]->setTarget(units[1]->getPosition());
	sf::Vector2f steering_force = units[1]->Behaviour()->Arrive(units[1], units[1]->getTarget(), 200, dtime);
	units[1]->update(steering_force, dtime, event);
	steering_force = units[0]->Behaviour()->Pursue(units[0], units[1]->getTarget(), 200, dtime);
	units[0]->update(steering_force, dtime, event);
}

void StatePursue::draw()
{
	sf::CircleShape shape;
	for (int i = 0; i < (int)units.size(); i++)
	{
		units[i]->draw();
	}
}

const char* StatePursue::getTitle()
{
	return "SDL Steering Behaviours :: Seek and Pursue Demo";
}