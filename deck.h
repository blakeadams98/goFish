/*
 * Blake Adams
 * 11/9/18
 * deck.h
 * Lab 6: Go Fish
 */

// FILE: deck.h
// written by Owen Astrachan and Roger Priebe
// this class respresents a deck of cards
// When a Deck is constructed, it contains 52 cards
// in a "regular" order (aces, twos, threes, ... , kings)
//
// Shuffling a deck will randomize whatever cards are in the deck
// Do not shuffle if you have less than 2 cards
//
// dealCard() returns a card from the deck and decreases the
// number of cards in the deck (returned by size())
// The idea is that after shuffling, calling dealCard() 52 times
// returns each card in the deck after shuffling.
//

#ifndef _DECK_H
#define _DECK_H

#include "card.h"


class Deck
{
    static const int SIZE = 52;

public:

    /*
     * Default Constructor
     * Creates a deck of 52 cards
     */
    Deck();           // pristine, sorted deck

    /*
     * Name: shuffle
     * Description: Shuffles the cards in the deck
     * Input: N/A
     * Output: N/A
     */
    void shuffle();   // shuffle the cards in the current deck

    /*
     * Name: dealCard
     * Description: Returns a card from the deck if there are cards remaining
     * Input: N/A
     * Output: a Card from the deck
     */
    Card dealCard();   // get a card, after 52 are dealt, fail

    /*
     * Name: size
     * Description: Returns the number of cards remaining in the deck
     * Input: N/A
     * Output: The number of cards left in the deck
     */
    int  size() const; // # cards left in the deck

private:

    Card myCards[SIZE];
    int myIndex;  // current card to deal
};

#endif