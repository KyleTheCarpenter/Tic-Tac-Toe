#include "FontList.hpp"

void FontList::load(Fonts::ID id, const std::string& filename)
{
	std::unique_ptr<sf::Font> Font(new sf::Font());
	if (!Font->loadFromFile(filename))
		throw std::runtime_error("FontList::load-Failed to load " + filename);

	auto inserted = mFontMap.insert(std::make_pair(id, std::move(Font)));
	assert(inserted.second);
}

sf::Font& FontList::get(Fonts::ID id)
{
	auto found = mFontMap.find(id);

	assert(found != mFontMap.end());
	return *found->second;
}

const sf::Font& FontList::get(Fonts::ID id) const
{
	auto found = mFontMap.find(id);
	return *found->second;
}
