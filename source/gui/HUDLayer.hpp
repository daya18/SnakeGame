#pragma once

namespace sg
{
	class Application;
	class GameLayer;

	class HUDLayer
	{
	public:
		HUDLayer ( Application & );

		void ProcessEvent ( sf::Event );
		void Update ( sf::Time );
		void Render ( sf::RenderTarget & ) const;
		
		void SetGameLayer ( GameLayer const & );

	private:
		Application * application;
		GameLayer const * gameLayer;

		sf::Font font;
		sf::Text scoreText;
	};
}