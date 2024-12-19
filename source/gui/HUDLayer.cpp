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
		
		scoreText.move ( application.GetWindow ().getSize ().x * 0.5f, 0.0f );
		scoreText.setFont ( font );
		scoreText.setCharacterSize ( 50 );
	}

	void HUDLayer::ProcessEvent ( sf::Event )
	{

	}

	void HUDLayer::Update ( sf::Time )
	{
		scoreText.setString ( "Score: " + std::to_string (gameLayer->GetScore ()));
		scoreText.setOrigin ( scoreText.getGlobalBounds().getSize ().x * 0.5f, 0.0f);
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