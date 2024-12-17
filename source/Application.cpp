#include "Application.hpp"

namespace sg
{
	Application::Application ()
		: renderWindow { { 1280, 720 }, "SnakeGame" }
	{
	}

	void Application::Run ()
	{
		updateClock.restart ();

		while ( ! quit )
		{
			ProcessEvents ();
			Update ();
			Render ();
		}
	}

	void Application::ProcessEvents ()
	{
		sf::Event event;

		while ( renderWindow.pollEvent ( event ) )
		{
			if ( event.type == sf::Event::Closed )
				quit = true;

			for ( auto & layer : layers )
				layer->ProcessEvent ( event );
		}
	}

	void Application::Update ()
	{
		for ( auto & layer : layers )
			layer->Update ( updateClock.getElapsedTime () );
		
		updateClock.restart ();
	}

	void Application::Render ()
	{
		renderWindow.clear ();

		for ( auto const & layer : layers )
			layer->Render ( renderWindow );

		renderWindow.display ();
	}
}