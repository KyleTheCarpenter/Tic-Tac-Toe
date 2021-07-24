#include "MenuScene.hpp"



MenuScene::MenuScene() : // sets the Button text
	ExitButton		( "Exit"),
	onePlayerButton ( "1-Player"),
	twoPlayerButton ( "2-Player")
{}

void MenuScene::run(TextureList & TextureRenderer, FontList& FontRenderer)
{
	//sets the resources from the resource lists
	ExitButton.getResources(TextureRenderer.get(Textures::ID::MenuButton), FontRenderer.get(Fonts::ID::MenuFont));
	twoPlayerButton.getResources(TextureRenderer.get(Textures::ID::MenuButton), FontRenderer.get(Fonts::ID::MenuFont));
	onePlayerButton.getResources(TextureRenderer.get(Textures::ID::MenuButton), FontRenderer.get(Fonts::ID::MenuFont));
	myTitle.setTexture(TextureRenderer.get(Textures::ID::Title));

	ExitButton.setPosition(120, 450);
	onePlayerButton.setPosition(120, 250);
	twoPlayerButton.setPosition(120, 350);
	myTitle.setPosition(70, -20);
	myTitle.scale(2, 2);
}

void MenuScene::mainEventHandler(sf::Event& Event)
{
	ExitButton.EventHandle(Event);
	onePlayerButton.EventHandle(Event);
	twoPlayerButton.EventHandle(Event);
}

void MenuScene::mainDraw(sf::RenderWindow& rWindow)
{
	
	rWindow.draw(ExitButton);
	rWindow.draw(onePlayerButton);
	rWindow.draw(twoPlayerButton);
	rWindow.draw(myTitle);
}

void MenuScene::mainUpdate(sf::RenderWindow& rWindow,Setting & Settings)
{
	//add live update to buttons
	ExitButton.update(rWindow);
	onePlayerButton.update(rWindow);
	twoPlayerButton.update(rWindow);

	if (ExitButton.getActivated()) { //if exit button pressed
		ExitButton.Deactivate();
		
		rWindow.close(); //Exit game
	}//end of exitbutton

	if (onePlayerButton.getActivated()) {  //if Oneplayer Button is clicked
		onePlayerButton.Deactivate();
		Settings.setGameChoice(Setting::GameChoice::OnePlayer);//change gamemode to 1p
	}//end of 1pbutton

	if (twoPlayerButton.getActivated()) { // if twoPlayer button is clicked
		twoPlayerButton.Deactivate();
		Settings.setGameChoice(Setting::GameChoice::TwoPlayer); //change gamemode to 2p
	}//end of 2pbutton
}


