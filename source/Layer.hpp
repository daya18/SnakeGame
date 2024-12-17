#pragma once

namespace sg
{
	class Layer
	{
	public:
		virtual void ProcessEvent ( sf::Event );
		virtual void Update ( sf::Time );
		virtual void Render ( sf::RenderTarget & ) const;

		void SetEnabled ( bool );
		bool GetEnabled () const;

	private:
		bool enabled { true };
	};



	// Implementation
	inline void Layer::ProcessEvent ( sf::Event )
	{
	}

	inline void Layer::Update ( sf::Time )
	{
	}

	inline void Layer::Render ( sf::RenderTarget & ) const
	{
	}

	inline void Layer::SetEnabled ( bool enabled )
	{
		this->enabled = enabled;
	}

	inline bool Layer::GetEnabled () const
	{
		return enabled;
	}
}