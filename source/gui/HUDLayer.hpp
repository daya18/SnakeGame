#pragma once

#include "../Layer.hpp"

namespace sg
{
	class Application;

	class HUDLayer : public Layer
	{
	public:
		HUDLayer ( Application & );

		void ProcessEvent ( sf::Event ) override;
		void Update ( sf::Time ) override;
		void Render ( sf::RenderTarget & ) const override;

	private:
		Application * application;
		sf::Font font;
		sf::Text scoreText;
	};
}