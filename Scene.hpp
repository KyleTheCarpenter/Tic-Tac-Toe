#pragma once

#ifndef KYLE_Scene
#define KYLE_Scene
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Setting.hpp"
#include "TextureList.hpp"
#include "FontList.hpp"
#include "MenuButton.hpp"

class Scene {
public:								//constructors
	Scene();
public:						    	//setters n getters


public:							    //public functions
	void			 run();

	//private functions
private:
	void			 mainEventHandler(sf::Event& rEvent);
	void			 mainDraw(sf::RenderWindow& rWindow);
	void			 mainUpdate(sf::RenderWindow& rWindow);
	void			 render();

	//private values
private:
	

};

#endif // !KYLE_Scene
