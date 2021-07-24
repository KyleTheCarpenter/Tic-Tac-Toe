#pragma once


#ifndef KYLE_SETTING
#define KYLE_SETTING
#include <iostream>


			struct Size {
				float x;                   //homemade vector2f
				float y;
			};


class Setting {												//Constructors and enums
public:
		enum class				GameChoice					{Null,OnePlayer,TwoPlayer};   //Which Game Scene
		enum class				Turn						{Null,you,me,draw};           //whos Turn
	Setting();																			  //Constructor

public:					//Getter And Mutators								

		Size					getSize()	   const			 { return windowSize; }
		GameChoice				getGameChoice()const		     { return currentGame; }
		Turn					getTurn()      const			 { return myTurn; }
		Turn					getWinner()    const			 { return Winner; }
		int						getScore1()    const			 { return score1; }
		int						getScore2()    const			 { return score2; }

		void					setSize(float x, float y)		 { windowSize.x = x; windowSize.y = y; }
		void					setGameChoice(GameChoice choice) { currentGame = choice; }
		void					setTurn(Turn turn)				 { myTurn = turn; }
		void					setWinner(Turn turn)			 { Winner = turn; }

public:					//public Functions

		void					player1win()					 { score1++; }
		void					player2win()					 { score2++; }
		void					clearScores()					 { score1 = 0; score2 = 0; }

	
private:              //private values

		Turn			myTurn;
		Turn			Winner;
		Size			windowSize;
		int				score1;
		int				score2;
		GameChoice		currentGame;

};
#endif //#KYLE_SETTING