#pragma once

#include "utility.h"

class Unit;
class Bird;
class SteeringBehaviour
{
public:
	SteeringBehaviour();
	~SteeringBehaviour();


	/* Add here your own Steering Behaviour functions declarations */
	sf::Vector2f Seek(Unit* agent, sf::Vector2f target, float dtime);
	sf::Vector2f Flee(Unit* agent, sf::Vector2f target, float dtime);
	sf::Vector2f Arrive(Unit* agent, sf::Vector2f target, float r, float dtime);
	sf::Vector2f Pursue(Unit* agent, sf::Vector2f target, float maxSpeed, float dtime);
	sf::Vector2f Evade(Bird* agent, sf::Vector2f target, float maxSpeed, float dtime);
	sf::Vector2f Wander(Unit* agent, sf::Vector2f target, float dtime);
	sf::Vector2f CollisionAvoidance(Unit* agent, sf::Vector2f target, std::vector <sf::Vector2f> obstacles, float dtime, float MAX_AHEAD, float MAX_AVOID_FORCE);
	//sf::Vector2f Combining(Unit* agent, sf::Vector2f target, float dtime);



};

