#include "ScoreCard.hpp"

void ScoreCard::setFonts(FontList & fontRenderer)
{
		//load fonts from the fontList

	myScoreTitlep1.setFont(fontRenderer.get(Fonts::ID::MenuFont));
	myScoreTitlep2.setFont(fontRenderer.get(Fonts::ID::MenuFont));
	myScoreDatap1.setFont(fontRenderer.get(Fonts::ID::MenuFont));
	myScoreDatap2.setFont(fontRenderer.get(Fonts::ID::MenuFont));
	turnTitle.setFont(fontRenderer.get(Fonts::ID::MenuFont));
	turnData.setFont(fontRenderer.get(Fonts::ID::MenuFont));
	WinnerText.setFont(fontRenderer.get(Fonts::ID::MenuFont));
	
}

ScoreCard::ScoreCard():alive(false),displayTurn(Setting::Turn::me)
{
	//sets winner text alive to false, sets the first turn to Player1

	turnShape.setSize(sf::Vector2f(30, 30));
	turnShape.setOutlineThickness(1);						//visual square representing turn
	turnShape.setOutlineColor(sf::Color::Black);
}

void ScoreCard::Clear()
{
	alive = false;			//hides the Winner text
}

void ScoreCard::ClearScore()
{
	myScoreDatap1.setString("0");
	myScoreDatap2.setString("0"); //sets visual text scores to 0
}

void ScoreCard::init()
{ 
	myScoreTitlep1.setCharacterSize(22);
	myScoreTitlep2.setCharacterSize(22);
	myScoreDatap1.setCharacterSize(28);
	myScoreDatap2.setCharacterSize(28);
	turnTitle.setCharacterSize(22);
	turnData.setCharacterSize(22);
	WinnerText.setCharacterSize(40);

	
	turnTitle.setString("Current Turn");
	myScoreTitlep1.setString("Player1 Score");

	myScoreTitlep1.setFillColor(sf::Color::Black);
	myScoreTitlep2.setFillColor(sf::Color::Black);
	myScoreDatap1.setFillColor(sf::Color::Black);
	myScoreDatap2.setFillColor(sf::Color::Black);
	turnTitle.setFillColor(sf::Color::Black);
	turnData.setFillColor(sf::Color::Black);
	WinnerText.setFillColor(sf::Color::Black);

	myScoreTitlep1.setPosition(10, 10);
	myScoreTitlep2.setPosition(10, 50);
	myScoreDatap1.setPosition(210, 5);
	myScoreDatap2.setPosition(210, 45);
	turnTitle.setPosition(350, 10);
	turnData.setPosition(375, 45);
	turnShape.setPosition(495, 50);
	WinnerText.setPosition(150, 100);
}

void ScoreCard::ShowStats(Setting& setting)
{
	
	switch (setting.getWinner()) {			//checks who Won and computes it

		case Setting::Turn::me:WinnerText.setString("Player 1 Wins"); setting.player1win(); break;
		case Setting::Turn::you:WinnerText.setString("Player 2 Wins"); setting.player2win();  break;
		case Setting::Turn::draw:WinnerText.setString("....DRAW...."); break;
		default:WinnerText.setString(""); break; //aka null

	}	//end of checking who won
} 




void ScoreCard::update(Setting & setting)
{

	myScoreDatap1.setString(std::to_string(setting.getScore1()));
	myScoreDatap2.setString(std::to_string(setting.getScore2()));

	switch (setting.getGameChoice()) { //sets the Title of score according to the gamemode
		case Setting::GameChoice::TwoPlayer:myScoreTitlep2.setString("Player2 Score"); break;
		case Setting::GameChoice::OnePlayer:myScoreTitlep2.setString("Comp Score"); break;

	} //end of gamechoice switch

	switch (setting.getTurn()) {								//checks whos turn it is
		case Setting::Turn::me:turnData.setString("Player1 "); turnShape.setFillColor(sf::Color::Blue); break; //sets visual turn to player1
		case Setting::Turn::you:							    //checks which gamemode
			switch (setting.getGameChoice()) {					//sets whos turn it is according to gamemode
				case Setting::GameChoice::TwoPlayer:turnData.setString("Player2"); break;
				case Setting::GameChoice::OnePlayer:turnData.setString("Comp   "); break;

			}			 //end of Gamechoice switch
		turnShape.setFillColor(sf::Color::Green); break;		//sets colour to green regardless of Gamemode
	}				//end of whos turn Switch

}				//end of liveUpdate

void ScoreCard::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	if (alive) { //Alive used for displaying Winner Text
		target.draw(WinnerText, states);
	}
		target.draw(turnTitle, states);
		target.draw(myScoreTitlep1, states);
		target.draw(myScoreTitlep2, states);
		target.draw(myScoreDatap1, states);
		target.draw(myScoreDatap2, states);
		target.draw(turnShape, states);
		target.draw(turnData, states);

	
}