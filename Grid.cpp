#include "Grid.hpp"

Grid::Grid(Setting & Settings) :i(0),j(0),valX(150),valY(150),whosTurn(Turn::one),square(Settings),rSettings(Settings),pause(false),
tally(0)
{  //i and j and tempory values valX and valY are starting point of the grid,
	//sets whosTurn to player1.sets pause to false and tally to 0
	myGrid.reserve(9);
	for (i = 0; i < 9; i++) {
		myGrid.push_back(square);
	}
	updateGrid();  //lines up grid

}
void Grid::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	//draws all squares
	for (int ie = 0; ie < myGrid.size(); ie++) {
		target.draw(myGrid[ie], states);
	}
	
}
void Grid::update(sf::RenderWindow& rWindow)
{
	tally = myGrid[0].getCount() + myGrid[1].getCount() + myGrid[2].getCount() + myGrid[3].getCount() + myGrid[4].getCount() + myGrid[5].getCount()
		+ myGrid[6].getCount() + myGrid[7].getCount() + myGrid[8].getCount();
						//this adds up all the tiles count value and checks when all are active and calls a draw

	if (tally == 9) {
		rSettings.setWinner(Setting::Turn::draw);
		tally = 0;
	}					//end of checking if tally is full

		for (i = 0; i < myGrid.size(); i++) {
			myGrid[i].update(rWindow);
		
		ProcessResults();
	}					//end of precessing results

}
void Grid::ProcessResults()
		//all results
{       //horizontal wins of ME
	
		if (myGrid[0].getID() == Setting::Turn::me && myGrid[1].getID() == Setting::Turn::me && myGrid[2].getID() == Setting::Turn::me) {
			rSettings.setWinner(Setting::Turn::me);
			End();
		}
		else if (myGrid[3].getID() == Setting::Turn::me && myGrid[4].getID() == Setting::Turn::me && myGrid[5].getID() == Setting::Turn::me) {
			rSettings.setWinner(Setting::Turn::me);
			End();
		}
		else 	if (myGrid[6].getID() == Setting::Turn::me && myGrid[7].getID() == Setting::Turn::me && myGrid[8].getID() == Setting::Turn::me) {
			rSettings.setWinner(Setting::Turn::me);
			End();
		}


		//horizontal wins of you
		else if (myGrid[0].getID() == Setting::Turn::you && myGrid[1].getID() == Setting::Turn::you && myGrid[2].getID() == Setting::Turn::you) {
			rSettings.setWinner(Setting::Turn::you);
			End();
		}
		else if (myGrid[3].getID() == Setting::Turn::you && myGrid[4].getID() == Setting::Turn::you && myGrid[5].getID() == Setting::Turn::you) {
			rSettings.setWinner(Setting::Turn::you);
			End();
		}
		else if (myGrid[6].getID() == Setting::Turn::you && myGrid[7].getID() == Setting::Turn::you && myGrid[8].getID() == Setting::Turn::you) {
			rSettings.setWinner(Setting::Turn::you);
			End();
		}

		//vertical wins of me
		else if (myGrid[0].getID() == Setting::Turn::me && myGrid[3].getID() == Setting::Turn::me && myGrid[6].getID() == Setting::Turn::me) {
			rSettings.setWinner(Setting::Turn::me);
			End();
		}
		else if (myGrid[1].getID() == Setting::Turn::me && myGrid[4].getID() == Setting::Turn::me && myGrid[7].getID() == Setting::Turn::me) {
			rSettings.setWinner(Setting::Turn::me);
			End();
		}
		else if (myGrid[2].getID() == Setting::Turn::me && myGrid[5].getID() == Setting::Turn::me && myGrid[8].getID() == Setting::Turn::me) {
			rSettings.setWinner(Setting::Turn::me);
			End();
		}

		//vertical wins of you
		else if (myGrid[0].getID() == Setting::Turn::you && myGrid[3].getID() == Setting::Turn::you && myGrid[6].getID() == Setting::Turn::you) {
			rSettings.setWinner(Setting::Turn::you);
			End();
		}
		else if (myGrid[1].getID() == Setting::Turn::you && myGrid[4].getID() == Setting::Turn::you && myGrid[7].getID() == Setting::Turn::you) {
			rSettings.setWinner(Setting::Turn::you);
			End();
		}
		else if (myGrid[2].getID() == Setting::Turn::you && myGrid[5].getID() == Setting::Turn::you && myGrid[8].getID() == Setting::Turn::you) {
			rSettings.setWinner(Setting::Turn::you);
			End();
		}

		//diag wins of me
		else if (myGrid[0].getID() == Setting::Turn::me && myGrid[4].getID() == Setting::Turn::me && myGrid[8].getID() == Setting::Turn::me) {
			rSettings.setWinner(Setting::Turn::me);
			End();
		}
		else if (myGrid[2].getID() == Setting::Turn::me && myGrid[4].getID() == Setting::Turn::me && myGrid[6].getID() == Setting::Turn::me) {
			rSettings.setWinner(Setting::Turn::me);
			End();
		}

		//diag wins of you
		else if (myGrid[0].getID() == Setting::Turn::you && myGrid[4].getID() == Setting::Turn::you && myGrid[8].getID() == Setting::Turn::you) {
			rSettings.setWinner(Setting::Turn::you);
			End();
		}
		else if (myGrid[2].getID() == Setting::Turn::you && myGrid[4].getID() == Setting::Turn::you && myGrid[6].getID() == Setting::Turn::you) {
			rSettings.setWinner(Setting::Turn::you);
			End();
		}
	
	

}
void Grid::End()
{
	//locks all the tiles
	for (i = 0; i < myGrid.size(); i++) {
		myGrid[i].lock();
	}
	
}
void Grid::Clear()
{ //sets the grid back to default
	for (i = 0; i < myGrid.size(); i++) {
		myGrid[i].setID(Setting::Turn::Null);
		myGrid[i].setState(Square::State::Off);
		myGrid[i].unlock();
		myGrid[i].Reset();
		rSettings.setTurn(Setting::Turn::me);
	}
}
void Grid::EventHandler(sf::Event& Event)
{
	//event handlers for all squares
	for (i = 0; i < myGrid.size(); i++) {
		myGrid[i].EventHandler(Event);
	}
}
void Grid::updateSquare(int which)
{
	//updates a square in the grid for Computer
	myGrid[which].setColor(sf::Color::Green);
	myGrid[which].setState(Square::State::On);
	myGrid[which].setID(rSettings.getTurn());
	myGrid[which].setCount();
	myGrid[which].updateSquare();
	myGrid[which].lock();
}

void Grid::updateGrid()
{
	int temp = valX; //stores valX value

	for (i = 0,j+0; i < myGrid.size(); i++,j++) {
		if(j ==3){
			valY += square.getSize().y+5;  //every 3 squares set x to original and skip y down a row
			valX = temp;
			j = 0;
		}

		myGrid[i].setPosition(valX, valY);
		valX += square.getSize().x+5;
	}
}
