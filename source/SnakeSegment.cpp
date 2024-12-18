#include "SnakeSegment.hpp"

#include "Snake.hpp"
#include "Math.hpp"

namespace sg
{
	SnakeSegment::SnakeSegment ( Snake & snake, Types type, sf::Vector2f const & position, sf::Vector2f const & moveDirection )
		:
		snake ( &snake ),
		type ( type ),
		moveDirection ( moveDirection )
	{
		segment.setFillColor ( sf::Color::Blue );

		segment.setOutlineColor ( sf::Color::Yellow );
		segment.setOutlineThickness ( 5.0f );

		SetPosition ( position );
		SetSize ( { snake.segmentSize, snake.segmentSize } );
	}

	void SnakeSegment::Update ( sf::Time const & delta )
	{
		UpdateMoveDirection ();

		segment.move ( moveDirection * snake->moveSpeed );
	}

	void SnakeSegment::Render ( sf::RenderTarget & target ) const
	{
		target.draw ( segment );
	}

	void SnakeSegment::Turn ( sf::Vector2f direction )
	{
		if ( type != Types::head )
			return;

		// Add a turn point to make other segments follow;
		snake->turnPoints.push_back ( { segment.getPosition (), moveDirection, direction } );

		moveDirection = direction;
	}

	void SnakeSegment::SetPosition ( sf::Vector2f const & position )
	{
		segment.setPosition ( position );
	}

	void SnakeSegment::SetSize ( sf::Vector2f const & size )
	{
		segment.setSize ( size );
	}

	void SnakeSegment::UpdateMoveDirection ()
	{
		auto & position { segment.getPosition () };

		for ( auto turnPointIt { snake->turnPoints.begin () }; turnPointIt != snake->turnPoints.end (); ++ turnPointIt )
		{
			if ( moveDirection == turnPointIt->forwardDirection )
			{
				auto positionF { Project ( position, moveDirection ) };
				auto turnPointPositionF { Project ( turnPointIt->position, moveDirection ) };

				if ( positionF >= turnPointPositionF && positionF <= turnPointPositionF + snake->moveSpeed )
				{
					moveDirection = turnPointIt->turnDirection;

					if ( type == Types::tail )
					{
						snake->turnPoints.erase ( turnPointIt );
						break;
					}
				}
			}
		}
	}
}