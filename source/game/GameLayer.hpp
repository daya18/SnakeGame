#pragma once

#include "../Layer.hpp"
#include "Snake.hpp"

namespace sg
{
	class GameLayer : public Layer
	{
	public:
		GameLayer ();

		void ProcessEvent ( sf::Event ) override;
		void Update ( sf::Time ) override;
		void Render ( sf::RenderTarget & ) const override;

	private:
		Snake snake;
	};
}