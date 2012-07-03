/*
 * Card.cpp
 *
 *  Created on: Jun 14, 2012
 *      Author: nrobinso
 */
#include "Card.h"
#include <sstream>

Card::Card()
{
}

Card::Card(int suitVal, int val)
{
	mySuit = Suit(suitVal);
	myFaceVal = Face(val);
}

int Card::getVal()
{
	if(myFaceVal > 10)
		return 10;
	else if(myFaceVal == 0)
		return 11;
	else
		return myFaceVal;
}

int Card::getSuit()
{
	return mySuit;
}

void Card::setSuit(Suit val)
{
	mySuit = val;
}

void Card::setVal(Face val)
{
	myFaceVal = val;
}

std::string Card::getValStr(int num)
{
	std::stringstream ss;
	ss << num;
	return ss.str();
}



