#include "Snake.hpp"

#include "../../Math.hpp"

namespace sg
{
	Snake::Snake ( GameLayer & gameLayer, sf::Vector2f const & position )
	:
		gameLayer ( &gameLayer ),
		position ( position ),
		headSegment ( std::make_unique <SnakeSegment> ( *this ) )
	{
		headSegment->SetPosition ( position );
		headSegment->SetFillColor ( { 67, 53, 167 } );

		headSegment -> 
			 Grow ( sf::Vector2f { -1.0f, 0.0f } )
			.Grow ( sf::Vector2f { 0.0f, 1.0f } );
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

	void Snake::Turn ( sf::Vector2f const & direction )
	{
		if ( direction == headSegment->GetForward () || direction == -headSegment->GetForward () )
			return;

		headSegment->AddTurnPoint ( { headSegment->GetPosition (), headSegment->GetForward (), direction } );
	}
}