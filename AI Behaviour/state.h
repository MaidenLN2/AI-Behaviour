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

class State
{
public:
	State() {};
	virtual ~State() {};
	virtual void update(float dtime, sf::Event* event) = 0;
	virtual void draw() = 0;
	virtual const char* getTitle() { return ""; };
};
