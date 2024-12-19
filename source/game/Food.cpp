#include "Food.hpp"

namespace sg
{
	Food::Food ()
	{
		texture.loadFromFile ( "assets/images/apple.png" );
		food.setTexture ( texture, true );
		food.setScale ( 2.0f, 2.0f );
	}

	void Food::Render ( sf::RenderTarget & target ) const
	{
		target.draw ( food );
	}

	sf::FloatRect Food::GetGlobalBounds () const
	{
		return food.getGlobalBounds ();
	}

	void Food::SetPosition ( sf::Vector2f const & position )
	{
		food.setPosition ( position );
	}
}