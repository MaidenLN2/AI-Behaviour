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
// Author	:   Lera Blokhina
// Mail     :   valeriia.blokhina@mds.ac.nz
//	

#include "utility.h"

	StateWander::StateWander()
	{
		Unit* unit = new Unit;
		unit->setPosition(sf::Vector2f(800, 800));
		unit->setTarget(sf::Vector2f(800, 800));
		unit->setMass(0.035);
		//unit->loadSpriteTexture("../res/soldier.png", 4);
		units.push_back(unit);
		target = sf::Vector2f(800, 800);
		wanderMaxChange = 50;
		wanderCircleOffset = 70;
		wanderCircleRadius = 80;
		wanderAngle = 0.0f;
		wanderCircleCenter = {};
		wanderDisplacementVector = {};
	}

	StateWander::~StateWander()
	{
		for (int i = 0; i < (int)units.size(); i++)
		{
			delete units[i];
		}
	}

	void StateWander::update(float dtime, sf::Event* event)
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
		sf::Vector2f velocity = units[0]->getVelocity();
		float angle = (float)(atan2(velocity.y, velocity.x) * RAD2DEG);
		sf::Vector2f steering_force = units[0]->Behaviour()->Wander(units[0], units[0]->getTarget(), dtime);
		units[0]->update(steering_force, dtime, event);
	}

	void StateWander::draw()
	{
		units[0]->draw();
	}

	const char* StateWander::getTitle()
	{
		return "SDL Steering Behaviours :: Wander Demo";
	}