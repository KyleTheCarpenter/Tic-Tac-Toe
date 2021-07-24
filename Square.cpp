#include "Square.hpp"

Square::Square(Setting & Settings) :myState(State::Off), isLocked(false), isColliding(false),
myColor(sf::Color::Blue),rSettings(Settings),myID(Setting::Turn::Null),count(0)
{
	mySquare.setSize(sf::Vector2f(100, 100));
	mySquare.setFillColor(sf::Color::White);
	mySquare.setOutlineThickness(2);
	mySquare.setOutlineColor(sf::Color::Black);

}
void Square::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(mySquare, states); //draw the Square

}//end of draw 

void Square::update(sf::RenderWindow& rWindow)
{
	if (!isLocked) { //do if Sqare isnt Locked
		isColliding = false; //resets isColliding to false

		if (mySquare.getGlobalBounds().contains(sf::Mouse::getPosition(rWindow).x, sf::Mouse::getPosition(rWindow).y)) {
			//check if square is colliding with Mouse.. 
			isColliding = true; //sets isColliding to true

		}		//end of colliding with mouse
	}				//end of if its locked
}						//end of Live update


void Square::EventHandler(sf::Event& Event)
{
	if (Event.type == Event.MouseButtonPressed) {

		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {

			if (!isLocked) {								 //do if Square isnt locked

				if (isColliding) {							 //do if mouse is hovering the Square

					myState = State::On;					 //sets the State to ON
					myID = rSettings.getTurn();			   	 //sets the ID to whatever turn it is
					updateSquare();						     //updates Square to whoever pressed 
					count = 1;							     //changes the count to 1 aka ON
					switch (myID) {							 //sets the turn depending on whos turn it currently is
						case Setting::Turn::me:rSettings.setTurn(Setting::Turn::you); break;
						case Setting::Turn::you:rSettings.setTurn(Setting::Turn::me); break;
					}	//end of MyID Switch
					isLocked = true;						 // locks the Tile

				}			//end of checking if hovering
			}					//end of if its Locked
		}							//end of checking if left button is pressed
	}									//end of checking if Mouse button is pressed
}											//end of event Handling

void Square::Reset()
{ //set Square to White and count back to 0
	mySquare.setFillColor(sf::Color::White); isLocked = false;
	count = 0;
}

void Square::updateSquare()
{

	if (!isLocked) {				 //if square isnt locked

		switch (myID) {

			case Setting::Turn::me:myColor = sf::Color::Blue; break;
			case Setting::Turn::you:myColor = sf::Color::Green; break;

		} //end of switch myID

		switch (myState) {

			case State::Off:mySquare.setFillColor(sf::Color::White); isLocked = false; break;
			case State::On:mySquare.setFillColor(myColor); isLocked = true; break;

		} //end of switch myState
	} //end of if isLocked false
} //end of updateSquare
