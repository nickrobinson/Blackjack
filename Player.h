/*
 * Player.h
 *
 *  Created on: Jun 14, 2012
 *      Author: nrobinso
 */

#ifndef PLAYER_H_
#define PLAYER_H_
#include "Card.h"
#include <vector>

using namespace std;

class Player{
	public:
		Player();
		double getBankroll();
		void setBankroll(double);
		double getBetAmmount();
		void setBetAmmount(double);
		int getHandValue(vector<Card>*);


	private:
		double bankroll;
		double betAmmount;
};



#endif /* PLAYER_H_ */