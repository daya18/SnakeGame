#include "Food.hpp"

namespace sg
{
	Food::Food ( sf::Vector2f const & position )
	{
		food.setSize ( { 50.0f, 50.0f } );
		food.setPosition ( position );
		food.setFillColor ( sf::Color::Magenta );
	}

	void Food::Render ( sf::RenderTarget & target ) const
	{
		target.draw ( food );
	}
}