#include "Math.hpp"

namespace sg
{
	sf::Vector2f GetRightDirection ( sf::Vector2f direction )
	{
		if ( direction == sf::Vector2f { 0.0f, -1.0f } )
			return sf::Vector2f { 1.0f, 0.0f };

		if ( direction == sf::Vector2f { 1.0f, 0.0f } )
			return sf::Vector2f { 0.0f, 1.0f };

		if ( direction == sf::Vector2f { 0.0f, 1.0f } )
			return sf::Vector2f { -1.0f, 0.0f };

		if ( direction == sf::Vector2f { -1.0f, 0.0f } )
			return sf::Vector2f { 0.0f, 1.0f };
	}

	sf::Vector2f Multiply ( sf::Vector2f const & l, sf::Vector2f const & r )
	{
		return { l.x * r.x, l.y * r.y };
	}

	float Project ( sf::Vector2f const & vector, sf::Vector2f const & axis )
	{
		auto axisAlignedVector { Multiply ( vector, axis ) };
		return axisAlignedVector.x == 0.0f ? axisAlignedVector.y : axisAlignedVector.x;
	}
}