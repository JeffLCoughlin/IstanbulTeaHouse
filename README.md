# IstanbulTeaHouse
Code to calculate best bet on the TeaHouse in the board game Istanbul

Compile via g++ -O2 -o teahouse TeaHouse.cpp

and run

./teahouse

By default it will calculate, when having the Mosque card allowing the chance a die to 4 or re-roll, the chance of making each possible bet, and the average Lira obtained per encounter.

To run the code without the Mosque card, set CARD = 0.

Results with the Mosque card are:

Bet  ChanceOfMakingBet(%)  AvgLiraPerTurn

2 100 2
3 100 3

4 100 4

5 100 5

6 99.2 5.97

7 95.3 6.77

8 85.4 7.12

9 67.9 6.75

10 44.5 5.56

11 16 3.44

12 5.51 2.55



Results without are:

Bet  ChanceOfMakingBet(%)  AvgLiraPerTurn

2 100 2

3 100 3

4 100 4

5 100 5

6 99.2 5.97

7 95.3 6.77

8 85.4 7.12

9 67.9 6.75

10 44.5 5.56

11 16 3.44

12 5.51 2.55

