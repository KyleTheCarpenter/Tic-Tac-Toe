#include "MenuButton.hpp"

MenuButton::MenuButton(std::string Name) : myState(State::Null), activated(false)
{
	//constructos asks for a name.. sets the State to Null and activated to false
	myText.setString(Name);
	
}

void MenuButton::getResources(sf::Texture& t, sf::Font& f)
{
	//takes the textures from the resource lists and assigns

	mySprite.setTexture(t);
	mySprite.setTextureRect(sf::IntRect(0, 0, 350, 80)); //sets starting image OFF
	myText.setFont(f);
	myText.setFillColor(sf::Color::Black); 
	
}

void MenuButton::EventHandle(sf::Event& Event)
{

	if (Event.type == Event.MouseButtonPressed) {
		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
			if (myState == State::ON) {
				activated = true;
			} //if its Hoverd
		}		//if Button is Left
	}				//if Button is pressed
	
}

void MenuButton::update(sf::RenderWindow& window)
{
	
	switch (myState) { //checks the State and changes the rect accordingly
		case State::Off: mySprite.setTextureRect(sf::IntRect(0, 0, 350, 80)); break;
		case State::ON: mySprite.setTextureRect(sf::IntRect(0, 80, 350, 80)); break;
	}//end of checking State

    myState = State::Off; //automatically sets the Button to off

	if (mySprite.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y))) {
		myState = State::ON; //checks if the Button is Hoverd and changes the tex rect to ON
	} //end of checking if hoverd
	
}

void MenuButton::setTextPosition()
{	//lines up the Text with the middle of the button

	myText.setPosition(mySprite.getPosition().x + mySprite.getGlobalBounds().width / 2 - myText.getGlobalBounds().width / 2,
	mySprite.getPosition().y + mySprite.getGlobalBounds().height / 4);

}


void MenuButton::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(mySprite, states);
	target.draw(myText, states);

}


