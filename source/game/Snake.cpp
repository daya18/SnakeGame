#include "Snake.hpp"

#include "../Math.hpp"

namespace sg
{
	Snake::Snake ()
	{	
		segments.emplace_back ( *this, sf::Vector2f { segmentSize, segmentSize } );
		segments.emplace_back ( *this, sf::Vector2f { segmentSize, segmentSize } );
		segments.emplace_back ( *this, sf::Vector2f { segmentSize, segmentSize } );
		segments.emplace_back ( *this, sf::Vector2f { segmentSize, segmentSize } );
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
	
	void Snake::PositionSegments ()
	{
		sf::Vector2f position { this->position };

		for ( auto & segment : segments )
		{
			position += Multiply ( -segment.GetForward (), segment.GetSize () * 0.5f );
			segment.SetPosition ( position );
			position += Multiply ( -segment.GetForward (), segment.GetSize () * 0.5f );
		}
	}

	void Snake::Turn ( sf::Vector2f direction )
	{
		//if ( direction == moveDirection || direction == -moveDirection )
		//	return;

		//moveDirection = direction;

		//segments.back ().Turn ( moveDirection );
	}
}