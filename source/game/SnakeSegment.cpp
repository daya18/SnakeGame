#include "SnakeSegment.hpp"

#include "Snake.hpp"
#include "../Math.hpp"

namespace sg
{
	SnakeSegment::SnakeSegment ( Snake & snake, sf::Vector2f const & size )
	:
		snake ( &snake )
	{
		rect.setFillColor ( sf::Color::Blue );
		SetSize ( size );
	}

	void SnakeSegment::Update ( sf::Time const & deltaTime )
	{
		//UpdateMoveDirection ();

		//rect.move ( velocity * snake->moveSpeed * deltaTime.asSeconds () );
	}

	void SnakeSegment::Render ( sf::RenderTarget & target ) const
	{
		target.draw ( rect );
	}

	void SnakeSegment::SetPosition ( sf::Vector2f const & position )
	{
		this->position = position;
		rect.setPosition ( position );
	}

	void SnakeSegment::SetSize ( sf::Vector2f const & size )
	{
		this->size = size;
		rect.setSize ( size );
	}

	void SnakeSegment::SetVelocity ( sf::Vector2f const & velocity )
	{
		this->velocity = velocity;
	}
	
	void SnakeSegment::SetForward ( sf::Vector2f const & forward )
	{
		this->forward = forward;
	}

	sf::Vector2f SnakeSegment::GetPosition () const
	{
		return position;
	}

	sf::Vector2f SnakeSegment::GetSize () const
	{
		return size;
	}

	sf::Vector2f SnakeSegment::GetVelocity () const
	{
		return velocity;
	}
	
	sf::Vector2f SnakeSegment::GetForward () const
	{
		return forward;
	}

	void SnakeSegment::UpdateMoveDirection ()
	{
		//auto & position { segment.getPosition () };

		//for ( auto turnPointIt { snake->turnPoints.begin () }; turnPointIt != snake->turnPoints.end (); ++ turnPointIt )
		//{
		//	if ( moveDirection == turnPointIt->forwardDirection )
		//	{
		//		if ( ApproximatelyEqual ( position, turnPointIt->position, snake->moveSpeed * 0.005 ) )
		//		{
		//			SetPosition ( turnPointIt->position );
		//			moveDirection = turnPointIt->turnDirection;
		//			
		//			if ( type == Types::tail )
		//			{
		//				snake->turnPoints.erase ( turnPointIt );
		//				break;
		//			}
		//		}
		//	}
		//}
	}
}