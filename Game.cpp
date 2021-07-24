#include "Game.hpp"

Game::Game() :App(sf::VideoMode(Settings.getSize().x, Settings.getSize().y), "Title", sf::Style::Close), Event()
, TwoPlayer(Settings),OnePlayer(Settings)
{

	render(); //load resources
   MenuScene.run(TextureRenderer,FontRenderer);
   OnePlayer.run(TextureRenderer, FontRenderer);
   TwoPlayer.run(TextureRenderer, FontRenderer); //*** init of rooms
	setBackground();  //sets bg
	Run();         //runs loop
	
}

void Game::Run()
{
	while (App.isOpen()) {
		mainEventHandler();
		mainUpdate();
		App.clear();
		mainDraw();														//Main Loop
		App.display();
}
}
void Game::setBackground()
{
	backGround.setTexture(TextureRenderer.get(Textures::ID::BG));		//sets background texture
}
void Game::mainEventHandler()
{
	while (App.pollEvent(Event)) {
		if (Event.type == sf::Event::EventType::Closed)								//close Window if exit clicked
			App.close();
		switch (Settings.getGameChoice()) {
		case Setting::GameChoice::Null:MenuScene.mainEventHandler(Event); break;	//Main Event Deciding between stages
		case Setting::GameChoice::OnePlayer:OnePlayer.mainEventHandler(Event,Settings); break;
		case Setting::GameChoice::TwoPlayer:TwoPlayer.mainEventHandler(Event); break;
		}
		
		
	}
}

void Game::mainDraw()
{
	App.draw(backGround);
	switch (Settings.getGameChoice()) {
	case Setting::GameChoice::Null:MenuScene.mainDraw(App); break;
	case Setting::GameChoice::OnePlayer:OnePlayer.mainDraw(App); break;				//Main Draw Deciding between stages
	case Setting::GameChoice::TwoPlayer:TwoPlayer.mainDraw(App); break;
	}
	
}

void Game::mainUpdate()
{
	App.draw(backGround);
	switch (Settings.getGameChoice()) {
	case Setting::GameChoice::Null:MenuScene.mainUpdate(App,Settings); break;
	case Setting::GameChoice::OnePlayer:OnePlayer.mainUpdate(App, Settings); break;  //Main Update Deciding between stages
	case Setting::GameChoice::TwoPlayer:TwoPlayer.mainUpdate(App, Settings); break;
	}
	
	
}

void Game::render()
{
	TextureRenderer.load(Textures::ID::Title, "files\\title.png");
	TextureRenderer.load(Textures::ID::BG, "files\\bg.png");
	TextureRenderer.load(Textures::ID::MenuButton, "files\\menuButton.png");  //Loads resources into lists
	FontRenderer.load(Fonts::ID::MenuFont, "files\\menuFont.otf");
}
