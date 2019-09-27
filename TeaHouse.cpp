#include <iomanip>
#include <iostream>
#include <random>

using namespace std;

mt19937 randgen(1337);  // Intialize random number generator

int ROLLDICE();  // Roll two dice and return the sum
void SWAP(int &,int &);  // Swap two numbers
uniform_real_distribution<double> dist;  // Generates a random number between 0 and 1.

const int CARD = 1;  // Set to 1 if you have the Mosque card, else 0
const int NMC = 1000000;  // Number of Monte Carlo runs

int main ()
  {
  int i, bet, sum, maderoll, d1, d2;

  cout << "Bet  ChanceOfMakingBet(%)  AvgLiraPerTurn" << endl;

  for(bet=2;bet<=12;bet++)  // Loop through each bet possible
    {
    sum=0;
    maderoll=0;
    for(i=0;i<NMC;i++)
      {
      d1 = ROLLDICE();  // Roll the dice
      d2 = ROLLDICE();

      if(d1>d2)
        SWAP(d1,d2);  // Force d1 to be the smaller die

      if(CARD==1)  // If you have the mosque card
        if(d1 + d2 < bet)  // If the first dice roll didn't win the bet
          {
          if(d1+d2 < bet && max(d1,4)+d2>=bet)  // If changing one die to 4 will make the bet, do it
            d1=4;
          else  // Else, re-roll
            {
            d1 = ROLLDICE();
            d2 = ROLLDICE();
            }
          }

      if(d1 + d2 >= bet)  // If you made or beat your bet, get that many
        {
        sum+=bet;
        maderoll+=1;
        }
      else                // Else, you get 2 Lira
        sum+=2;
      }
    cout << bet << " " << setprecision(3) <<  100.0*maderoll/NMC << " " << 1.0*sum/NMC << endl;
    }

  exit(0);
  }


int ROLLDICE()
  {
  return int(6*dist(randgen)+1);
  }

void SWAP(int &a, int &b)
  {
  b = a + b;
  a = b - a;
  b = b - a;
  }
