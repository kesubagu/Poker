#include <iostream>
#include <cstring>
#include "analyzer.h"



void advisor_main();
void combo_type(std::string combination_1);


using namespace std;

int main()
{
    int option;
   do
   {
      cout << endl << "Hello! Please select one of the following options" << endl;
      cout << "1. Poker advisor" << endl;
      cout << "2. Instructions" << endl;
      cout << "3. Quit" << endl;

      cin >> option;

  switch(option){

  case 1:
      advisor_main();
      break;

  case 2:
      cout << "Here are the instructions." << endl;
      break;

  case 3:
    option = -1;
    break;

  default:
    cout << "Please enter a valid number" << endl;


      }
   }
   while(option!=-1);

return 0;
}

void advisor_main()
{
    int number_of_opponents;
    string hand_card[2];
    string the_flop[3];
    string combination_1;


    cout << "How many people are you playing against?"<< endl;
    cin >> number_of_opponents;

    cout << "Cards on hand please" << endl;
    cin >> hand_card[0] >> hand_card[1];

    cout << "Enter cards from the flop" << endl;
    cin >> the_flop[0] >> the_flop[1] >> the_flop[2];

    combination_1 = hand_card[0] + hand_card[1] + the_flop[0] + the_flop[1] + the_flop[2];

    //cout << "The combination on hand is " << combination_1 << endl;
    combo_type(combination_1);


}

void combo_type(string combination_1)
{
    if(straight_flush(combination_1))
        cout << "Got a straight flush!" << endl;

        else if(four_kind (combination_1))
            cout << "Got four of a kind!" << endl;

          else if(full_house (combination_1))
             cout << "Got a full house!" << endl;

            else if(pflush (combination_1))
                cout << "Got a flush!" << endl;

                else if(straight(combination_1))
                   cout << "Got a straight!" << endl;

                  else if(three_pair(combination_1))
                    cout << "Got three of a kind!" << endl;

                    else if(two_pair(combination_1))
                      cout << "Got two pair!" << endl;

                      else if(one_pair(combination_1))
                        cout << "Got a pair!" << endl;

                        else
                          cout << "Got a high card!" <<endl;


}
