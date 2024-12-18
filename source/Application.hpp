#pragma once

#include "Layer.hpp"

namespace sg
{
	class Application
	{
	public:
		Application ();

		void Run ();

		
	private:
		void ProcessEvents ();
		void Update ();
		void Render ();

		sf::RenderWindow renderWindow;
		bool quit { false };
		sf::Clock updateClock;
		std::vector <std::unique_ptr <Layer>> layers;
	};
}