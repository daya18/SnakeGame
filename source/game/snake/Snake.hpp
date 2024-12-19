#pragma once

#include "SnakeSegment.hpp"

namespace sg
{
	class GameLayer;

	class Snake
	{
	public:
		Snake ( GameLayer &, sf::Vector2f const & position );

		void ProcessEvent ( sf::Event );
		void Update ( sf::Time );
		void Render ( sf::RenderTarget & ) const;
		
		void SetSpeed ( float );
		float GetSpeed () const;

		SnakeSegment & GetHeadSegment ();

	private:
		void Turn ( sf::Vector2f const & );

		GameLayer * gameLayer;
		float segmentSize { 30.0f };
		float moveSpeed { 100.0f };

		sf::Vector2f position { 0.0f, 0.0f };
		sf::Vector2f moveDirection { 1.0f, 0.0f };
		float speed { 0.1f };

		std::unique_ptr <SnakeSegment> headSegment;
	};


	inline void Snake::SetSpeed ( float speed ) { this->speed = speed; }
	inline float Snake::GetSpeed () const { return speed; }
	inline SnakeSegment & Snake::GetHeadSegment () { return *headSegment; }
}