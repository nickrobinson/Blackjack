/*
 * Card.h
 *
 *  Created on: Jun 14, 2012
 *      Author: nrobinso
 */

#ifndef CARD_H_
#define CARD_H_

#include <string>

class Card{

	public:
		Card();
		enum Suit { Diamonds, Hearts, Clubs, Spades };
		enum Face { Ace = 0,
					Two = 2,
					Three = 3,
					Four = 4,
					Five = 5,
					Six = 6,
					Seven = 7,
					Eight = 8,
					Nine = 9,
					Ten = 10,
					Jack = 11,
					Queen = 12,
					King = 13};
		Card(int, int);
		int getVal();
		std::string getValStr(int);
		void setVal(Face);
		void setSuit(Suit);
		int getSuit();


	private:
		Suit mySuit;
		Face myFaceVal;
};


#endif /* CARD_H_ */
