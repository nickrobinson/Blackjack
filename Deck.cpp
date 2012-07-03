/*
 * Deck.cpp
 *
 *  Created on: Jun 14, 2012
 *      Author: nrobinso
 */
#include "Card.h"
#include "Deck.h"
#include <time.h>
#include <iostream>

using namespace std;


Deck::Deck()
{
	Card tempCard;
	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 13; j++)
		{
			if(j !=0)
				tempCard.setVal(Card::Face(j+1));
			else
				tempCard.setVal(Card::Face(j));
			tempCard.setSuit(Card::Suit(i));
			cards.push_back(tempCard);
		}
	}
	count = 0;
}

void Deck::shuffle()
{
	srand(time(NULL));
	int randNum = rand() % 52;
	Card tempCard;

	for(int i=0; i < 52; i++)
	{
		tempCard = cards[i];
		cards[i] = cards[randNum];
		cards[randNum] = cards[i];
		randNum = rand() % 52;
	}

	topCard = 0;
}

Card Deck::Deal()
{
	Card *tempCard = &cards[topCard];
	topCard++;

	if(tempCard->getVal() > 9)
		count--;
	else if(tempCard->getVal() < 7)
		count++;

	return *tempCard;
}


