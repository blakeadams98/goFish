/*
 * Blake Adams
 * 11/9/18
 * player.h
 * Lab 6: Go Fish
 */

// FILE:  player.h
// written by Roger Priebe
// 1/22/08 (revised 9/2/08)
// This class represents a player in a card game that takes "tricks"
// The "Books" represent a container for holding tricks

#ifndef _PLAYER_H
#define _PLAYER_H

#include <iostream>
#include <string>
#include <vector>
#include "card.h"

using namespace std;


class Player
{
public:

    /*
     * Default Constructor
     * Creates a player with an empty name
     */
    Player();

    /*
     * Constructor with parameter
     * Creates a player with a specified name
     */
    Player(string name);

    /*
     * Name: getName
     * Description: Returns the name of the player
     * Input: N/A
     * Output: the name of the player
     */
    string getName() const {
        return myName;
    }

    /*
     * Name: addCard
     * Description: adds a card to the players hand
     * Input: Card c, the card to be added
     * Output: N/A
     */
    void addCard(Card c);  //adds a card to the hand

    /*
     * Name: bookCards
     * Description: Places two cards into the players book
     * Input: Card c1, Card c2, the two cards to be booked
     * Output: N/A
     */
    void bookCards(Card c1, Card c2);


    /*
     * Name: checkHandForBook
     * Description: checks if there are any books in the players hands and if there are,
     * populates the two variables with them
     * Input: Card &c1, Card &c2, the locations of two card variables
     * Output: Whether or not there were any books in the hand
     */
    bool checkHandForBook(Card &c1, Card &c2);

    /*
     * Name: rankInHand
     * Description: returns whether or not the player has a certain rank in their hand
     * Input: Card c, the card to check
     * Output: Whether or not the player had that rank in their hand
     */
    bool rankInHand(Card c) const;

    /*
     * Name: chooseCardFromHand
     * Description: randomly chooses a card from the player's hand
     * Input: N/A
     * Output: A card from the player's hand
     */
    Card chooseCardFromHand() const;

    /*
     * Name: removeCardFromHand
     * Description: Removes a specified from the player's hand and returns it
     * Input: Card c, the card to be removed
     * Output: The card that was removed
     */
    Card removeCardFromHand(Card c);

    /*
     * Name: showHand
     * Description: Returns a string representation of the player's hand
     * Input: N/A
     * Output: a string of the player's hand
     */
    string showHand() const;

    /*
     * Name: showBooks
     * Description: Returns a string representation of the player's books
     * Input: N/A
     * Output: a string of the player's books
     */
    string showBooks() const;

    /*
     * Name: getHandSize
     * Description: Returns the number of cards in the player's hand
     * Input: N/A
     * Output: The number of cards in the player's hand
     */
    int getHandSize() const;

    /*
     * Name: getBookSize
     * Description: Returns the number of cards in the player's book
     * Input: N/A
     * Output: The number of cards in the player's book
     */
    int getBookSize() const;



private:

    vector <Card> myHand;
    vector <Card> myBook;

    string myName;

};


#endif