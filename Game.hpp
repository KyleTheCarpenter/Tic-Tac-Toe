#pragma once
/*

                 TITLE: Tic-Tac-Toe

					Author: Kylethecarpenter aka Kyle Earl

					Functionality:

						1Player against computer
						2Player agaisnt another Player
						Score
						Main Menu

					Known Bugs:
						not bug but easy to win agains computer

					Known Redundency:
						id system and turn system
						Grid overload

					Future Goals:
						easy mode and Hard mode
						way to save scores
						Adding a class dedicated to the computer

*/

#ifndef KYLE_GAME
#define KYLE_GAME
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Setting.hpp"
#include "TextureList.hpp"
#include "FontList.hpp"
#include "MenuScene.hpp"
#include"TwoPlayerScene.hpp"
#include"OnePlayerScene.hpp"


class Game {
public:								//constructors
					Game();

public:							    //public functions
	void			 Run();

								    //private functions
private:
	void			 mainEventHandler();
	void			 mainDraw();
	void			 mainUpdate();
	void			 render();
	void			 setBackground();
				
									//private values
private:		
	Setting							 Settings;
	sf::RenderWindow				 App;
	sf::Event						 Event;
	TextureList						 TextureRenderer;
	FontList						 FontRenderer;
	sf::Sprite						 backGround;
	MenuScene						 MenuScene;
	TwoPlayerScene					 TwoPlayer;
	OnePlayerScene					 OnePlayer;
	

};

#endif // !KYLE_GAME
