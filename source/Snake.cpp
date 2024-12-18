#include "Snake.hpp"

namespace sg
{
	Snake::Snake ()
	{	
		int segmentCount { 4 };

		// Create body segments 
		for ( int segmentIndex { 0 }; segmentIndex < segmentCount; ++segmentIndex )
		{
			sf::Vector2f segmentPosition { segmentIndex * segmentSize, 0.0f };

			auto segmentType {
				  segmentIndex == 0 ? SnakeSegment::Types::tail
				: segmentIndex == segmentCount - 1 ? SnakeSegment::Types::head
				: SnakeSegment::Types::body
			};

			segments.emplace_back ( SnakeSegment { *this, segmentType, segmentPosition, { 1.0f, 0.0f } } );
		}
	}

	void Snake::ProcessEvent ( sf::Event event )
	{
		if ( event.type == sf::Event::KeyPressed )
		{
			switch ( event.key.code )
			{
			case sf::Keyboard::W: Turn ( {  0.0f, -1.0f } ); break;
			case sf::Keyboard::A: Turn ( { -1.0f,  0.0f } ); break;
			case sf::Keyboard::S: Turn ( {  0.0f,  1.0f } ); break;
			case sf::Keyboard::D: Turn ( {  1.0f,  0.0f } ); break;
			}
		}
	}

	void Snake::Update ( sf::Time delta )
	{
		for ( auto & segment : segments )
			segment.Update ( delta );
	}

	void Snake::Render ( sf::RenderTarget & target ) const
	{
		for ( auto const & segment : segments )
			segment.Render ( target );
	}

	void Snake::Turn ( sf::Vector2f direction )
	{
		if ( direction == moveDirection || direction == -moveDirection )
			return;

		moveDirection = direction;

		segments.back ().Turn ( moveDirection );
	}
}