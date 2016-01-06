#include <cstring>
#include <iostream>

using namespace std;

int one_pair(std::string card_combo)
{
    unsigned found;
    unsigned i;

    for(i=0; i<card_combo.size()-2; i=i+2)                 // +2 because card type are at even positions and suit and odd positions
    {
        found = card_combo.find(card_combo[i]);


        if(found!=-1u && found!=i)
        {
            return 1;
        }

    }

return 0;
}



int two_pair(std::string card_combo)
{
    unsigned found;
    unsigned i;
    unsigned k;
    unsigned found_2;

    for(i=0; i<card_combo.size()-2; i=i+2)                 // +2 because card type are at even positions and suit and odd positions
    {
        found = card_combo.find(card_combo[i]);


        if(found!=-1u && found!=i)
        {

            for(k=0; k<card_combo.size()-2; k=k+2)
            {
             found_2 = card_combo.find(card_combo[k]);

                if (found_2!=-1u && found_2!=k && k!=i)
                    return 1;
            }

        }

    }

return 0;
}





int three_pair(std::string card_combo)
{
    unsigned found;
    unsigned i;
    unsigned found_2;

    for(i=0; i<card_combo.size()-2; i=i+2)                 // +2 because card type are at even positions and suit and odd positions
    {
        found = card_combo.find(card_combo[i]);
        found_2 = card_combo.find_last_of(card_combo[i]);

        if (found!=-1u && found!=i && found_2!=found && found_2!=i)        //Last condition is required to prevent last occurrence
                                                                           //of card number to be mistaken with
            {
                return 1;
            }


    }

return 0;
}






int straight(std::string card_combo)
{
    int card_number[5];
    unsigned i;
    int minimum;
    int straight_sum;
    int actual_sum = 0;                  //Default value

    for (i=0; i<card_combo.size(); i=i+2)                    // Loop converts string chars into int to be used for math operations
    {
        if (card_combo[i] == 'A')
            card_number[i/2] = 14;

            else if(card_combo[i] == 'K')
                card_number[i/2] = 13;

                else if(card_combo[i] == 'Q')
                   card_number[i/2] = 12;

                    else if(card_combo[i] == 'J')
                       card_number[i/2] = 11;

                       else if(card_combo[i] == 'T')
                          card_number[i/2] = 13;

                          else if(card_combo[i] == '9')
                            card_number[i/2] = 9;

                             else if(card_combo[i] == '8')
                                  card_number[i/2] = 8;

                                else if(card_combo[i] == '7')
                                    card_number[i/2] = 7;

                                    else if(card_combo[i] == '6')
                                         card_number[i/2] = 6;

                                        else if(card_combo[i] == '5')
                                            card_number[i/2] = 5;

                                          else if(card_combo[i] == '4')
                                               card_number[i/2] = 4;

                                             else if(card_combo[i] == '3')
                                                  card_number[i/2] = 3;

                                                else if (card_combo[i] == '2')
                                                      card_number[i/2] = 2;



    }

    minimum  = card_number[0];         // Setting default minimum value;

    for(i=0; i<5; i++)
    {
        if(card_number[i]<minimum)
            minimum = card_number[i];
    }

    straight_sum = (5*minimum) + 10;    // Straight is 4 more consecutive cards values from minimum which is
                                       // minimum +(minimum+1) + (minimum+2) + (minimum+3) + (minimum+4) = (5*minimum)+10

    for(i=0; i<5; i++)
        actual_sum = actual_sum + card_number[i];


    if (actual_sum == straight_sum)
        return 1;


return 0;
}





int pflush(std::string card_combo)
{
    if (card_combo[1]== card_combo[3] && card_combo[1]== card_combo[5]
        && card_combo[1]== card_combo[7] && card_combo[1]== card_combo[9])      //Make sure suit is the same
    {
        return 1;
    }

 return 0;
}






int full_house(std::string card_combo)
{
    unsigned found;
    unsigned i;
    unsigned found_2;
    string numbers = "";
    string cut;

   for(i=0; i<card_combo.size(); i = i+2)       //Loading all numbers into different string to simplify logic
    numbers = numbers + card_combo.at(i);



    for(i=0; i<numbers.size(); i++)              // +2 because card type are at even positions and suit and odd positions
    {
        found = numbers.find(numbers[i]);
        found_2 = numbers.find_last_of(numbers[i]);

        if (found!=-1u && found!=i && found_2!=found && found_2!=i)
           {
               cut = numbers[i];

               while(numbers.find(cut)!=-1u)                               //While it can still find "cut", keep erasing cu
               {
                   numbers.erase(numbers.find(cut), 1);

               }


               if (numbers[0] == numbers[1])
                 return 1;
           }


    }


    return 0;
}






int four_kind(std::string card_combo)
{
    if(card_combo[2] == card_combo[4] && card_combo[2] == card_combo[6] && card_combo[2] == card_combo[8])
        return 1;
       else if(card_combo[0] == card_combo[4] && card_combo[0] == card_combo[6] && card_combo[0] == card_combo[8])
          return 1;
         else if(card_combo[0] == card_combo[2] && card_combo[0] == card_combo[6] && card_combo[0] == card_combo[8])
            return 1;
            else if(card_combo[0] == card_combo[2] && card_combo[0] == card_combo[4] && card_combo[0] == card_combo[8])
               return 1;
               else if(card_combo[0] == card_combo[2] && card_combo[0] == card_combo[4] && card_combo[2] == card_combo[6])
                  return 1;
                  else
                    return 0;
}







int straight_flush(std::string card_combo)
{
    if(straight(card_combo) && pflush(card_combo))
        return 1;


    return 0;
}

