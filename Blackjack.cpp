/*
 * Black.cpp
 *
 *  Created on: Jun 14, 2012
 *      Author: nrobinso
 */
#include <iostream>
#include <string>
#include <vector>
#include "Card.h"
#include "Deck.h"
#include "Player.h"

using namespace std;

int main()
{
	Deck myDeck;
	Player me;
	int playerCardCount = 0;
	int dealerCardCount = 0;
	string userResponse;
	cout << "Would you like to play?: ";
	cin >> userResponse;

	if(userResponse == "Y" || userResponse == "y")
	{
		myDeck.shuffle();
	}

	//Deal a game
	vector<Card> playersCards;
	vector<Card> dealerCards;
	playersCards.push_back(myDeck.Deal());
	playersCards.push_back(myDeck.Deal());

	cout << "Your Cards: " << playersCards[0].getVal() << " " << playersCards[1].getVal() << endl;
	
	//Dealer Cards
	dealerCards.push_back(myDeck.Deal());
	dealerCards.push_back(myDeck.Deal());
	playerCardCount = 2;
	cout << "Dealer showing: " << dealerCards[1].getVal() << endl;

	if(me.getHandValue(&playersCards) == 21)
	{
		cout << "BLACKJACK" << endl;
		me.setBankroll(me.getBankroll() + (me.getBetAmmount() * 1.5));
	}

	cout << "Hit(H) Double(D) or Stand(S): ";
	cin >> userResponse;

	while(userResponse == "H" && (me.getHandValue(&playersCards) <= 21))
	{
		playerCardCount++;
		playersCards.push_back(myDeck.Deal());
		cout << "Your Cards: ";
		for(int i = 0; i < playersCards.size(); i++)
		{
			cout << playersCards[i].getVal() << " ";
		}
		cout << endl;
		
		cout << "Hand Value: " << me.getHandValue(&playersCards) << endl;
		cout << "Hit(H) Double(D) or Stand(S): ";
		cin >> userResponse;
	}

	//Dealers turn
	while(me.getHandValue(&dealerCards) < 17)
	{
		dealerCards.push_back(myDeck.Deal());
	}

	cout << "Dealer's Hand: ";
	for(int i = 0; i < dealerCards.size(); i++)
	{
		cout << dealerCards[i].getVal() << " ";
	}
	cout << endl;

	if(me.getHandValue(&dealerCards) > 21)
	{
		cout << "YOU WIN";
		me.setBankroll(me.getBankroll() + me.getBetAmmount());
	}
	else if(me.getHandValue(&dealerCards) > me.getHandValue(&playersCards))
	{
		cout << "YOU LOSE";
		me.setBankroll(me.getBankroll() - me.getBetAmmount());
	}
	else if(me.getHandValue(&playersCards) > me.getHandValue(&dealerCards))
	{
		cout << "YOU WIN";
		me.setBankroll(me.getBankroll() + me.getBetAmmount());
	}

	cin >> userResponse;

	return 0;
}


