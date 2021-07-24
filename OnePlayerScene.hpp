#pragma once

#ifndef KYLE_ONEPLAYERSCENE
#define KYLE_ONEPLAYERSCENE
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics.hpp>
#include "Setting.hpp"
#include "TextureList.hpp"
#include "FontList.hpp"
#include "MenuButton.hpp"
#include "Scene.hpp"
#include "Grid.hpp"
#include "ScoreCard.hpp"

class OnePlayerScene {
public:								//constructors
						 OnePlayerScene(Setting& Setting);
 
public:							    //public functions
	void				 run(TextureList& TextureRenderer, FontList& FontRenderer);
									
public:								//private functions
	void				 mainEventHandler(sf::Event& rEvent, Setting& Settings);
	void				 mainDraw(sf::RenderWindow& rWindow);
	void				 mainUpdate(sf::RenderWindow& rWindow, Setting& Settings);

	void				 restartClock() { clock.restart(); }
	void				 ComputerMove(Setting& Settings);

	
private:					//private values

	MenuButton			ExitButton;
	MenuButton			RetryButton;

	int					turn;
	int					computerChoice;

	Grid				myGrid;
	ScoreCard			scoreCard;

	sf::Clock			clock;
	sf::Time			time;
	bool				once;

};

#endif // !KYLE_ONEPLAYERSCENE
