#pragma once
#ifndef KYLE_MENUBUTTON
#define KYLE_MENUBUTTON
#include <SFML/Graphics.hpp>
#include <iostream>

class MenuButton:public sf::Drawable {

public:				//enum and constructor
	enum class					State							{Null,Off,ON};
	MenuButton(std::string Name);

public:				//Getters and mutators
	bool						getActivated()					{ return activated; }
	
	void						setState(State state)			{ myState = state; }
	void						setPosition(float x, float y)	{ mySprite.setPosition(x, y); setTextPosition(); }
	void						Deactivate()					{ activated = false; }

public: //public functions
	void						getResources(sf::Texture& t, sf::Font& f);
	void						EventHandle(sf::Event & Event);
	void						update(sf::RenderWindow & window);
	
private://private functions
	virtual void				draw(sf::RenderTarget& target, sf::RenderStates states)const;
	void						setTextPosition();

private: //private values
	sf::Sprite					mySprite;
	sf::Text					myText;
	State						myState;
	bool						activated;
	sf::Vector2f				startPosition;
};
#endif // !KYLE_MENUBUTTON
