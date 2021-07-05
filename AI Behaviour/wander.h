	

#pragma once
	#include "utility.h"

	class StateWander : public State
	{
	public:
		StateWander();
		~StateWander();
		void update(float dtime, sf::Event* event);
		void draw();
		const char* getTitle();
	private:
		std::vector<Unit*> units;
		sf::Vector2f target;
	public:
		// Wander fields
		int wanderMaxChange = 50;
		int wanderCircleOffset = 80;
		int wanderCircleRadius = 70;
		float wanderAngle = 0.0f;
		sf::Vector2f wanderCircleCenter = {};
		sf::Vector2f wanderDisplacementVector = {};
	};


