#pragma once

namespace sg
{
	class Food
	{
	public:
		Food ( sf::Vector2f const & position );

		void Render ( sf::RenderTarget & ) const;

	private:
		sf::RectangleShape food;
	};
}