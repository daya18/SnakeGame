#pragma once

#include "snake/Snake.hpp"
#include "Food.hpp"

namespace sg
{
	class Application;

	class GameLayer
	{
	public:
		GameLayer ( Application & );

		void ProcessEvent ( sf::Event );
		void Update ( sf::Time );
		void Render ( sf::RenderTarget & ) const;

		int GetScore () const;
		Food & GetFood ();

	private:
		void GenerateFood ();

		Application * application;

		int score { 0 };
		Snake snake;
		Food food;
	};



	// Implementation
	inline int GameLayer::GetScore () const { return score; }
}