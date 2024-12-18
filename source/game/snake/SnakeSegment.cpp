#include "SnakeSegment.hpp"

#include "Snake.hpp"

namespace sg
{
	float const SnakeSegment::size { 50.0f };

	SnakeSegment::SnakeSegment ( Snake & snake )
		: snake ( & snake )
	{
		Layout ();
	}
	
	void SnakeSegment::Update ( sf::Time const & delta )
	{
	}

	void SnakeSegment::Render ( sf::RenderTarget & target ) const
	{
		target.draw ( rectangle );

		if ( prev )
			prev->Render ( target );
	}
	
	SnakeSegment & SnakeSegment::Grow ( sf::Vector2f const & direction)
	{
		if ( ! prev )
		{
			prev = std::make_unique <SnakeSegment> ( *snake );
			prev->SetPosition ( position + direction * size );
		}

		return *prev;
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
	
	void SnakeSegment::Move ( sf::Vector2f const & delta )
	{
		SetPosition ( position + delta );
	}

	void SnakeSegment::Layout ()
	{
		rectangle.setPosition ( position );
		rectangle.setSize ( sf::Vector2f { size, size } );
	}
}