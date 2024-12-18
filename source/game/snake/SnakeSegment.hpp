#pragma once

namespace sg
{
	class Snake;

	class SnakeSegment
	{
	public:
		SnakeSegment ( Snake & );

		void Update ( sf::Time const & );
		void Render ( sf::RenderTarget & ) const;

		SnakeSegment & Grow ( sf::Vector2f const & );

		void SetPosition ( sf::Vector2f const & );
		void SetForward ( sf::Vector2f const & );
		void Move ( sf::Vector2f const & );

		sf::Vector2f GetPosition () const;
		sf::Vector2f GetForward () const;

	private:
		void Layout ();

		static float const size;

		Snake * snake;

		sf::Vector2f position	{ 0.0f, 0.0f };
		sf::Vector2f forward	{ 1.0f, 0.0f };
		
		sf::RectangleShape rectangle;

		std::unique_ptr <SnakeSegment> prev { nullptr };
		std::unique_ptr <SnakeSegment> next { nullptr };
	};



	inline sf::Vector2f SnakeSegment::GetPosition () const { return position; }
	inline sf::Vector2f SnakeSegment::GetForward () const { return forward; }
}