/* HW07 Blackjack

Author: Mason English

Description: Make a game of blackjack run by the computer
*/

#include <iostream>
#include <string>
#include <ctime>

using namespace std;

struct Card {
    int rank;
    int suit;
};

Card deck[51];

/*
Origional Deck Index Key
0-9 = hearts
10-19 = Clubs
20-29 = Diamonds
30-39 = Spades

J,Q,K
40,41,42 = hearts(face)
43,44,45 = Clubs (face)
46,47,48 = Diamonds (face)
49,50,51 = Spades (face)
*/


/*
* Converts a number between 0 and 3 to a corresponding
* playing card suit
*/
string ConvertIntToSuit(int suitNum) {
    switch (suitNum) {
    case 0:
        return "Hearts";
        break;
    case 1:
        return "Clubs";
        break;
    case 2:
        return "Diamonds";
        break;
    case 3:
    default:
        return "Spades";
        break;
    }
}


 int PrintCard(Card card) {
   
    if ((card.rank > 10) || (card.rank == 1))  { // Prints Card Rank
        if(card.rank == 11) {
            cout << "Jack";
        }
        if (card.rank == 12) {
            cout << "Queen";
        }
        if (card.rank == 13) {
            cout << "King";
        }
        if (card.rank == 1) {
            cout << "Ace";
        }
    }
    else {
        cout << card.rank;
    }

    cout << " of ";

    cout << ConvertIntToSuit(card.suit);


    return 0;
}

 Card Shuffle(Card deck[51]) { // Shuffles deck (swaps cards 5200 times)
     Card placeholder;

     for (int j = 0; j < 100; j++) {
         for (int i = 0; i < 52; i++) {
             int spot = rand() % 52;
             placeholder = deck[i];
             deck[i] = deck[spot];
             deck[spot] = placeholder;
         }
     }
     return deck[51];
 }

int IfFaceCard(int& count, int cValue) {    //Corects Player value for face cards
    if (cValue == 11) {
        count = (count - 1);
    }
    if (cValue == 12) {
        count = (count - 2);
    }
    if (cValue == 13) {
        count = (count - 3);
    }
    return 0;
}

int main() {
    srand(time(NULL));

    for (int i = 0; i <= 39 ; i++) { // Assigns number values 1-10 to first 40 cards
        deck[i].rank = (i % 10 + 1);
    }

    for (int j = 40; j <= 51; j++) { // Assigns face card values to 40-51
        deck[j].rank = ((j - 1) % 3 + 11);
    }

    for (int k = 0; k <= 51; k++) { // Assigns suit int values
        if (((k >= 0) && (k <= 9)) || ((k <= 42) && (k >= 40))) {
            deck[k].suit = 0;
        }
        if (((k >= 10) && (k <= 19)) || ((k <= 45) && (k >= 43))) {
            deck[k].suit = 1;
        }
        if (((k >= 20) && (k <= 29)) || ((k <= 48) && (k >= 46))) {
            deck[k].suit = 2;
        }
        if (((k >= 30) && (k <= 39)) || ((k <= 51) && (k >= 49))) {
            deck[k].suit = 3;
        }
       }

    string choice = "Yes";


    cout << "Would you like to play blackjack? ( Yes or No)" << endl; //Intro to game
    cin >> choice;
    if (choice == "No") {
        return 0;
    }


    while (choice == "Yes") { //Each Loop =  a new game
       
        cout << endl << endl;

        Shuffle(deck);

        int place = 0;
        int dealerTotal2 = 0;
        int dealerTotal = 0;
        int playerTotal = 0;
        int playerTotal2 = 0;


        cout << "Dealer was dealt the ";   //Dealer's first tun
        
        PrintCard(deck[place]);
        cout << " ." << endl;

        dealerTotal = dealerTotal + deck[place].rank; 
        IfFaceCard(dealerTotal, deck[place].rank);
        cout << "Dealer total is " << dealerTotal << endl;
        place = place + 1;

        cout << "You were dealt the ";
        PrintCard(deck[place]); 
        cout << " ." << endl;

        playerTotal = playerTotal + deck[place].rank;  //Player's first turn
        IfFaceCard(playerTotal, deck[place].rank);
        cout << "Your total is " << playerTotal << endl;
        place = place + 1;

        string cardChoice = "Hit";

        //Start Player Turn
        while ((playerTotal <= 21) && ((cardChoice == "Hit") || (cardChoice == "hit"))) {

            cout << "You were dealt the "; //Player Receives Card
            PrintCard(deck[place]);
            cout << "." << endl;

            playerTotal = playerTotal + deck[place].rank; //States new total
            IfFaceCard(playerTotal, deck[place].rank);
            place = place + 1;
            
            cout << "Your total is " << playerTotal << endl;

            if (playerTotal > 21) {
                cout << "You busted!! Dealer wins." << endl << endl;
            }
            if (playerTotal <= 21) {
                cout << "Would you like to Hit or Stand?" << endl;
                cin >> cardChoice;
            }
            playerTotal2 = playerTotal;
        }

        cout << endl << endl;    

        //Start Dealer's Turn
        if (playerTotal <= 21) {
            while (dealerTotal < 17) {

                cout << "Dealer was dealt the ";
                PrintCard(deck[place]);
                cout << "." << endl;
                IfFaceCard(dealerTotal, deck[place].rank);
                place = place + 1;

                dealerTotal = dealerTotal + deck[place].rank; //States new total
                cout << "Dealer total is " << dealerTotal << endl << endl;


                dealerTotal2 = dealerTotal;
            }

            // Possible outcomes
            if (dealerTotal > 21) {
                cout << "Dealer busted!! You win!" << endl;
            }
            if ((dealerTotal >= playerTotal2) && (dealerTotal <= 21)) {
                cout << "Dealer wins." << endl;
            }
            if (dealerTotal < playerTotal2) {
                cout << "You win!!!" << endl;
            }
        }
        cout << "Would you like to play again? ( Yes or No)" << endl; //Intro to game
        cin >> choice;
        if (choice == "No") {
            return 0;
        }
    }
    
    return 0;
}
