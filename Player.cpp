/*
 * Player.cpp
 *
 *  Created on: Jun 14, 2012
 *      Author: nrobinso
 */

#include "Player.h"

using namespace std;

Player::Player()
{
	bankroll = 10000;
	betAmmount = 200;
}

double Player::getBankroll()
{
	return bankroll;
}

void Player::setBankroll(double money)
{
	bankroll = money;
}

double Player::getBetAmmount()
{
	return betAmmount;
}

void Player::setBetAmmount(double ammount)
{
	betAmmount = ammount;
}

int Player::getHandValue(vector<Card>* hand)
{
	int handVal = 0;

	for(int i=0; i < hand->size(); i++)
	{
		handVal += hand->at(i).getVal();
	}

	return handVal;
}
