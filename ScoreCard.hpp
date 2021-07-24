#pragma once

#ifndef KYLE_SCORECARD
#define KYLE_SCORECARD
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Setting.hpp"
#include "FontList.hpp"

class ScoreCard : public sf::Drawable {

public: //constructors
	ScoreCard();

public: //getters mutators
	
	bool							Alive()							{ return alive; }
	void							setAlive(bool b)				{ alive = b; }

public:	// public functions

	void							init();
	void							update(Setting & setting);
	void							ShowStats(Setting& setting);
	void							setFonts(FontList& fontRenderer);
	void							Clear();
	void							ClearScore();
	
private: //private functions

	virtual void					draw(sf::RenderTarget& target, sf::RenderStates states)const;

private: //private values

	sf::Text						myScoreTitlep1;
	sf::Text						myScoreTitlep2;
	sf::Text						myScoreDatap1;
	sf::Text						myScoreDatap2;

	sf::Text						turnTitle;
	sf::Text						turnData;
	sf::RectangleShape				turnShape;
	Setting::Turn					displayTurn;
	sf::Text						WinnerText;
	
	bool							alive;

};







#endif // !KYLE_SCORECARD
