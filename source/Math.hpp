#pragma once

namespace sg
{
	sf::Vector2f GetRightDirection ( sf::Vector2f );
	sf::Vector2f Multiply ( sf::Vector2f const &, sf::Vector2f const & );
	float Project ( sf::Vector2f const & vector, sf::Vector2f const & axis );
	float & Project ( sf::Vector2f & vector, sf::Vector2f const & axis );
	bool ApproximatelyEqual ( sf::Vector2f const &, sf::Vector2f const &, float tolerance );
	float Random ();
}