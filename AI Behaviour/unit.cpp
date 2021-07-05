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

using namespace std;

Unit::Unit() : //sprite_texture(0),
position(sf::Vector2f(100, 100)),
target(sf::Vector2f(1000, 100)),
velocity(sf::Vector2f(0, 0)),
mass(0.1f),
max_force(50),
max_velocity(200),
orientation(0),
color({ 255,255,255,255 }),
sprite_num_frames(0),
sprite_w(0),
sprite_h(0),
draw_sprite(false)
{
	steering_behaviour = new SteeringBehaviour;
}

Unit::~Unit()
{
	//if (sprite_texture)
	//	SDL_DestroyTexture(sprite_texture);
	if (steering_behaviour)
		delete (steering_behaviour);
}



SteeringBehaviour* Unit::Behaviour()
{
	return steering_behaviour;
}

sf::Vector2f Unit::getPosition()
{
	return position;
}

sf::Vector2f Unit::getTarget()
{
	return target;
}

sf::Vector2f Unit::getVelocity()
{
	return velocity;
}

float Unit::getMaxVelocity()
{
	return max_velocity;
}

void Unit::setPosition(sf::Vector2f _position)
{
	position = _position;
}

void Unit::setTarget(sf::Vector2f _target)
{
	target = _target;
}

void Unit::setVelocity(sf::Vector2f _velocity)
{
	velocity = _velocity;
}

void Unit::setMass(float _mass)
{
	mass = _mass;
}

void Unit::setColor(sf::Uint8 r, sf::Uint8 g, sf::Uint8 b, sf::Uint8 a)
{
	color = { r, g, b, a };
}
void Unit::setMaxVelocity(sf::Vector2f mv)
{
	max_velocity = Length(mv);
}

void Unit::update(sf::Vector2f steering_force, float dtime, sf::Event* event)
{

	//cout << "agent update:" << endl;

	switch (event->type)
	{
		/* Keyboard & Mouse events */
	case sf::Event::KeyPressed:
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			draw_sprite = !draw_sprite;
		break;
	default:
		break;
	}

	sf::Vector2f acceleration = steering_force / mass;
	velocity = velocity + acceleration * dtime;
	Truncate(velocity, max_velocity);

	position = position + velocity * dtime;


	// Update orientation
	orientation = (float)(atan2(velocity.y, velocity.x) * RAD2DEG);

	//// Trim position values to window size
	//if (position.x < 0) position.x = TheApp::Instance()->getWinSize().x;
	//if (position.y < 0) position.y = TheApp::Instance()->getWinSize().y;
	//if (position.x > TheApp::Instance()->getWinSize().x) position.x = 0;
	//if (position.y > TheApp::Instance()->getWinSize().y) position.y = 0;
}

void Unit::draw()
{
	if (draw_sprite)
	{
		sf::CircleShape avatar(5.f, 4);

		avatar.setFillColor(sf::Color::Yellow);



		//Uint32 sprite;

		//if (velocity.Length() < 5.0)
		//	sprite = 1;
		//else
		//	sprite = (int)(SDL_GetTicks() / (-0.1 * velocity.Length() + 250)) % sprite_num_frames;

		//SDL_Rect srcrect = { (int)sprite * sprite_w, 0, sprite_w, sprite_h };
		//SDL_Rect dstrect = { (int)position.x - (sprite_w / 2), (int)position.y - (sprite_h / 2), sprite_w, sprite_h };
		//SDL_Point center = { sprite_w / 2, sprite_h / 2 };
		//SDL_RenderCopyEx(TheApp::Instance()->getRenderer(), sprite_texture, &srcrect, &dstrect, orientation + 90, &center, SDL_FLIP_NONE);
	}
	else
	{
		//draw_circle(TheApp::Instance()->getRenderer(), (int)position.x, (int)position.y, 15, color.r, color.g, color.b, color.a);
		//SDL_RenderDrawLine(TheApp::Instance()->getRenderer(), (int)position.x, (int)position.y, (int)(position.x + 15 * cos(orientation * DEG2RAD)), (int)(position.y + 15 * sin(orientation * DEG2RAD)));
	}
}

//bool Unit::loadSpriteTexture(char* filename, int _num_frames)
//{
//	if (_num_frames < 1) return false;
//
//	SDL_Surface* image = IMG_Load(filename);
//	if (!image) {
//		cout << "IMG_Load: " << IMG_GetError() << endl;
//		return false;
//	}
//	sprite_texture = SDL_CreateTextureFromSurface(TheApp::Instance()->getRenderer(), image);
//
//	sprite_num_frames = _num_frames;
//	sprite_w = image->w / sprite_num_frames;
//	sprite_h = image->h;
//	draw_sprite = true;
//
//	if (image)
//		SDL_FreeSurface(image);
//
//	return true;
//}
