#include "GameLayer.hpp"

#include "../Math.hpp"
#include "../Application.hpp"

namespace sg
{
	GameLayer::GameLayer ( Application & application )
		:
		application ( &application ),
		snake ( *this, sf::Vector2f { application.GetWindow ().getSize () } *0.5f )
	{
		GenerateFood ();
	}

	void GameLayer::ProcessEvent ( sf::Event event )
	{
		snake.ProcessEvent ( event );
	}

	void GameLayer::Update ( sf::Time delta )
	{
		snake.Update ( delta );

		if ( snake.GetHeadSegment ().GetGlobalBounds ().intersects ( food.GetGlobalBounds () ) )
		{
			++score;
			GenerateFood ();
			auto & snakeTailSegment { snake.GetHeadSegment ().GetTail () };
			snakeTailSegment.Grow ( -snakeTailSegment.GetForward () );
		}
	}

	void GameLayer::Render ( sf::RenderTarget & target ) const
	{
		snake.Render ( target );
		food.Render ( target );
	}

	void GameLayer::GenerateFood ()
	{
		auto windowSize { sf::Vector2f { application->GetWindow ().getSize () } };
		food.SetPosition ( { Random () * windowSize.x, Random () * windowSize.y } );
	}
}