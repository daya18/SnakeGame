#pragma once

#include "SnakeSegment.hpp"

namespace sg
{
	class Snake
	{
	public:
		Snake ( sf::Vector2f const & position );

		void ProcessEvent ( sf::Event );
		void Update ( sf::Time );
		void Render ( sf::RenderTarget & ) const;

	private:
		struct TurnPoint
		{
			sf::Vector2f position;
			sf::Vector2f forwardDirection;
			sf::Vector2f turnDirection;
		};

		void Turn ( sf::Vector2f const & );

		float segmentSize { 30.0f };
		float moveSpeed { 100.0f };

		sf::Vector2f position { 0.0f, 0.0f };
		sf::Vector2f moveDirection { 1.0f, 0.0f };

		std::unique_ptr <SnakeSegment> headSegment;
		std::vector <TurnPoint> turnPoints;
	};
}