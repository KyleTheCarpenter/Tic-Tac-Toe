#pragma once
#ifndef KYLE_Grid
#define KYLE_Grid
#include <iostream>
#include<SFML/Graphics.hpp>
#include"Square.hpp"
#include "Setting.hpp"
class Grid : public sf::Drawable {

public: //constructor and enum
	enum class								Turn							 { one, two };
	Grid(Setting & Settings);

public: //getters and mutators
	
	Square				&					getSquare(int which)				{ return myGrid[which]; }
	Turn									getTurn()				const		{ return whosTurn; }
	bool									getPause()				const		{ return pause; }
	int										getTally()				const		{ return tally; }

	void									setPosition(float x, float y)		{ myGrid[0].setPosition(x, y); }
	void									setTurn(Turn turn)					{ whosTurn = turn; }
	void									setPause(bool b)					{ pause = b; }
	
public: //public functions

	void									updateSquare(int which);
	void									updateGrid();
	void									EventHandler(sf::Event& Event);
	void									update(sf::RenderWindow& rWindow);
	void									ProcessResults();
	void									End();
	void									Clear();
	
private://private functions

	virtual void							draw(sf::RenderTarget& target, sf::RenderStates states)const;

private: //private values

	std::vector<Square>						myGrid;
	Square									square;
	int										i;
	int										j;
	float									valX;
	float									valY;
	Turn									whosTurn;
	
	Setting					&				rSettings;
	bool									pause;
	int										tally;
};


#endif //KYLE_Grid