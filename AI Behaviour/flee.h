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

#pragma once
	#include "utility.h"


class StateFlee : public State
{
public:
	StateFlee();
	~StateFlee();
	void update(float dtime, sf::Event* event);
	void draw();
	const char* getTitle();

private:
	std::vector<Unit*> units;
	sf::Vector2f target;
};