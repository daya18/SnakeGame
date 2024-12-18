#include "HUDLayer.hpp"

#include "../Application.hpp"

namespace sg
{
	HUDLayer::HUDLayer ( Application & application )
		: application ( & application )
	{
		font.loadFromFile ( "assets/fonts/Roboto/Roboto-Regular.ttf" );
		
		scoreText.setCharacterSize ( 50 );
		scoreText.setString ( "0" );
		scoreText.setFont ( font );
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