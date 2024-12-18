#include "Application.hpp"

#include "game/GameLayer.hpp"
#include "gui/HUDLayer.hpp"

namespace sg
{
	Application::Application ()
		: renderWindow { { 1280, 720 }, "SnakeGame" }
	{
		layers.push_back ( std::make_unique <GameLayer> () );
		layers.push_back ( std::make_unique <HUDLayer> ( *this ) );
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