#include "Snake.hpp"

#include "../../Math.hpp"

namespace sg
{
	Snake::Snake ( sf::Vector2f const & position )
	:
		position ( position ),
		headSegment ( std::make_unique <SnakeSegment> ( *this ) )
	{
		headSegment->SetPosition ( position );
		headSegment->Grow ( sf::Vector2f { -1.0f, 0.0f } );
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
		headSegment->Update ( delta );
	}

	void Snake::Render ( sf::RenderTarget & target ) const
	{
		headSegment->Render ( target );
	}

	void Snake::Turn ( sf::Vector2f const & )
	{

	}
}