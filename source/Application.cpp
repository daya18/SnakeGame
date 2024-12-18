#include "Application.hpp"

namespace sg
{
	Application::Application ()
	:
		renderWindow { { 1280, 720 }, "SnakeGame" },
		gameLayer { *this },
		hudLayer { *this }
	{
		hudLayer.SetGameLayer ( gameLayer );
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

			gameLayer.ProcessEvent ( event );
			hudLayer.ProcessEvent ( event );
		}
	}

	void Application::Update ()
	{
		sf::Time elapsedTime { updateClock.getElapsedTime () };

		gameLayer.Update ( elapsedTime );
		hudLayer.Update ( elapsedTime );

		updateClock.restart ();
	}

	void Application::Render ()
	{
		renderWindow.clear ();

		gameLayer.Render ( renderWindow );
		hudLayer.Render ( renderWindow );

		renderWindow.display ();
	}
}