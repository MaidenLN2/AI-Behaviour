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

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/System/Vector2.hpp>
#include "state.h"
#include "steeringbehaviour.h"
#include <vector>
#include <list>
#include <ctime>
#include <math.h>
#include "unit.h"
#include <iostream>
#include "flee.h"
#include "arrival.h"
#include "wander.h"
#include "flocking.h" 
#include "pursue.h"
#include "bird.h"


#ifndef M_PI	
#define M_PI	3.14159265358979323846   // pi
#endif

#define RAD2DEG (180.0f / (float)M_PI)
#define DEG2RAD ((float)M_PI / 180.0f)

float Length(sf::Vector2f v);
float Distance(sf::Vector2f start, sf::Vector2f end);
void Normalise(sf::Vector2f& normalise);
void Truncate(sf::Vector2f& v, float max);