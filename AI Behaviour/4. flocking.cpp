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

	StateFlocking::StateFlocking()
	{
		Unit* unit = new Unit;
		unit->setPosition(sf::Vector2f(640, 360));
		unit->setTarget(sf::Vector2f(640, 360));
		//unit->loadSpriteTexture("../res/cat.png", 3);
		units.push_back(unit);
		target = sf::Vector2f(640, 360);
		srand(time(NULL));

		//Unit* bg = new Unit;
		//bg->setPosition(sf::Vector2f(0, 383));
		//bg->loadSpriteTexture("../res/bg.jpg", 2);
		//units.push_back(bg);

		//Unit* text = new Unit;
		//text->setPosition(sf::Vector2f(635, -80));
		//text->loadSpriteTexture("../res/combiningsb.png", 2);
		//units.push_back(text);
		for (int i = 0; i < rand() % 10 + 4; i++) {

			Unit* z = new Unit;
			z->setPosition(sf::Vector2f(200 + rand() % 50, 200 + rand() % 50));
			z->setMaxVelocity(sf::Vector2f(100, 100));
			//if (i % 2 == 0) z->loadSpriteTexture("../res/dogblack.png", 3);
			//else z->loadSpriteTexture("../res/dog.png", 3);
			units.push_back(z);
			r = 50;
			neighbourCount = 0;
		}

		separation.x, separation.y = 0.0f;
	}

	StateFlocking::~StateFlocking()
	{
		for (int i = 0; i < (int)units.size(); i++)
		{
			delete units[i];
		}


	}

	void StateFlocking::update(float dtime, sf::Event* event)
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


		for (int i = 3; i < units.size(); i++) {
			obstacles.push_back(units[i]->getPosition());
			neighbourCount++;

		}

		float t;
		dist = units[0]->getPosition() - units[3]->getPosition();


		sf::Vector2f steering_force = units[0]->Behaviour()->Seek(units[0], units[0]->getTarget(), dtime);
		units[0]->update(steering_force, dtime, event);

		for (int i = 3; i < units.size(); i++) {
			if (Length(units[0]->getVelocity()) == 0)
				t = 2;
			else
				t = Length(dist) / Length(units[0]->getVelocity());
			steering_force = units[i]->Behaviour()->Pursue(units[i], units[0]->getPosition() + units[0]->getVelocity() * t, 100, dtime);

			for (int j = 4; j < units.size(); j++) {
				sf::Vector2f farness;
				farness.x, farness.y = Distance(units[i]->getPosition(), units[j]->getPosition());
				if (Length(farness) <= r) {
					alignment += (units[j]->getVelocity());
					cohesion += units[j]->getPosition();
					separation += units[j]->getPosition() - units[i]->getPosition();
				}
			}
			alignment /= (float)neighbourCount;
			Normalise(alignment);

			cohesion /= (float)neighbourCount;
			cohesion = sf::Vector2f(cohesion.x - units[i]->getPosition().x, cohesion.y - units[i]->getPosition().y);
			Normalise(cohesion);

			separation /= (float)neighbourCount;
			separation *= -1.0f;
			Normalise(separation);

			units[i]->update(steering_force + separation * 60.f + cohesion * 25.f + alignment * 20.f, dtime, event);
			separation.x, separation.y = 0;
		}

		obstacles.clear();
	}

	void StateFlocking::draw()
	{
		units[1]->draw();
		for (int i = 1; i < units.size(); i++)
			units[i]->draw();

		//draw_circle(TheApp::Instance()->getRenderer(), (int)target.x, (int)target.y, 15, 255, 0, 0, 255);
		units[0]->draw();
		units[2]->draw();
	}

	const char* StateFlocking::getTitle()
	{
		return "AI Steering Behaviours :: KinematicSeek Demo";
	}