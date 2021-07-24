#pragma once

#ifndef KYLE_TWOPLAYERSCENE
#define KYLE_TWOPLAYERSCENE
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Setting.hpp"
#include "TextureList.hpp"
#include "FontList.hpp"
#include "MenuButton.hpp"
#include "Scene.hpp"
#include "Grid.hpp"
#include "ScoreCard.hpp"

class TwoPlayerScene  {
public:			 //constructors
	TwoPlayerScene(Setting & Setting);

public:			 //public functions
	void			 run(TextureList& TextureRenderer, FontList& FontRenderer);

				//private functions
public:
	void			 mainEventHandler(sf::Event& rEvent);
	void			 mainDraw(sf::RenderWindow& rWindow);
	void			 mainUpdate(sf::RenderWindow& rWindow, Setting& Settings);

				//private values
private:

	MenuButton       ExitButton;
	MenuButton		 RetryButton;
	int				 turn;
	Grid			 myGrid;
	ScoreCard		 scoreCard;
	
};

#endif // !KYLE_TWOPLAYERSCENE
