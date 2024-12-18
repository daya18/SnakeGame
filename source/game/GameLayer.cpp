#include "GameLayer.hpp"

#include "../Math.hpp"
#include "../Application.hpp"

namespace sg
{
	GameLayer::GameLayer ( Application & application )
	: 
		application ( & application ),
		snake ( sf::Vector2f { application.GetWindow ().getSize () } * 0.5f ),
		food { { Random () * application.GetWindow ().getSize ().x, Random () * application.GetWindow ().getSize ().y } }
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
		food.Render ( target );
	}
}