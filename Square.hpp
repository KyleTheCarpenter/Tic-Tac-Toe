#pragma once
#ifndef KYLE_SQUARE
#define KYLE_SQUARE
#include <iostream>
#include<SFML/Graphics.hpp>
#include"Setting.hpp"
class Square: public sf::Drawable {

public:											  //enums and Constructor

	enum class								 State				{ On, Off };
	Square(Setting & Settings);

public:											  //getters and mutators

	State						getState()		const			{ return myState; }
	Setting::Turn				getID()			const			{ return myID; }
	sf::Vector2f				getSize()		const			{ return mySquare.getSize(); }
	bool						Highlighted()	const			{ return isColliding; }
	int							getCount()		const			{ return count; }


	void						setState(State state)			{ myState = state; }
	void						setPosition(float x, float y)   { mySquare.setPosition(x, y); }
	void						setID(Setting::Turn t)			{ myID = t; }
	void						setCount()						{ count = 1; }
	void						setColor(sf::Color color)		{ myColor = color; }
	void						lock() { isLocked = true; }
	void						unlock() { isLocked = false; }

public: //public Functions

	void						Reset();
	void						updateSquare();
	void						EventHandler(sf::Event & Event);
	void						update(sf::RenderWindow & rWindow);

private:  //private functions

	virtual void				draw(sf::RenderTarget& target, sf::RenderStates states)const;

private: //private values

	sf::RectangleShape			 mySquare;
	State						 myState;
	sf::Color					 myColor;
	bool						 isLocked;
	bool						 isColliding;
	Setting				&		 rSettings;
	Setting::Turn				 myID;
	int							 count;
	
};


#endif //KYLE_SQUARE