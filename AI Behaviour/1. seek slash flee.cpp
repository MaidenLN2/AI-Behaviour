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

	StateFlee::StateFlee()
	{
		Unit* unit = new Unit;
		unit->setPosition(sf::Vector2f(800, 800));
		unit->setTarget(sf::Vector2f(400, 400));
		//unit->loadSpriteTexture("../res/soldier.png", 4);
		units.push_back(unit);
		target = sf::Vector2f(800, 800);
	}

	StateFlee::~StateFlee()
	{
		for (int i = 0; i < (int)units.size(); i++)
		{
			delete units[i];
		}
	}

	void StateFlee::update(float dtime, sf::Event* event)
	{
		switch (event->type) 
		{
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

		sf::Vector2f steering_force = units[0]->Behaviour()->Flee(units[0], units[0]->getTarget(), dtime);
		units[0]->update(steering_force, dtime, event);
	}

	void StateFlee::draw() 
	{
		// setting up target circle usung SFML
		sf::CircleShape shape;
		shape.setFillColor(sf::Color::Transparent);

		shape.setOutlineColor(sf::Color::Red);
		shape.setOutlineThickness(10.0f);

		shape.setPosition(target.x, target.y);

		units[0]->draw();
	}

	const char* StateFlee::getTitle()
	{
		return "AI Steering Behaviours :: Flee Demo";
	}