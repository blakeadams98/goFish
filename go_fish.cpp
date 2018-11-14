#include <iostream>
#include <cstdlib>
#include <fstream>
#include "card.h"
#include "deck.h"
#include "player.h"

using namespace std;


void dealHand(Deck &d, Player &p, int numCards);
bool inquiry(Player &p1, Player &p2, ostream &out);
void bookCheck(Player &p1, ostream &out);
void drawCard(Deck &d, Player &p1, ostream &out);
void gameStatus(Player &p1, Player &p2, ostream &out);

static const int NUMCARDS = 7;
static const int DECKSIZE = 52;

int main(int argc, char *argv[])
{

    ofstream goFish;
    goFish.open("gofish_results.txt");


    Player p1("Joe");
    Player p2("Jane");

    Deck d;
    d.shuffle();
    int remainingCards = DECKSIZE;

    dealHand(d,p1,NUMCARDS);
    dealHand(d,p2,NUMCARDS);
    remainingCards -= (NUMCARDS*2);


    gameStatus(p1, p2, goFish);

    //CHECK FOR BOOKS
    goFish << endl;

    bookCheck(p1,goFish);
    bookCheck(p1,goFish);
    bookCheck(p1,goFish);
    bookCheck(p2,goFish);
    bookCheck(p2,goFish);
    bookCheck(p2,goFish);

    goFish << endl;

    gameStatus(p1,p2,goFish);


    goFish << endl;

    /*Program will run until the deck is out of cards or one of the players has
     *14 books (meaning they won). A successful call results in another turn
     *until the player has an unsuccessful call or runs out of cards, at which
     *point they will draw from the deck and end their turn.
     */
    while (remainingCards>0 && p1.getBookSize()<28 && p2.getBookSize()<28)
    {
        while  (p1.getHandSize()>0 && inquiry(p1,p2,goFish))
        {
        }
        drawCard(d,p1,goFish);
        remainingCards--;

        goFish << endl;

        while (p2.getHandSize()>0 && inquiry(p2,p1,goFish))
        {
        }
        drawCard(d,p2,goFish);
        remainingCards--;

        goFish << endl;

        gameStatus(p1,p2,goFish);

        goFish<<endl;
    }

    if (p1.getBookSize()>=p2.getBookSize())
    {
        goFish << p1.getName() << " is the winner!!" << endl;
    }
    else
        goFish << p2.getName() << " is the winner!!" << endl;

    goFish.close();

    return EXIT_SUCCESS;
}


void dealHand(Deck &d, Player &p, int numCards)
{
    for (int i = 0; i<numCards; i++)
    {
        p.addCard(d.dealCard());
    }
}

bool inquiry(Player &p1, Player &p2, ostream& out)
{
    bool success = false;
    Card c = p1.chooseCardFromHand();
    out << p1.getName() << " asks - Do you have a " << c.rankString(c.getRank()) << "?" << endl;

    if (p2.rankInHand(c))
    {
        out << p2.getName() << " says - Yes. I have a " << c.rankString(c.getRank()) << endl;
        p1.bookCards(p2.removeCardFromHand(c),p1.removeCardFromHand(c));
        out << p1.getName() << " books the " << c.rankString(c.getRank()) << endl;
        success = true;
    }
    else
    {
        out << p2.getName() << " says - Go Fish" << endl;
    }
    return success;
}

void bookCheck(Player &p1, ostream &out)
{
    Card c1;
    Card c2;
    if (p1.checkHandForBook(c1,c2))
    {
        p1.bookCards(p1.removeCardFromHand(c1),p1.removeCardFromHand(c2));
        out << p1.getName() << " books the " << c1.rankString(c1.getRank()) << "'s" << endl;
    }

}

void drawCard(Deck &d, Player &p1, ostream &out)
{
    Card c = d.dealCard();
    p1.addCard(c);
    out << p1.getName() << " draws " << c.toString() << endl;
    bookCheck(p1,out);

}

void gameStatus(Player &p1, Player &p2, ostream &out)
{
    out << p1.getName() << " has : " << p1.showHand() << endl;
    out << p2.getName() << " has : " << p2.showHand() << endl;

    out << p1.getName() << "'s books are :\t" << p1.showBooks() << endl;
    out << p2.getName() << "'s books are :\t" << p2.showBooks() << endl;
}
