#pragma once

#ifndef KYLE_MenuScene
#define KYLE_MenuScene
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Setting.hpp"
#include "TextureList.hpp"
#include "FontList.hpp"
#include "MenuButton.hpp"
#include "Scene.hpp"

class MenuScene {
public:								//constructors
	MenuScene();
public:						    	//setters n getters


public:							    //public functions
	void			 run(TextureList& TextureRenderer, FontList& FontRenderer);

	//private functions
public:
	void			 mainEventHandler(sf::Event& rEvent);
	void			 mainDraw(sf::RenderWindow& rWindow);
	void			 mainUpdate(sf::RenderWindow& rWindow, Setting& Settings);
	

	//private values
private:

	MenuButton       ExitButton;
	MenuButton       onePlayerButton;
	MenuButton       twoPlayerButton;
	sf::Sprite		 myTitle;

};

#endif // !KYLE_MenuScene
