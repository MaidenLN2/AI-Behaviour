//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2021 Media Design School
//
// File Name    : 
// Description    : 
// Author   : Lera Blokhina
// Mail     :   valeriia.blokhina@mds.ac.nz
//

#include "utility.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML works!");

	sf::Clock deltaClock;

	State* curr_scene = new StateFlee;

	while (window.isOpen())
	{
		sf::Event event;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		float dtime = deltaClock.restart().asSeconds();

		/* Keyboard events */
		switch (event.type)
		{
		case sf::Event::KeyPressed:
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
			{
				delete(curr_scene);
				curr_scene = new StateFlee;
				//app->setWindowTitle(curr_scene->getTitle());
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
			{
				delete(curr_scene);
				curr_scene = new StatePursue;
				//app->setWindowTitle(curr_scene->getTitle());
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
			{
				delete(curr_scene);
				curr_scene = new StateArrival;
				//app->setWindowTitle(curr_scene->getTitle());
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4))
			{
				delete(curr_scene);
				curr_scene = new StateFlocking;
				//app->setWindowTitle(curr_scene->getTitle());
			}
			//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num5))
			//{
			//	delete(curr_scene);
			//	curr_scene = new SceneKinematicEvade;
			//	//app->setWindowTitle(curr_scene->getTitle());
			//}
			//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num6))
			//{
			//	delete(curr_scene);
			//	curr_scene = new StateWander;
			//	//app->setWindowTitle(curr_scene->getTitle());
			//}
			//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num7))
			//{
			//	delete(curr_scene);
			//	curr_scene = new ScenePathFinding;
			//	//app->setWindowTitle(curr_scene->getTitle());
			//}

			//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num8))
			//{
			//	delete(curr_scene);
			//	curr_scene = new SceneCollisionAvoidance;
			//	//app->setWindowTitle(curr_scene->getTitle());
			//}
			//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num9))
			//{
			//	delete(curr_scene);
			//	curr_scene = new Separation;
			//	//app->setWindowTitle(curr_scene->getTitle());
			//}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)))
			{
				window.close();
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
			{
				//app->setFullScreen();
			}
			break;
		case sf::Event::Closed:
			window.close();
			break;
		}

		window.clear();
		curr_scene->update(dtime, &event);
		curr_scene->draw();
		window.display();

      // case buttons 1 2 3 4 5 6 pressed

	}


	return 0;
}

//int main()
//{
//	
//    sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML works!");
//	//sf::CircleShape triangle(20, 3);
//	//triangle.setFillColor(sf::Color::Yellow);
//
//    //// set the absolute position of the entity
//    //triangle.setPosition(10.f, 50.f);
//
//    //// move the entity relatively to its current position
//    //triangle.move(5.f, 5.f);
//
//    // retrieve the absolute position of the entity
//    //sf::Vector2f position = triangle.getPosition(); // = (15, 55)
//
//    while (window.isOpen())
//    {
//        sf::Event event;
//        while (window.pollEvent(event))
//        {
//            if (event.type == sf::Event::Closed)
//                window.close();
//        }
//
//        window.clear();
//        //window.draw(triangle);
//        window.display();
//
//        // case buttons 1 2 3 4 5 6 pressed
//    }
//
//	return 0;
//}
//
//int main()
//{
//	bool quit = false;
//	
//	State* curr_scene = new StateFlee;
//
//	while (!quit)
//	{
//
//		sf::Event event;
//		while (window.pollEvent(event))
//		{
//			if (event.type == sf::Event::Closed)
//				window.close();
//		}
//
//		float dtime = (float)(SDL_GetTicks() - last_update) / 1000.0f;
//		last_update = (float)SDL_GetTicks();
//		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); //TODO set bg color
//		SDL_RenderClear(renderer);
//		scene->update(dtime, &event);
//		scene->draw();
//		SDL_RenderPresent(renderer);
//		return event;
//
//		/* Keyboard events */
//		switch (event.type)
//		{
//		case sf::Event::KeyPressed:
//			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
//			{
//				delete(curr_scene);
//				curr_scene = new SceneKinematicSeek;
//				//app->setWindowTitle(curr_scene->getTitle());
//			}
//			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
//			{
//				delete(curr_scene);
//				curr_scene = new SceneKinematicFlee;
//				//app->setWindowTitle(curr_scene->getTitle());
//			}
//			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
//			{
//				delete(curr_scene);
//				curr_scene = new SceneKinematicArrive;
//				//app->setWindowTitle(curr_scene->getTitle());
//			}
//			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4))
//			{
//				delete(curr_scene);
//				curr_scene = new SceneKinematicPursue;
//				//app->setWindowTitle(curr_scene->getTitle());
//			}
//			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num5))
//			{
//				delete(curr_scene);
//				curr_scene = new SceneKinematicEvade;
//				//app->setWindowTitle(curr_scene->getTitle());
//			}
//			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num6))
//			{
//				delete(curr_scene);
//				curr_scene = new SceneKinematicWander;
//				//app->setWindowTitle(curr_scene->getTitle());
//			}
//			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num7))
//			{
//				delete(curr_scene);
//				curr_scene = new ScenePathFinding;
//				//app->setWindowTitle(curr_scene->getTitle());
//			}
//
//			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num8))
//			{
//				delete(curr_scene);
//				curr_scene = new SceneCollisionAvoidance;
//				//app->setWindowTitle(curr_scene->getTitle());
//			}
//			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num9))
//			{
//				delete(curr_scene);
//				curr_scene = new Separation;
//				//app->setWindowTitle(curr_scene->getTitle());
//			}
//			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)))
//			{
//				quit = true;
//			}
//			if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
//			{
//				//app->setFullScreen();
//			}
//			break;
//		case sf::Event::Closed:
//			quit = true;
//			break;
//		}
//
//	}
//
//	return 0;
//}

