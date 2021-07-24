#include "OnePlayerScene.hpp"



OnePlayerScene::OnePlayerScene(Setting& settings) :turn(1),once(false),
ExitButton("Menu"), RetryButton("Retry"), myGrid(settings), computerChoice(0)
//set button names, make turn to player1, once is false aka computer clock hasnt started
//computer choice is 0 to start

{

}

void OnePlayerScene::run(TextureList& TextureRenderer, FontList& FontRenderer)
{
	ExitButton.getResources(TextureRenderer.get(Textures::ID::MenuButton), FontRenderer.get(Fonts::ID::MenuFont));
	RetryButton.getResources(TextureRenderer.get(Textures::ID::MenuButton), FontRenderer.get(Fonts::ID::MenuFont));
	scoreCard.setFonts(FontRenderer);
	scoreCard.init();
	ExitButton.setPosition(300, 520);
	RetryButton.setPosition(0, 520);


}
void OnePlayerScene::PrintSquare(int num, Setting& settings) {
	
		if (myGrid.getSquare(num).getID() == Setting::Turn::Null) {
			myGrid.updateSquare(num);
	}
		else if (myGrid.getSquare(num).getID() == Setting::Turn::me) {
			ComputerMove(settings);
			std::cout << "its hitting me";
		}
}
void OnePlayerScene::ComputerMove(Setting& Settings)
{
	computerChoice = rand() % 9;
	std::cout << computerChoice << "\n";
	once = false;
	//random number between 0 and 9

   //check horizontal doubles toprow

	if (myGrid.getTally() == 9)  {

	}
	if (myGrid.getTally() < 9) {
		if (myGrid.getSquare(0).getID() == Setting::Turn::you &&
			myGrid.getSquare(1).getID() == Setting::Turn::you && myGrid.getSquare(2).getID() == Setting::Turn::Null) {

			PrintSquare(2, Settings);
		}
		else if (myGrid.getSquare(1).getID() == Setting::Turn::you &&
			myGrid.getSquare(2).getID() == Setting::Turn::you && myGrid.getSquare(0).getID() == Setting::Turn::Null) {
			PrintSquare(0, Settings);
		}
		else if (myGrid.getSquare(0).getID() == Setting::Turn::you &&
			myGrid.getSquare(2).getID() == Setting::Turn::you && myGrid.getSquare(1).getID() == Setting::Turn::Null) {
			PrintSquare(1, Settings);
		}
		//check horizontal middle row
		else if (myGrid.getSquare(3).getID() == Setting::Turn::you &&
			myGrid.getSquare(4).getID() == Setting::Turn::you && myGrid.getSquare(5).getID() == Setting::Turn::Null) {
			PrintSquare(5, Settings);
		}
		else if (myGrid.getSquare(5).getID() == Setting::Turn::you &&
			myGrid.getSquare(4).getID() == Setting::Turn::you && myGrid.getSquare(3).getID() == Setting::Turn::Null) {
			PrintSquare(3, Settings);
		}
		else if (myGrid.getSquare(5).getID() == Setting::Turn::you &&
			myGrid.getSquare(3).getID() == Setting::Turn::you && myGrid.getSquare(4).getID() == Setting::Turn::Null) {
			PrintSquare(4, Settings);
		}

		//check horizontal bottom row
		else if (myGrid.getSquare(6).getID() == Setting::Turn::you &&
			myGrid.getSquare(7).getID() == Setting::Turn::you && myGrid.getSquare(8).getID() == Setting::Turn::Null) {
			PrintSquare(8, Settings);
		}
		else if (myGrid.getSquare(7).getID() == Setting::Turn::you &&
			myGrid.getSquare(8).getID() == Setting::Turn::you && myGrid.getSquare(6).getID() == Setting::Turn::Null) {
			PrintSquare(6, Settings);
		}
		else if (myGrid.getSquare(6).getID() == Setting::Turn::you &&
			myGrid.getSquare(8).getID() == Setting::Turn::you && myGrid.getSquare(7).getID() == Setting::Turn::Null) {
			PrintSquare(7, Settings);
		}

		//check vertical 1st row
		else if (myGrid.getSquare(0).getID() == Setting::Turn::you &&
			myGrid.getSquare(3).getID() == Setting::Turn::you && myGrid.getSquare(6).getID() == Setting::Turn::Null) {
			PrintSquare(6, Settings);
		}
		else if (myGrid.getSquare(0).getID() == Setting::Turn::you &&
			myGrid.getSquare(6).getID() == Setting::Turn::you && myGrid.getSquare(3).getID() == Setting::Turn::Null) {
			PrintSquare(3, Settings);
		}
		else if (myGrid.getSquare(3).getID() == Setting::Turn::you &&
			myGrid.getSquare(6).getID() == Setting::Turn::you && myGrid.getSquare(0).getID() == Setting::Turn::Null) {
			PrintSquare(0, Settings);
		}
		//check vertical 2st row
		else if (myGrid.getSquare(1).getID() == Setting::Turn::you &&
			myGrid.getSquare(4).getID() == Setting::Turn::you && myGrid.getSquare(7).getID() == Setting::Turn::Null) {
			PrintSquare(7, Settings);
		}
		else if (myGrid.getSquare(1).getID() == Setting::Turn::you &&
			myGrid.getSquare(7).getID() == Setting::Turn::you && myGrid.getSquare(4).getID() == Setting::Turn::Null) {
			PrintSquare(4, Settings);
		}
		else if (myGrid.getSquare(7).getID() == Setting::Turn::you &&
			myGrid.getSquare(4).getID() == Setting::Turn::you && myGrid.getSquare(1).getID() == Setting::Turn::Null) {
			PrintSquare(1, Settings);
		}
		//check vertical 3rd row
		else if (myGrid.getSquare(2).getID() == Setting::Turn::you &&
			myGrid.getSquare(5).getID() == Setting::Turn::you && myGrid.getSquare(8).getID() == Setting::Turn::Null) {
			PrintSquare(8, Settings);
		}
		else if (myGrid.getSquare(2).getID() == Setting::Turn::you &&
			myGrid.getSquare(8).getID() == Setting::Turn::you && myGrid.getSquare(5).getID() == Setting::Turn::Null) {
			PrintSquare(5, Settings);
		}
		else if (myGrid.getSquare(5).getID() == Setting::Turn::you &&
			myGrid.getSquare(8).getID() == Setting::Turn::you && myGrid.getSquare(2).getID() == Setting::Turn::Null) {
			PrintSquare(2, Settings);
		}

		//check diag to the right
		else if (myGrid.getSquare(0).getID() == Setting::Turn::you &&
			myGrid.getSquare(4).getID() == Setting::Turn::you && myGrid.getSquare(8).getID() == Setting::Turn::Null) {
			PrintSquare(8, Settings);
		}
		else if (myGrid.getSquare(0).getID() == Setting::Turn::you &&
			myGrid.getSquare(8).getID() == Setting::Turn::you && myGrid.getSquare(4).getID() == Setting::Turn::Null) {
			PrintSquare(4, Settings);
		}
		else if (myGrid.getSquare(4).getID() == Setting::Turn::you &&
			myGrid.getSquare(8).getID() == Setting::Turn::you && myGrid.getSquare(0).getID() == Setting::Turn::Null) {
			PrintSquare(0, Settings);
		}
		//check diag to the left
		else if (myGrid.getSquare(2).getID() == Setting::Turn::you &&
			myGrid.getSquare(4).getID() == Setting::Turn::you && myGrid.getSquare(6).getID() == Setting::Turn::Null) {
			PrintSquare(6, Settings);
		}
		else if (myGrid.getSquare(2).getID() == Setting::Turn::you &&
			myGrid.getSquare(6).getID() == Setting::Turn::you && myGrid.getSquare(4).getID() == Setting::Turn::Null) {
			PrintSquare(4, Settings);
		}
		else if (myGrid.getSquare(6).getID() == Setting::Turn::you &&
			myGrid.getSquare(4).getID() == Setting::Turn::you && myGrid.getSquare(2).getID() == Setting::Turn::Null) {
			PrintSquare(2, Settings);
		}

	                                                                                                                 	//start player collision

 //top row horiz
		else if (myGrid.getSquare(0).getID() == Setting::Turn::me &&
			myGrid.getSquare(1).getID() == Setting::Turn::me && myGrid.getSquare(2).getID() == Setting::Turn::Null) {

			PrintSquare(2, Settings);
		}
		else if (myGrid.getSquare(1).getID() == Setting::Turn::me &&
			myGrid.getSquare(2).getID() == Setting::Turn::me && myGrid.getSquare(0).getID() == Setting::Turn::Null) {
			PrintSquare(0, Settings);
		}
		else if (myGrid.getSquare(0).getID() == Setting::Turn::me &&
			myGrid.getSquare(2).getID() == Setting::Turn::me && myGrid.getSquare(1).getID() == Setting::Turn::Null) {
			PrintSquare(1, Settings);
		}
		//check horizontal middle row
		else if (myGrid.getSquare(3).getID() == Setting::Turn::me &&
			myGrid.getSquare(4).getID() == Setting::Turn::me && myGrid.getSquare(5).getID() == Setting::Turn::Null) {
			PrintSquare(5, Settings);
		}
		else if (myGrid.getSquare(5).getID() == Setting::Turn::me &&
			myGrid.getSquare(4).getID() == Setting::Turn::me && myGrid.getSquare(3).getID() == Setting::Turn::Null) {
			PrintSquare(3, Settings);
		}
		else if (myGrid.getSquare(5).getID() == Setting::Turn::me &&
			myGrid.getSquare(3).getID() == Setting::Turn::me && myGrid.getSquare(4).getID() == Setting::Turn::Null) {
			PrintSquare(4, Settings);
		}

		//check horizontal bottom row
		else if (myGrid.getSquare(6).getID() == Setting::Turn::me &&
			myGrid.getSquare(7).getID() == Setting::Turn::me && myGrid.getSquare(8).getID() == Setting::Turn::Null) {
			PrintSquare(8, Settings);
		}
		else if (myGrid.getSquare(7).getID() == Setting::Turn::me &&
			myGrid.getSquare(8).getID() == Setting::Turn::me && myGrid.getSquare(6).getID() == Setting::Turn::Null) {
			PrintSquare(6, Settings);
		}
		else if (myGrid.getSquare(6).getID() == Setting::Turn::me &&
			myGrid.getSquare(8).getID() == Setting::Turn::me && myGrid.getSquare(7).getID() == Setting::Turn::Null) {
			PrintSquare(7, Settings);
		}

		//check vertical 1st row
		else if (myGrid.getSquare(0).getID() == Setting::Turn::me &&
			myGrid.getSquare(3).getID() == Setting::Turn::me && myGrid.getSquare(6).getID() == Setting::Turn::Null) {
			PrintSquare(6, Settings);
		}
		else if (myGrid.getSquare(0).getID() == Setting::Turn::me &&
			myGrid.getSquare(6).getID() == Setting::Turn::me && myGrid.getSquare(3).getID() == Setting::Turn::Null) {
			PrintSquare(3, Settings);
		}
		else if (myGrid.getSquare(3).getID() == Setting::Turn::me &&
			myGrid.getSquare(6).getID() == Setting::Turn::me && myGrid.getSquare(0).getID() == Setting::Turn::Null) {
			PrintSquare(0, Settings);
		}
		//check vertical 2st row
		else if (myGrid.getSquare(1).getID() == Setting::Turn::me &&
			myGrid.getSquare(4).getID() == Setting::Turn::me && myGrid.getSquare(7).getID() == Setting::Turn::Null) {
			PrintSquare(7, Settings);
		}
		else if (myGrid.getSquare(1).getID() == Setting::Turn::me &&
			myGrid.getSquare(7).getID() == Setting::Turn::me && myGrid.getSquare(4).getID() == Setting::Turn::Null) {
			PrintSquare(4, Settings);
		}
		else if (myGrid.getSquare(7).getID() == Setting::Turn::me &&
			myGrid.getSquare(4).getID() == Setting::Turn::me && myGrid.getSquare(1).getID() == Setting::Turn::Null) {
			PrintSquare(1, Settings);
		}
		//check vertical 3rd row
		else if (myGrid.getSquare(2).getID() == Setting::Turn::me &&
			myGrid.getSquare(5).getID() == Setting::Turn::me && myGrid.getSquare(8).getID() == Setting::Turn::Null) {
			PrintSquare(8, Settings);
		}
		else if (myGrid.getSquare(2).getID() == Setting::Turn::me &&
			myGrid.getSquare(8).getID() == Setting::Turn::me && myGrid.getSquare(5).getID() == Setting::Turn::Null) {
			PrintSquare(5, Settings);
		}
		else if (myGrid.getSquare(5).getID() == Setting::Turn::me &&
			myGrid.getSquare(8).getID() == Setting::Turn::me && myGrid.getSquare(2).getID() == Setting::Turn::Null) {
			PrintSquare(2, Settings);
		}

		//check diag to the right
		else if (myGrid.getSquare(0).getID() == Setting::Turn::me &&
			myGrid.getSquare(4).getID() == Setting::Turn::me && myGrid.getSquare(8).getID() == Setting::Turn::Null) {
			PrintSquare(8, Settings);
		}
		else if (myGrid.getSquare(0).getID() == Setting::Turn::me &&
			myGrid.getSquare(8).getID() == Setting::Turn::me && myGrid.getSquare(4).getID() == Setting::Turn::Null) {
			PrintSquare(4, Settings);
		}
		else if (myGrid.getSquare(4).getID() == Setting::Turn::me &&
			myGrid.getSquare(8).getID() == Setting::Turn::me && myGrid.getSquare(0).getID() == Setting::Turn::Null) {
			PrintSquare(0, Settings);
		}
		//check diag to the left
		else if (myGrid.getSquare(2).getID() == Setting::Turn::me &&
			myGrid.getSquare(4).getID() == Setting::Turn::me && myGrid.getSquare(6).getID() == Setting::Turn::Null) {
			PrintSquare(6, Settings);
		}
		else if (myGrid.getSquare(2).getID() == Setting::Turn::me &&
			myGrid.getSquare(6).getID() == Setting::Turn::me && myGrid.getSquare(4).getID() == Setting::Turn::Null) {
			PrintSquare(4, Settings);
		}
		else if (myGrid.getSquare(6).getID() == Setting::Turn::me &&
			myGrid.getSquare(4).getID() == Setting::Turn::me && myGrid.getSquare(2).getID() == Setting::Turn::Null) {
			PrintSquare(2, Settings);
		}

		///end

		else if (myGrid.getSquare(computerChoice).getID() == Setting::Turn::Null) {
			PrintSquare(computerChoice, Settings);
			std::cout << "this should print";
		}
		else if (myGrid.getSquare(computerChoice).getID() == Setting::Turn::you) {
			ComputerMove(Settings);
			std::cout << "hit you";
		}
		else if (myGrid.getSquare(computerChoice).getID() == Setting::Turn::me) {
			ComputerMove(Settings);
			std::cout << "hit me";
		}
	}
	//end of else
}
void OnePlayerScene::mainEventHandler(sf::Event& Event,Setting & Settings)
{
	ExitButton.EventHandle(Event);
	if (myGrid.getPause() == true) {        //only handle retry button events if its paused
		RetryButton.EventHandle(Event);
	}
	if (Settings.getTurn() == Setting::Turn::me ) {
		myGrid.EventHandler(Event);           //only handle events if its my turn
	}
}

void OnePlayerScene::mainDraw(sf::RenderWindow& rWindow)
{

	rWindow.draw(ExitButton);
	if (myGrid.getPause() == true) {  //only draw retry button if paused
		rWindow.draw(RetryButton);
	}

	rWindow.draw(myGrid);
	rWindow.draw(scoreCard);
}

void OnePlayerScene::mainUpdate(sf::RenderWindow& rWindow, Setting& Settings)
{
	
	if (Settings.getTurn() == Setting::Turn::you) {			//if its computers turn
		if (once == false){
			std::cout << "once\n";						  //if clock has been turned off restart it.
			clock.restart();
			once = true;								//let it only happen once
		}
		time = clock.getElapsedTime();
		if (time.asMilliseconds() >= 1500 && once == true){ //every 1.5sec reset clock and compute move. set turn back to player1
			clock.restart();
			if(myGrid.getTally() < 9)
			ComputerMove(Settings);
			Settings.setTurn(Setting::Turn::me);
			
		}
	}
	scoreCard.update(Settings); //update scorecard
	if (myGrid.getPause() == false) { //if isnt paused
		switch (Settings.getWinner()) { //checks if there is a winner and summons scorecard
		case Setting::Turn::me: myGrid.setPause(true); scoreCard.setAlive(true); scoreCard.ShowStats(Settings); break;
		case Setting::Turn::you: myGrid.setPause(true);  scoreCard.setAlive(true); scoreCard.ShowStats(Settings); break;
		case Setting::Turn::draw:  myGrid.setPause(true); scoreCard.setAlive(true); Settings.setTurn(Setting::Turn::me);
			scoreCard.ShowStats(Settings);  break;
			}// end of checking for a winner

		}//end of checking if its not paused

	ExitButton.update(rWindow);
	RetryButton.update(rWindow); //update buttons
	if (myGrid.getPause() == true) {
		RetryButton.update(rWindow);   //update retry if paused
	}
	myGrid.update(rWindow);
	if (ExitButton.getActivated()) {     //handle exit button
		ExitButton.Deactivate();
		if (Settings.getTurn() == Setting::Turn::you) {
			once = false;               //resets move clock if exiting during computer play
		}

		myGrid.Clear();
		scoreCard.Clear();
		scoreCard.ClearScore();
		Settings.clearScores();
		myGrid.setPause(false);
		
		Settings.setWinner(Setting::Turn::Null);
		Settings.setGameChoice(Setting::GameChoice::Null);
		
	}
	if (RetryButton.getActivated()) {  //handle retry button
		RetryButton.Deactivate();
		myGrid.setPause(false);
		myGrid.Clear();
		scoreCard.Clear();
		Settings.setTurn(Settings.getWinner());

		if (Settings.getTurn() == Setting::Turn::draw) { //if its a draw make 1p start
			Settings.setTurn(Setting::Turn::me);
		}
		Settings.setWinner(Setting::Turn::Null);
		once = false; //resets computer wait clock
		clock.restart();
	}

}


