#include "SnakeSegment.hpp"

#include "Snake.hpp"
#include "../../Math.hpp"

namespace sg
{
	float const SnakeSegment::size { 25.0f };

	SnakeSegment::SnakeSegment ( Snake & snake )
		: snake ( &snake )
	{
		Layout ();
	}

	void SnakeSegment::Update ( sf::Time const & delta )
	{
		HandleTurns ();

		Move ( snake->GetSpeed () * forward );

		if ( prev )
			prev->Update ( delta );
	}

	void SnakeSegment::Render ( sf::RenderTarget & target ) const
	{
		target.draw ( rectangle );

		if ( prev )
			prev->Render ( target );
	}
	
	SnakeSegment & SnakeSegment::GetTail ()
	{
		if ( !prev )
			return *this;

		return prev->GetTail ();
	}

	SnakeSegment & SnakeSegment::Grow ( sf::Vector2f const & direction )
	{
		if ( !prev )
		{
			prev = std::make_unique <SnakeSegment> ( *snake );
			prev->SetPosition ( position + direction * size );	
			prev->SetForward ( -direction );

			prev->turnPoints = turnPoints;

			if ( prev->GetForward () != forward )
				prev->AddTurnPoint ( { position, prev->GetForward (), forward } );
		}

		return *prev;
	}

	void SnakeSegment::AddTurnPoint ( SnakeTurnPoint const & turnPoint )
	{
		turnPoints.push_back ( turnPoint );

		if ( prev )
			prev->AddTurnPoint ( turnPoint );
	}
	
	void SnakeSegment::SetFillColor ( sf::Color const & color )
	{
		this->fillColor = color;
	}

	void SnakeSegment::SetPosition ( sf::Vector2f const & position )
	{
		this->position = position;
		Layout ();
	}

	void SnakeSegment::SetForward ( sf::Vector2f const & forward )
	{
		this->forward = forward;
	}
	
	sf::FloatRect SnakeSegment::GetGlobalBounds () const
	{
		return rectangle.getGlobalBounds ();
	}

	void SnakeSegment::Move ( sf::Vector2f const & delta )
	{
		SetPosition ( position + delta );
	}
	
	void SnakeSegment::HandleTurns ()
	{
		for ( auto turnPointIt { turnPoints.begin () }; turnPointIt != turnPoints.end (); ++turnPointIt )
		{
			if ( ApproximatelyEqual ( turnPointIt->position, position, 0.5 ) )
			{
				SetPosition ( turnPointIt->position );
				SetForward ( turnPointIt->turnDirection );
				turnPoints.erase ( turnPointIt );
				return;
			}
		}
	}

	void SnakeSegment::Layout ()
	{
		rectangle.setPosition ( position );
		rectangle.setSize ( sf::Vector2f { size, size } );
		rectangle.setFillColor ( fillColor );
	}
}