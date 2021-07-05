#include "utility.h"


SteeringBehaviour::SteeringBehaviour()
{

}


SteeringBehaviour::~SteeringBehaviour()
{
}

sf::Vector2f SteeringBehaviour::Seek(Unit* agent, sf::Vector2f target, float dtime)
{
	sf::Vector2f desiredV = target - agent->getPosition(); 
	Normalise(desiredV);
	desiredV *= agent->getMaxVelocity();
	sf::Vector2f steeringForce = desiredV - agent->getVelocity();
	steeringForce /= agent->getMaxVelocity();
	steeringForce *= agent->getMaxForce();

	return steeringForce;
}

sf::Vector2f SteeringBehaviour::Flee(Unit* agent, sf::Vector2f target, float dtime)
{
	sf::Vector2f DesiredVelocity = agent->getPosition() - target;
	Normalise(DesiredVelocity);
	DesiredVelocity *= agent->getMaxVelocity();
	sf::Vector2f SteeringForce = (DesiredVelocity - agent->getVelocity());
	SteeringForce /= agent->getMaxVelocity();
	return SteeringForce * agent->getMaxForce();
}

sf::Vector2f SteeringBehaviour::Arrive(Unit* agent, sf::Vector2f target, float r, float dtime) {
	sf::Vector2f desiredV = target - agent->getPosition();
	sf::Vector2f steeringForce = desiredV - agent->getVelocity();
	float factor;
	sf::Vector2f dist = target - agent->getPosition();

	if (Length(dist) >= r)
	{
		//draw_circle(TheApp::Instance()->getRenderer(), target.x, target.y, r, 0, 0, 255, 1);
		Normalise(desiredV);
		desiredV *= agent->getMaxVelocity();
		steeringForce /= agent->getMaxVelocity();
		steeringForce *= agent->getMaxForce();
	}
	else
	{
		factor = Length(dist) / r;
		//draw_circle(TheApp::Instance()->getRenderer(), target.x, target.y, r, 0, 255, 0, 1);
		desiredV *= factor;
	}

	return steeringForce;
}

sf::Vector2f SteeringBehaviour::Pursue(Unit* agent, sf::Vector2f target, float maxSpeed, float dtime)
{

	sf::Vector2f desiredV = target - agent->getPosition(); 
	desiredV *= agent->getMaxVelocity();
	sf::Vector2f steeringForce = desiredV - agent->getVelocity();
	steeringForce /= agent->getMaxVelocity();
	steeringForce *= agent->getMaxForce();

	return steeringForce;
}

sf::Vector2f SteeringBehaviour::Evade(Bird* agent, sf::Vector2f target, float maxSpeed, float dtime)
{
	sf::Vector2f desiredV = target - agent->getPosition(); 
	Normalise(desiredV);
	desiredV *= agent->getMaxVelocity();
	sf::Vector2f steeringForce = desiredV - agent->getVelocity();
	steeringForce /= agent->getMaxVelocity();
	steeringForce *= agent->getMaxForce();

	return steeringForce;
}
sf::Vector2f SteeringBehaviour::Wander(Unit* agent, sf::Vector2f target, float dtime)
{

	sf::Vector2f desiredV = target - agent->getPosition();
	Normalise(desiredV);
	desiredV *= agent->getMaxVelocity();
	sf::Vector2f steeringForce = desiredV - agent->getVelocity();
	steeringForce /= agent->getMaxVelocity();
	steeringForce *= agent->getMaxForce();

	return steeringForce;
}

sf::Vector2f SteeringBehaviour::CollisionAvoidance(Unit* agent, sf::Vector2f target, std::vector <sf::Vector2f> obstacles, float dtime, float MAX_AHEAD, float MAX_AVOID_FORCE)
{
	float v = Length(agent->getVelocity()) / agent->getMaxVelocity();
	sf::Vector2f ahead = agent->getPosition() + agent->getVelocity() * v; 
	sf::Vector2f halfahead = agent->getPosition() + agent->getVelocity() * 0.5f * v;
	std::vector <sf::Vector2f> distances, subdistances, avoidForce;

	for (int i = 0; i < obstacles.size(); i++) {

		sf::Vector2f d = ahead - obstacles[i];
		distances.push_back(d);
		sf::Vector2f subD = halfahead - obstacles[i];
		subdistances.push_back(subD);
		sf::Vector2f af;
		af = ahead - obstacles[i];
		Normalise(af);
		af *= MAX_AVOID_FORCE;
		avoidForce.push_back(af);


	}
	
	for (int i = 0; i < avoidForce.size(); i++) {

		//draw_circle(TheApp::Instance()->getRenderer(), Length(avoidForce[i]), 50, 10, 255, 255, 255, 255);
		
		//SDL_RenderDrawLine(TheApp::Instance()->getRenderer(), 100, 20 * i + 20, distances[i].Length(), 20 * i + 20);
		//SDL_RenderDrawLine(TheApp::Instance()->getRenderer(), 100, 20 * i + 20, avoidForce[i].Length(), 20 * i + 20);
	}


	for (int i = 0; i < obstacles.size(); i++) {

		if (Length(distances[i]) <= 50 || Length(subdistances[i]) <= 50 || Distance(agent->getPosition(), obstacles[i]) <= 50) {//50 = radi de s'esfera


			//draw_circle(TheApp::Instance()->getRenderer(), 50, 50, 10, 255, 255, 255, 255);
			//SDL_RenderDrawLine(TheApp::Instance()->getRenderer(), agent->getPosition().x, agent->getPosition().y, avoidForce[i].x, avoidForce[i].y);
			sf::Vector2f desiredV = target - agent->getPosition();
			Normalise(desiredV);
			desiredV *= agent->getMaxVelocity();
			sf::Vector2f steeringForce = desiredV - agent->getVelocity();
			steeringForce /= agent->getMaxVelocity();
			steeringForce *= agent->getMaxForce();
			distances.clear();
			subdistances.clear();

			//draw_circle(TheApp::Instance()->getRenderer(), 50, 50, 10, 255, 255, 255, 255);

			//SDL_RenderDrawLine(TheApp::Instance()->getRenderer(), agent->getPosition().x, agent->getPosition().y, ahead.x, ahead.y);


			return steeringForce + avoidForce[i];

		}
		else {

			sf::Vector2f desiredV = target - agent->getPosition();
			Normalise(desiredV);
			desiredV *= agent->getMaxVelocity();
			sf::Vector2f steeringForce = desiredV - agent->getVelocity();
			steeringForce /= agent->getMaxVelocity();
			steeringForce *= agent->getMaxForce();


			//draw_circle(TheApp::Instance()->getRenderer(), 50, 50, 10, 255, 255, 255, 255);

			//SDL_RenderDrawLine(TheApp::Instance()->getRenderer(), agent->getPosition().x, agent->getPosition().y, ahead.x, ahead.y);



			return steeringForce;

		}
	}

}

