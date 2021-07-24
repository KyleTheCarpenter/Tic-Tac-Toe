#pragma once
#ifndef KYLE_FontLIST
#define KYLE_FontLIST


#include <iostream>
#include <map>
#include <SFML/Graphics.hpp>
#include <cassert> 

namespace Fonts
{
	enum class ID {MenuFont };
}

class FontList
{
public:

	void load(Fonts::ID id, const std::string& filename);
	sf::Font& get(Fonts::ID id);
	const sf::Font& get(Fonts::ID id) const;
private:
	std::map<Fonts::ID, std::unique_ptr<sf::Font>>mFontMap;
};

#endif // !KYLE_FontLIST
