/*
 * Blake Adams
 * 11/9/18
 * player.cpp
 * Lab 6: Go Fish
 */


#include <iostream>
#include <ctime>
#include <cstdlib>
#include "player.h"

using namespace std;

    Player::Player()
    {
        myName = "";
        myHand = vector<Card>();
        myBook = vector<Card>();
        unsigned int currentTime = (unsigned)time(0);
        srand(currentTime);
    }

    Player::Player(string name) {
        myName = name;
        myHand = vector<Card>();
        myBook = vector<Card>();
        unsigned int currentTime = (unsigned)time(0);
        srand(currentTime);
    }


    void Player::addCard(Card c)
    {
        myHand.push_back(c);
    }

    void Player::bookCards(Card c1, Card c2)
    {
        myBook.push_back(c1);
        myBook.push_back(c2);
    }

    bool Player::checkHandForBook(Card &c1, Card &c2)
    {
        bool found = false;
        for (int i = 0; i<getHandSize()-1; i++)
        {
            for (int j = i+1; j<getHandSize(); j++)
            {
                if (!found && myHand[i].getRank()==myHand[j].getRank())
                {
                    c1 = myHand[i];
                    c2 = myHand[j];
                    found = true;
                }
            }
        }
        return found;
    }

    bool Player::rankInHand(Card c) const
    {
        bool found = false;
        for (int i =0; i<getHandSize(); i++)
        {
            if (myHand[i].getRank()==c.getRank())
                found = true;
        }
        return found;
    }

    Card Player::chooseCardFromHand() const
    {
        int index =  (rand()%getHandSize());
        return myHand[index];
    }

    Card Player::removeCardFromHand(Card c)
    {
        Card temp;
        bool found = false;
        for (int i = 0; i<getHandSize(); i++)
        {
            if (!found && myHand[i].getRank() == c.getRank())
            {
                temp = myHand[i];
                myHand.erase(myHand.begin()+i);
                found = true;
            }
        }
        return temp;
    }



    string Player::showHand() const
    {
        string hand;
        for (int i = 0; i<getHandSize();i++)
        {
            hand.append(myHand[i].toString() + " ");
        }
        return hand;
    }

    int Player::getBookSize() const
    {
        return myBook.size();
    }

    int Player::getHandSize() const
    {
        return myHand.size();
    }

    string Player::showBooks() const
    {
        string books;
        for (int i = 0; i<getBookSize();i+=2)
        {
            books.append(myBook[i].toString() + ",");
            books.append(myBook[i+1].toString() + " " );
        }
        return books;
    }
