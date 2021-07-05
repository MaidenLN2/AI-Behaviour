#pragma once

#include "utility.h"

class Bird
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

	sf::Color color;

	sf::Texture* sprite_texture;
	bool draw_sprite;
	int sprite_num_frames;
	int sprite_w;
	int sprite_h;

public:
	Bird();
	~Bird();
	SteeringBehaviour* Behaviour();
	sf::Vector2f getPosition();
	sf::Vector2f getTarget();
	sf::Vector2f getVelocity();
	float getMaxVelocity();
	void setPosition(sf::Vector2f position);
	void setTarget(sf::Vector2f target);
	void setVelocity(sf::Vector2f velocity);
	void setMass(float mass);
	void setColor(sf::Uint8 r, sf::Uint8 g, sf::Uint8 b, sf::Uint8 a);
	void update(sf::Vector2f steering_force, float dtime, sf::Event* event);
	void draw();
	//bool Bird::loadSpriteTexture(char* filename, int num_frames = 1);
	float getMaxForce() {
		return max_force;
	}
};