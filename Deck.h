/*
 * Deck.h
 *
 *  Created on: Jun 14, 2012
 *      Author: nrobinso
 */

#ifndef DECK_H_
#define DECK_H_
#include "Card.h"
#include <vector>
#include <stdio.h>  

using namespace std;

class Deck{
	public:
		Deck();
		void shuffle();
		int deal(int numCards);
		int getCount();
		void setCount(int newCount);
		Card Deal();

	private:
		vector<Card> cards;
		int count;
		int topCard;

};



#endif /* DECK_H_ */
