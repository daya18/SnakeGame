#pragma once

namespace sg
{
	class Snake;

	class SnakeSegment
	{
	public:
		enum class Types { head, body, tail };

		SnakeSegment ( Snake &, Types type, sf::Vector2f const & position, sf::Vector2f const & moveDirection );

		void Update ( sf::Time const & );
		void Render ( sf::RenderTarget & ) const;

		void Turn ( sf::Vector2f direction );

	private:
		void SetPosition ( sf::Vector2f const & );
		void SetSize ( sf::Vector2f const & );
		void UpdateMoveDirection ();

		Snake * snake;
		Types type;
		sf::Vector2f moveDirection;
		sf::CircleShape segment;
	};
}