#pragma once

namespace sg
{
	class Snake;

	class SnakeSegment
	{
	public:
		SnakeSegment ( Snake &, sf::Vector2f const & size );

		void Update ( sf::Time const & );
		void Render ( sf::RenderTarget & ) const;

		void SetPosition ( sf::Vector2f const & );
		void SetSize ( sf::Vector2f const & );
		void SetVelocity ( sf::Vector2f const & );
		void SetForward ( sf::Vector2f const & );

		sf::Vector2f GetPosition () const;
		sf::Vector2f GetSize () const;
		sf::Vector2f GetVelocity () const;
		sf::Vector2f GetForward () const;

	private:
		void UpdateMoveDirection ();

		Snake * snake;
		sf::Vector2f position { 0.0f, 0.0f };
		sf::Vector2f size { 50.0f, 50.0f };
		sf::Vector2f velocity { 1.0f, 0.0f };
		sf::Vector2f forward { 1.0f, 0.0f, 0.0f };
		sf::RectangleShape rect;
	};
}