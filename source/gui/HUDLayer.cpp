#include "HUDLayer.hpp"

namespace sg
{
	HUDLayer::HUDLayer ()
	{
		scoreText.setCharacterSize ( 50 );
		scoreText.setString ( "Hello" );
	}

	void HUDLayer::ProcessEvent ( sf::Event )
	{

	}

	void HUDLayer::Update ( sf::Time )
	{

	}

	void HUDLayer::Render ( sf::RenderTarget & target ) const
	{
		target.draw ( scoreText );
	}
}