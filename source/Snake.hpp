#pragma once

#include "SnakeSegment.hpp"

namespace sg
{
	class Snake
	{
	public:
		Snake ();

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

		void Turn ( sf::Vector2f direction );

		float segmentSize { 25.0f };
		float moveSpeed { 100.0f };

		sf::Vector2f position { 0.0f, 0.0f };
		sf::Vector2f moveDirection { 1.0f, 0.0f };

		std::vector <SnakeSegment> segments;
		std::vector <TurnPoint> turnPoints;

		friend SnakeSegment;
	};
}