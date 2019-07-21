// name: Tanner Bonds, tjb0057
// partner: None
// filename: hw1.cpp
// due date: 08/31/2018
// collaboration: I did not use any external sources for this assignment.
// compliation: compile with g++ compiler.
// problem: determine how much diet soda it is possible to drink
//    without dying as a result.

#include <iostream>
using namespace std;

const double RATE = 0.001;

int main() {

   double yourWeight;
   double lethalKillMouse;
   double mouseWeight;
   double numOfSoda;

   cout << "What is the amount of artifical sweetner needed to kill a mouse:\n";
   cin >> lethalKillMouse;

   cout << "\nWhat is the weight of the mouse: ";
   cin >> mouseWeight;
   
   cout << "\nWhat is the weight of the dieter: ";
   cin >> yourWeight;
   
   numOfSoda = (lethalKillMouse / mouseWeight) * (yourWeight / RATE);
   
   cout << "\nYou can drink " << numOfSoda << " diet soda without dying as a result.";
   return 0;

}