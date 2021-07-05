#include "utility.h"

using namespace std;

Bird::Bird() : sprite_texture(0),
position(sf::Vector2f(200, 200)),
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

Bird::~Bird()
{
	//if (sprite_texture)
	//	SDL_DestroyTexture(sprite_texture);
	if (steering_behaviour)
		delete (steering_behaviour);
}

SteeringBehaviour* Bird::Behaviour()
{
	return steering_behaviour;
}

sf::Vector2f Bird::getPosition()
{
	return position;
}

sf::Vector2f Bird::getTarget()
{
	return target;
}

sf::Vector2f Bird::getVelocity()
{
	return velocity;
}

float Bird::getMaxVelocity()
{
	return max_velocity;
}

void Bird::setPosition(sf::Vector2f _position)
{
	position = _position;
}

void Bird::setTarget(sf::Vector2f _target)
{
	target = _target;
}

void Bird::setVelocity(sf::Vector2f _velocity)
{
	velocity = _velocity;
}

void Bird::setMass(float _mass)
{
	mass = _mass;
}

void Bird::setColor(sf::Uint8 r, sf::Uint8 g, sf::Uint8 b, sf::Uint8 a)
{
	color = { r, g, b, a };
}

void Bird::update(sf::Vector2f steering_force, float dtime, sf::Event* event)
{

	//cout << "agent update:" << endl;

	switch (event->type) {
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

void Bird::draw()
{
	if (draw_sprite)
	{
		sf::CircleShape avatar(5.f, 5);

		avatar.setFillColor(sf::Color::Blue);

		/*Uint32 sprite;

		if (velocity.Length() < 5.0)
			sprite = 1;
		else
			sprite = (int)(SDL_GetTicks() / (-0.1 * velocity.Length() + 250)) % sprite_num_frames;

		SDL_Rect srcrect = { (int)sprite * sprite_w, 0, sprite_w, sprite_h };
		SDL_Rect dstrect = { (int)position.x - (sprite_w / 2), (int)position.y - (sprite_h / 2), sprite_w, sprite_h };
		SDL_Point center = { sprite_w / 2, sprite_h / 2 };
		SDL_RenderCopyEx(TheApp::Instance()->getRenderer(), sprite_texture, &srcrect, &dstrect, orientation + 90, &center, SDL_FLIP_NONE);*/
	}
	else
	{
		//draw_circle(TheApp::Instance()->getRenderer(), (int)position.x, (int)position.y, 15, color.r, color.g, color.b, color.a);
		//SDL_RenderDrawLine(TheApp::Instance()->getRenderer(), (int)position.x, (int)position.y, (int)(position.x + 15 * cos(orientation * DEG2RAD)), (int)(position.y + 15 * sin(orientation * DEG2RAD)));
	}
}

//bool Bird::loadSpriteTexture(char* filename, int _num_frames)
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
