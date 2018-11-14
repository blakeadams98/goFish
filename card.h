/*
 * Blake Adams
 * 11/9/18
 * card.h
 * Lab 6: Go Fish
 */

//File Name: card.h
//
//Written by Owen Astrachan and Roger Priebe
// This class represents a playing card, i.e., "ace of spades"
// a Card is constructed from a rank (int in range 1..13)
// and a suit (Card::spades, Card::hearts, Card::diamonds,
// Card::clubs)
//
// Cards should be created by a Deck (see deck.h), a Deck returns
// good cards
// The function toString() converts a card to a string, e.g., to print
//
// Accessor functions include
//
// int GetRank()      -- returns 1, 2, ..., 13 for ace, two, ..., king
//
// bool SameSuitAs(c) -- returns true if same suit as Card c
//
// string suitString() -- returns "s", "h", "d" or "c"
//
// Note that the Ace is represented by 1 and the King by 13

#ifndef _CARD_H
#define _CARD_H

#include <iostream>
#include <string>
using namespace std;

class Card
{
public:


    enum Suit {spades, hearts, diamonds, clubs};

    /*
     * Default Constructor that creates a card
     * Default card is an ace of spades
     */
    Card();          // default, ace of spades

    /*
     * Constructor with parameters
     * Creates a card with a defined rank and suitd
     */
    Card(int rank, Suit s);

    /*
     * Name: toString
     * Description: Returns a string representation of the card
     * Input: N/A
     * Output: the card in a string format
     */
    string toString()              const;  // return string version e.g. Ac 4h Js

    /*
     * Name: sameSuitAs
     * Description: Returns whether or not a card has the same suit as another card
     * Input: const Card& c, the card to compare to
     * Output: Whether or not the cards have the same suit
     */
    bool sameSuitAs(const Card& c) const;  // true if suit same as c

    /*
     * Name: getRank
     * Description: Returns the rank of the card
     * Input: N/A
     * Output: the rank of the card
     */
    int  getRank()                 const;  // return rank, 1..13

    /*
     * Name: suitString
     * Description: Returns a string representation of the card's suit
     * Input: Suit s, the numerical suit value
     * Output: the suit in a string format
     */
    string suitString(Suit s)      const;  // return "s", "h",...

    /*
     * Name: rankString
     * Description: Returns a string representation of the card's rank
     * Input: int r, the numerical rank value
     * Output: the rank in a string format
     */
    string rankString(int r)       const;  // return "A", "2", ..."Q"


    bool operator == (const Card& rhs) const;
    bool operator != (const Card& rhs) const;



private:

    int myRank;
    Suit mySuit;


};

ostream& operator << (ostream& out, const Card& c);



#endif