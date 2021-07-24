#pragma once
#ifndef KYLE_TEXTURELIST
#define KYLE_TEXTURELIST


#include <iostream>
#include <map>
#include <SFML/Graphics.hpp>
#include <cassert> 

	namespace Textures
	{
		enum class ID {BG,ButtonBox,MenuButton,Title };
	}

	class TextureList
	{
	public:

		void load(Textures::ID id, const std::string& filename);

		sf::Texture& get(Textures::ID id);

		const sf::Texture& get(Textures::ID id) const;

	private:
		std::map<Textures::ID, std::unique_ptr<sf::Texture>>mTextureMap;
	};

#endif // !KYLE_TEXTURELIST
