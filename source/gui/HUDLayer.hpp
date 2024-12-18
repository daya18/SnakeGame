#pragma once

#include "../Layer.hpp"

namespace sg
{
	class HUDLayer : public Layer
	{
	public:
		HUDLayer ();

		void ProcessEvent ( sf::Event ) override;
		void Update ( sf::Time ) override;
		void Render ( sf::RenderTarget & ) const override;

	private:
		sf::Text scoreText;
	};
}