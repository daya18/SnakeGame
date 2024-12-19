#pragma once

namespace sg
{
	class Food
	{
	public:
		Food ();

		void SetPosition ( sf::Vector2f const & position );
		void Render ( sf::RenderTarget & ) const;
		sf::FloatRect GetGlobalBounds () const;

	private:
		sf::Texture texture;
		sf::Sprite food;
	};
}