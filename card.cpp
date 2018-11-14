/*
 * Blake Adams
 * 11/9/18
 * card.cpp
 * Lab 6: Go Fish
 */

#include "card.h"

using namespace std;

    Card::Card()
    {
        myRank = 1;
        mySuit = Card::spades;
    }

    Card::Card(int rank, Card::Suit s)
    {
        if (rank<14&&rank>0)
            myRank = rank;
        else
            myRank = 1;

        if (s>0)
            mySuit = s;
        else
            mySuit = Card::spades;
    }

    string Card::toString() const
    {
        return rankString(myRank) + suitString(mySuit);
    }

    bool Card::sameSuitAs(const Card &c) const
    {
        return (c.mySuit==mySuit);
    }

    int Card::getRank() const
    {
        return myRank;
    }

    string Card::suitString(Card::Suit s) const
    {
        switch(s)
        {
            case clubs:
                return "c";
            case diamonds:
                return "d";
            case hearts:
                return "h";
            default:
                return "s";
        }
    }

    string Card::rankString(int r) const
    {
        switch(r)
        {
            case 1:
                return "A";
            case 2:
                return "2";
            case 3:
                return "3";
            case 4:
                return "4";
            case 5:
                return "5";
            case 6:
                return "6";
            case 7:
                return "7";
            case 8:
                return "8";
            case 9:
                return "9";
            case 10:
                return "10";
            case 11:
                return "J";
            case 12:
                return "Q";
            default:
                return "K";
        }
    }

    bool Card::operator == (const Card& rhs) const
    {
        return (myRank==rhs.myRank && mySuit==rhs.mySuit);
    }

    bool Card::operator!=(const Card &rhs) const
    {
        return (myRank!=rhs.myRank||mySuit!=mySuit);
    }