#pragma once

#include "game/GameLayer.hpp"
#include "gui/HUDLayer.hpp"

namespace sg
{
	class Application
	{
	public:
		Application ();

		void Run ();

		sf::Window const & GetWindow () const;

	private:
		void ProcessEvents ();
		void Update ();
		void Render ();

		sf::RenderWindow renderWindow;
		bool quit { false };
		sf::Clock updateClock;
		GameLayer gameLayer;
		HUDLayer hudLayer;
	};



	// Implementation
	inline sf::Window const & Application::GetWindow () const { return renderWindow; }
}