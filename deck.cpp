/*
 * Blake Adams
 * 11/9/18
 * deck.cpp
 * Lab 6: Go Fish
 */



#include <iostream>
#include <ctime>
#include <cstdlib>
#include "deck.h"

using namespace std;

    Deck::Deck()
    {
        int countCard = 0;
        for (int i = 0; i<4;i++)
        {
            for (int j = 1; j<14; j++)
            {
                Card c = Card(j,Card::Suit(i));
                myCards[countCard] = c;
                countCard++;
            }
        }
        myIndex = SIZE-1;
        unsigned int currentTime = (unsigned)time(0);
        srand(currentTime);
    }

    void Deck::shuffle()
    {
        int numCards = size();
        if (numCards>1)
        {
            for (int i = 0; i<numCards; i++)
            {
                int indexOne = (rand()%numCards);
                int indexTwo = (rand()%numCards);
                Card temp = myCards[indexOne];
                myCards[indexOne] = myCards[indexTwo];
                myCards[indexTwo] = temp;
            }
        }
    }

    Card Deck::dealCard()
    {
        if (size()>0)
        {
            Card c = myCards[myIndex];
            myIndex--;
            return c;
        }
        else
            cout<<"FAILED"<<endl;
    }

    int Deck::size() const
    {
        return myIndex+1;
    }

