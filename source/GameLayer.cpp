#include "GameLayer.hpp"

namespace sg
{
	GameLayer::GameLayer ()
	{
	}

	void GameLayer::ProcessEvent ( sf::Event event )
	{
		snake.ProcessEvent ( event );
	}

	void GameLayer::Update ( sf::Time delta )
	{
		snake.Update ( delta );
	}
	
	void GameLayer::Render ( sf::RenderTarget & target ) const
	{
		snake.Render ( target );
	}
}