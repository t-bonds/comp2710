// name: Tanner Bonds, tjb0057
// partner: None
// filename: hw3.cpp
// due date: 09/14/2018
// collaboration: I did not use any external sources for this assignment.
// compliation: compile with g++ compiler.
// problem: Write a program to simulate duel between three people,
//  each with different probabilities of winning.
   
#include <iostream>
#include <stdlib.h>
#include <assert.h>
#include <ctime>
using namespace std;
   
   
const double AARON_STAT = 33; 
const double BOB_STAT = 50;
const double CHARLIE_STAT = 100;
    
   
bool at_least_two_alive(bool aaronAlive, bool bobAlive, bool charlieAlive){
   
   if ((aaronAlive && bobAlive && charlieAlive) ||
       ((!aaronAlive) && bobAlive && charlieAlive) ||
       (aaronAlive && (!bobAlive) && charlieAlive) ||
       (aaronAlive && bobAlive && (!charlieAlive))) {
       
      return true;
       
   }
      
   return false;
   
} 
   
bool shoot(int accuracy) {
   bool shot = false;
   int hit = (rand() % 100);
   if (hit <= accuracy) {
   
      shot = true;
   
   }
   else { 
      shot = false;
   }
   return shot;
}
   
   
void Aaron_shoots1(bool& bobAlive, bool& charlieAlive) {
   bool shot;
   assert(bobAlive || charlieAlive);
  
   if (charlieAlive == true) {
   
      shot = shoot(AARON_STAT);
   
      if (shot == true) {
      
         charlieAlive = false;
      
      }
   }
   else if (bobAlive == true) {
   
      shot = shoot(AARON_STAT);
   
      if (shot == true) {
      
         bobAlive = false;
      
      }
   }
}

void Aaron_shoots2(bool& bobAlive, bool& charlieAlive) {
   bool shot;
   int i = 0;
   assert(bobAlive || charlieAlive);
  
   if (charlieAlive == true && i == 0) {
   
      i++;
              
   }
   
   else if (charlieAlive == true && i <= 1) {
   
      shot = shoot(AARON_STAT);
   
      if (shot == true) {
      
         charlieAlive = false;
      
      }
   }
   
         
   else if (bobAlive == true) {
   
      shot = shoot(AARON_STAT);
   
      if (shot == true) {
      
         bobAlive = false;
      
      }
   }
}

void Bob_shoots(bool& aaronAlive, bool& charlieAlive) {
   bool shot;
   assert(aaronAlive || charlieAlive);
  
   if (charlieAlive == true) {
   
      shot = shoot(BOB_STAT);
   
      if (shot == true) {
      
         charlieAlive = false;
      
      }
   }
   else if (aaronAlive == true) {
   
      shot = shoot(BOB_STAT);
   
      if (shot == true) {
      
         aaronAlive = false;
      
      }
   }
}


void Charlie_shoots(bool& aaronAlive, bool& bobAlive){

   assert(aaronAlive || bobAlive);

   if (bobAlive == true) {
   
      bobAlive = false;
   
   }
   
   else {
   
      aaronAlive = false;
   
   }
}


void test_at_least_two_alive(void) {
   cout << "Unit Testing 1: Function – at_least_two_alive()\n";
   
   cout << "\tCase 1: Aaron alive, Bob alive, Charlie alive\n";
   assert(true == at_least_two_alive(true, true, true));
   cout << "\tCase passed ...\n";
   
   cout << "\tCase 2: Aaron dead, Bob alive, Charlie alive\n";
   assert(true == at_least_two_alive(false, true, true));
   cout << "\tCase passed ...\n";
   
   cout << "\tCase 3: Aaron alive, Bob dead, Charlie alive\n";
   assert(true == at_least_two_alive(true, false, true)); 
   cout << "\tCase passed ...\n";
   
   cout << "\tCase 4: Aaron alive, Bob alive, Charlie dead\n";
   assert(true == at_least_two_alive(true, true, false)); 
   cout << "\tCase passed ...\n";
   
   cout << "\tCase 5: Aaron dead, Bob dead, Charlie alive\n";
   assert(false == at_least_two_alive(false, false, true)); 
   cout << "\tCase passed ...\n";

   cout << "\tCase 6: Aaron dead, Bob alive, Charlie dead\n";
   assert(false == at_least_two_alive(false, true, false)); 
   cout << "\tCase passed ...\n";

   cout << "\tCase 7: Aaron alive, Bob dead, Charlie dead\n";
   assert(false == at_least_two_alive(true, false, false)); 
   cout << "\tCase passed ...\n";
   
   cout << "\tCase 8: Aaron dead, Bob dead, Charlie dead\n";
   assert(false == at_least_two_alive(false, false, false)); 
   cout << "\tCase passed ...\n";


}


  

void test_Aaron_shoots1(void){

   cout << "Unit Testing 2: Function Aaron_shoots1(Bob_alive, Charlie_alive)\n";

   bool aaronAlive = true;
   bool bobAlive = true;
   bool charlieAlive = true;

   cout << "\tCase 1: Bob alive, Charlie alive\n";
   cout << "\t\tAaron is shooting at Charlie\n";
      
   Aaron_shoots1(bobAlive, charlieAlive);


   if (charlieAlive == false) {
   
      cout << "\t\tCharlie is dead\n";
   
   }
   
   else {
   
      cout << "\t\tAaron misses\n";
   
   }

   cout << "\tCase 2: Bob dead, Charlie alive\n";
   cout << "\t\tAaron is shooting at Charlie\n";
   
   bobAlive = false;
   charlieAlive = true;
   Aaron_shoots1(bobAlive, charlieAlive);
 
   if (charlieAlive == false) {
   
      cout << "\t\tCharlie is dead\n";
   
   }
   
   else {
   
      cout << "\t\tAaron misses\n";
   
   }
   
   cout << "\tCase 3: Bob alive, Charlie dead\n";
   cout << "\t\tAaron is shooting at Bob\n";
   
   bobAlive = true;
   charlieAlive = false;
   Aaron_shoots1(bobAlive, charlieAlive);
 
   if (bobAlive == false) {
   
      cout << "\t\tBob is dead\n";
   
   }
   
   else {
   
      cout << "\t\tAaron misses\n";
   
   } 
}


void test_Bob_shoots(void) {

   cout << "Unit Testing 3: Function Bob_shoots(Aaron_alive, Charlie_alive)\n";

   bool aaronAlive = true;
   bool bobAlive = true;
   bool charlieAlive = true;

   cout << "\tCase 1: Aaron alive, Charlie alive\n";
   cout << "\t\tBob is shooting at Charlie\n";
   
   Bob_shoots(aaronAlive, charlieAlive);
   
   if (charlieAlive == false) {
   
      cout << "\t\tCharlie is dead\n";
   
   }
   
   else {
   
      cout << "\t\tBob misses\n";
   
   } 

   cout << "\tCase 2: Aaron dead, Charlie alive\n";
   cout << "\t\tBob is shooting at Charlie\n";
   
   aaronAlive = false;
   charlieAlive = true;
   Bob_shoots(aaronAlive, charlieAlive);
 
   if (charlieAlive == false) {
   
      cout << "\t\tCharlie is dead\n";
   
   }
   
   else {
   
      cout << "\t\tBob misses\n";
   
   }
   
   cout << "\tCase 3: Aaron alive, Charlie dead\n";
   cout << "\t\tBob is shooting at Aaron\n";
   
   aaronAlive = true;
   charlieAlive = false;
   Bob_shoots(aaronAlive, charlieAlive);
 
   if (aaronAlive == false) {
   
      cout << "\t\tAaron is dead\n";
   
   }
   
   else {
   
      cout << "\t\tBob misses\n";
   
   } 
}

void test_Charlie_shoots(void) {

   cout << "Unit Testing 4: Function Charlie_shoots(Aaron_alive, Bob_alive)\n";

   bool aaronAlive = true;
   bool bobAlive = true;
   bool charlieAlive = true;

   cout << "\tCase 1: Aaron alive, Bob alive\n";
   cout << "\t\tCharlie is shooting at Bob\n";
   
   Charlie_shoots(aaronAlive, bobAlive);
   
   if (bobAlive == false) {
   
      cout << "\t\tBob is dead\n";
   
   }
   
   else {
   
      cout << "\t\tCharlie misses, an impossible feat\n";
   
   } 

   cout << "\tCase 2: Aaron dead, Bob alive\n";
   cout << "\t\tCharlie is shooting at Bob\n";
   
   aaronAlive = false;
   bobAlive = true;
   Charlie_shoots(aaronAlive, bobAlive);
 
   if (bobAlive == false) {
   
      cout << "\t\tBob is dead\n";
   
   }
   
   else {
   
      cout << "\t\tCharlie misses, an impossible feat\n";
   
   }
   
   cout << "\tCase 3: Aaron alive, Bob dead\n";
   cout << "\t\tCharlie is shooting at Aaron\n";
   
   aaronAlive = true;
   bobAlive = false;
   Charlie_shoots(aaronAlive, bobAlive);
 
   if (aaronAlive == false) {
   
      cout << "\t\tAaron is dead\n";
   
   }
   
   else {
   
      cout << "\t\tCharlie misses, an impossible feat\n";
   
   } 
}

   

void test_Aaron_shoots2(void) {
   cout << "Unit Testing 5: Function Aaron_shoots2(Bob_alive, Charlie_alive)\n";
    
   bool aaronAlive = true;
   bool bobAlive = true;
   bool charlieAlive = true;

   cout << "\tCase 1: Bob alive, Charlie alive\n";
   cout << "\t\tAaron is shooting at Charlie\n";
      
   Aaron_shoots2(bobAlive, charlieAlive);


   if (charlieAlive == false) {
   
      cout << "\t\tCharlie is dead\n";
   
   }
   
   else {
   
      cout << "\t\tAaron intentionally misses his first shot\n";
      cout << "\t\tBoth Bob and Charlie are alive\n";
   
   }

   cout << "\tCase 2: Bob dead, Charlie alive\n";
   cout << "\t\tAaron is shooting at Charlie\n";
   
   bobAlive = false;
   charlieAlive = true;
   Aaron_shoots2(bobAlive, charlieAlive);
 
   if (bobAlive == false) {
   
      cout << "\t\tCharlie is dead\n";
   
   }
   
   else {
   
      cout << "\t\tAaron misses\n";
      
   
   }
   
   cout << "\tCase 3: Bob alive, Charlie dead\n";
   cout << "\t\tAaron is shooting at Bob\n";
   
   bobAlive = false;
   charlieAlive = true;
   Aaron_shoots2(bobAlive, charlieAlive);
 
   if (bobAlive == false) {
   
      cout << "\t\tBob is dead\n";
   
   }
   
   else {
   
      cout << "\t\tAaron misses\n";
   
   } 

    
}

 
       
int main() {

   srand(time(0));

   cout << "*** Welcome to Puzzlevania's Duel Simulator ***\n";
   
   test_at_least_two_alive();
   cout << "Press any key to continue...";
   cin.ignore().get();

   test_Aaron_shoots1();
   cout << "Press any key to continue...";
   cin.ignore().get();
   
   test_Bob_shoots();
   cout <<  "Press any key to continue...";
   cin.ignore().get();
   
   test_Charlie_shoots();
   cout <<  "Press any key to continue...";
   cin.ignore().get();
   
   test_Aaron_shoots2();
   cout << "Press any key to continue...";
   cin.ignore().get();

   cout << "Ready to test strategy 1 (run 10000 times):\n";
   cout << "press any key to continue...";
   cin.ignore().get();
          
   cout << "...\n...\n...\n\n";

   int aaronSurvive = 0;
   int bobSurvive = 0;
   int charlieSurvive = 0;

   for (int i = 0; i < 10000; i++) {
   
      bool aaronAlive = true;
      bool bobAlive = true;
      bool charlieAlive = true;
   
   
      while (at_least_two_alive(aaronAlive, bobAlive, charlieAlive)) {
      
         if (aaronAlive) {
         
            Aaron_shoots1(bobAlive, charlieAlive);
         
         }
         
         if (bobAlive) {
         
            Bob_shoots(aaronAlive, charlieAlive);
         
         }
                     
         if (charlieAlive) {
         
            Charlie_shoots(aaronAlive, bobAlive);
         
         }
         
                     
      }
         
      if (aaronAlive) {
         
         aaronSurvive++;
         
      }
         
      else if (bobAlive) {
         
         bobSurvive++;
         
      }
         
      else if (charlieAlive) {
         
         charlieSurvive++;
         
      }
      
   }
   
   double aaronWinRate = aaronSurvive * .01;
   double bobWinRate = bobSurvive * .01;
   double charlieWinRate = charlieSurvive * .01;

   
   cout << "Aaron won " << aaronSurvive << "/10000 duels or  " << aaronWinRate << "%\n";
   cout << "Bob won " << bobSurvive << "/10000 duels or  " << bobWinRate << "%\n";
   cout << "Charlie won " << charlieSurvive << "/10000 duels or  " << charlieWinRate << "%\n\n";
    
   
           
          
   cout << "Ready to test strategy 2 (run 10000 times):\n";
   cout << "press any key to continue...";
   cin.ignore().get();
   
   cout << "...\n...\n...\n\n";

   int aaronSurvive2 = 0;
   int bobSurvive2 = 0;
   int charlieSurvive2 = 0;
   
   for (int i = 0; i < 10000; i++) {
   
      bool aaronAlive = true;
      bool bobAlive = true;
      bool charlieAlive = true;
      
   
      while (at_least_two_alive(aaronAlive, bobAlive, charlieAlive)) {
      
         if (aaronAlive) {
         
            Aaron_shoots2(bobAlive, charlieAlive);
         
         }
         
         if (bobAlive) {
         
            Bob_shoots(aaronAlive, charlieAlive);
         
         }
                     
         if (charlieAlive) {
         
            Charlie_shoots(aaronAlive, bobAlive);
         
         }
         cout << endl;
                     
      }
         
      if (aaronAlive) {
         
         aaronSurvive2++;
         
      }
         
      else if (bobAlive) {
         
         bobSurvive2++;
         
      }
         
      else if (charlieAlive) {
         
         charlieSurvive2++;
         
      }
      
   
   }
   
   double aaronWinRate2 = aaronSurvive2 * .01;
   double bobWinRate2 = bobSurvive2 * .01;
   double charlieWinRate2 = charlieSurvive2 * .01;
   
   cout << "Aaron won " << aaronSurvive2 << "/10000 duels or  " << aaronWinRate2 << "%\n";
   cout << "Bob won " << bobSurvive2 << "/10000 duels or  " << bobWinRate2 << "%\n";
   cout << "Charlie won " << charlieSurvive2 << "/10000 duels or  " << charlieWinRate2 << "%\n";
   
   if (aaronSurvive > aaronSurvive2) {
   
      cout << "\nStrategy 1 is better than strategy 2.\n";
   
   }
   
   else {
   
      cout << "\nStrategy 2 is better than strategy 1.\n";
   
   
   }
   
   return 0;
}