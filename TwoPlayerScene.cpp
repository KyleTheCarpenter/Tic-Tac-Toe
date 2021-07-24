#include "TwoPlayerScene.hpp"



TwoPlayerScene::TwoPlayerScene(Setting& settings) :turn(1),
ExitButton("Menu"), RetryButton("Retry") , myGrid(settings)
//sets turn to player 1. names buttons
	
{

}

void TwoPlayerScene::run(TextureList& TextureRenderer, FontList& FontRenderer)
{
	ExitButton.getResources(TextureRenderer.get(Textures::ID::MenuButton), FontRenderer.get(Fonts::ID::MenuFont));
	RetryButton.getResources(TextureRenderer.get(Textures::ID::MenuButton), FontRenderer.get(Fonts::ID::MenuFont));
	scoreCard.setFonts(FontRenderer);
	scoreCard.init();
	ExitButton.setPosition(300, 520);
	RetryButton.setPosition(0, 520);

	
}

void TwoPlayerScene::mainEventHandler(sf::Event& Event)
{
	ExitButton.EventHandle(Event);
	if (myGrid.getPause() == true) {
		RetryButton.EventHandle(Event); //only Handle retry if game paused
	}
	myGrid.EventHandler(Event);
}

void TwoPlayerScene::mainDraw(sf::RenderWindow& rWindow)
{

	rWindow.draw(ExitButton);
	if (myGrid.getPause() == true) {
		rWindow.draw(RetryButton);  //only draw retry if game paused
	}
	
	rWindow.draw(myGrid);
	rWindow.draw(scoreCard);
}

void TwoPlayerScene::mainUpdate(sf::RenderWindow& rWindow, Setting& Settings)
{
	scoreCard.update(Settings);
	if (myGrid.getPause() == false) { //if only done if isnt paused
		switch (Settings.getWinner()) { //checking to see if anyone won
			//pauses the game then summons winner text then shows the stats of scorecard
			case Setting::Turn::me: myGrid.setPause(true); scoreCard.setAlive(true); scoreCard.ShowStats(Settings); break; //lil redundent

			case Setting::Turn::you:myGrid.setPause(true); scoreCard.setAlive(true); scoreCard.ShowStats(Settings); break;

			case Setting::Turn::draw: myGrid.setPause(true); scoreCard.setAlive(true); scoreCard.ShowStats(Settings);  break;

		}
	}//end of checking if isnt paused

	//updates of objects
	myGrid.update(rWindow);
	ExitButton.update(rWindow);
	if (myGrid.getPause() == true) {  //only show retry if the game is paused
		RetryButton.update(rWindow);
	}
	

	if (ExitButton.getActivated()) {
		ExitButton.Deactivate();
		myGrid.Clear();
		scoreCard.Clear();				//if exit button is pressed
		scoreCard.ClearScore();
		Settings.clearScores();
		myGrid.setPause(false);
		Settings.setWinner(Setting::Turn::Null);
		Settings.setGameChoice(Setting::GameChoice::Null);

	}//end of exit button
	if (RetryButton.getActivated()) {  //if retry button is pressed
		RetryButton.Deactivate();
		myGrid.Clear();
		scoreCard.Clear();
		Settings.setTurn(Settings.getWinner());
		myGrid.setPause(false);
		Settings.setWinner(Setting::Turn::Null);
		
	}//end of retry button
}


