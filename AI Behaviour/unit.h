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

class Unit
{
	friend class SteeringBehaviour;

private:
	SteeringBehaviour* steering_behaviour;
	sf::Vector2f position;
	sf::Vector2f velocity;
	sf::Vector2f target;

	float mass;
	float orientation;
	float max_force;
	float max_velocity;

	sf::Color color = sf::Color::Yellow;

	//sf::Texture* sprite_texture;
	bool draw_sprite;
	int sprite_num_frames;
	int sprite_w;
	int sprite_h;

public:
	Unit();
	~Unit();
	SteeringBehaviour* Behaviour();
	sf::Vector2f getPosition();
	sf::Vector2f getTarget();
	sf::Vector2f getVelocity();
	float getMaxVelocity();
	void setPosition(sf::Vector2f position);
	void setTarget(sf::Vector2f target);
	void setVelocity(sf::Vector2f velocity);
	void setMaxVelocity(sf::Vector2f mv);
	void setMass(float mass);
	void setColor(sf::Uint8 r, sf::Uint8 g, sf::Uint8 b, sf::Uint8 a);
	void update(sf::Vector2f steering_force, float dtime, sf::Event* event);
	void draw();
	//bool Unit::loadSpriteTexture(char* filename, int num_frames = 1);
	float getMaxForce() {
		return max_force;
	}
};
