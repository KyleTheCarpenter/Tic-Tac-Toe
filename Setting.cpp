#include "Setting.hpp"

Setting::Setting():windowSize(),currentGame(GameChoice::Null),myTurn(Turn::me),Winner(Turn::Null),score1(0),score2(0)
{                                   //sets windowsize to null, Gamechoice to Menu aka Null, sets turn to start with 1st player
									//sets Winner to nonExistent aka Null, sets both scores to 0
	windowSize.x = 600;
	windowSize.y = 600;                     //sets window size to 600,600
}
