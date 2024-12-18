#include "HUDLayer.hpp"

#include "../Application.hpp"
#include "../game/GameLayer.hpp"

namespace sg
{
	HUDLayer::HUDLayer ( Application & application )
	: 
		application ( & application )
	{
		font.loadFromFile ( "assets/fonts/Roboto/Roboto-Regular.ttf" );
		
		scoreText.setFont ( font );
		scoreText.setCharacterSize ( 50 );
	}

	void HUDLayer::ProcessEvent ( sf::Event )
	{

	}

	void HUDLayer::Update ( sf::Time )
	{
		scoreText.setString ( std::to_string ( gameLayer->GetScore () ) );
	}

	void HUDLayer::Render ( sf::RenderTarget & target ) const
	{
		target.draw ( scoreText );
	}

	void HUDLayer::SetGameLayer ( GameLayer const & gameLayer )
	{
		this->gameLayer = & gameLayer;
	}
}