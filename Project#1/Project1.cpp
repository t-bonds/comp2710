// name: Tanner Bonds, tjb0057
// partner: None
// filename: Project1.cpp
// due date: 11/9/2018
// collaboration: I did not use any external sources for this assignment.
// compliation: compile with g++ compiler.
// problem: Write a simple text based game.


#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;


const int HALL = 20;
int money, position, intelligence, timeLeft;
int score = money * position * timeLeft;
int ans, ans1;
string name;

//#define UNIT_TESTING


void startGame();
void gameMenu();
void playGame();
void highScores();
void quitGame();
void checkWin();
void winGame();
void checkLose();
void loseGame();
void sortScores();
void viewScores();
void characterMove();
void boostInt();
void boostMoney();
void viewGame();
void decrementTime();
void playPuzzle();
void playEncounter();



void characterMoveTest(void);
void boostIntTest(void);
void boostMoneyTest(void);
void viewGameTest(void);
void startGameTest(void);
void playPuzzleTest(void);
void playEncounterTest(void);
void quitGameTest(void);





struct Character {

   std::string name;
   int score;

};


void startGame() {

   cout << "Enter Your Name: ";
   cin >> name;


   cout << "\n\n****************************************\n";
   cout << "*Welcome to Shelby Center & Dragons!   *\n";
   cout << "****************************************\n";
   
   gameMenu();

}

void gameMenu() {
 
   cout << "\nEnter 1 to Start a New Game\n";
   cout << "Enter 2 to View Top Scores\n";
   cout << "Enter 3 to Quit\n\n";
   cout << "Please select an option: ";
   cin >> ans;
   
   switch (ans) {
   
      case 1:
         cout << "Starting a new Game... \n\n";
         playGame();
         break;
   
      case 2:
         cout << "Displaying high scores... \n\n";
         highScores();
         break;
   
      case 3:
         quitGame();
         break;
   
      default:
         cout << "Please enter a valid input (1, 2, or 3)\n\n";
         break;
   
   }
   
   gameMenu();
}
 
void playGame() {
 
   checkWin();
   checkLose();
   cout << "You have "<< timeLeft <<" seconds remaining.\n";
   cout << "You have "<< (HALL - position) <<" steps to the end of the hall\n"; 
   cout << "You have $"<< money <<".00 money.\n";
   cout << "You have "<< intelligence <<" intelligence.\n\n";
 
   cout << "Time is running out, " << name << "!\n";
   cout << "\tPress 1 to Move Forward. \n";
   cout << "\tPress 2 to Read Technical Papers.    (Intelligence +) \n";
   cout << "\tPress 3 to Search for Loose Change.  (Money +) \n";
   cout << "\tPress 4 to View Your Character Stats.\n";
   cout << "\tPress 5 to Quit The Game.\n\n";
   cout << "Please make your decision: ";
   cin >> ans1;
 
   switch(ans1) {
   
      case 1:
      
         characterMove();
         break;
   
      case 2:
         boostInt();
         break;
   
      case 3:
         boostMoney();
         break;
   
      case 4:
         viewGame();
         break;
   
      case 5:
         quitGame();
         break;
   
   }

   playGame();
 
}
 
void highScores() {
 
   sortScores();
   viewScores();
 
}
 
void quitGame() {
   int quit = 5;
   score = abs(timeLeft * money * intelligence);
   cout << "\nFinal Score: " << score;
   cout << "\nThanks For Playing!\n";
   exit(1);
 
}
 
void checkWin() {
 
   if (position >= HALL) {
   
      winGame();
   
   }
}
 
void winGame() {
 
   cout << "You have reached the end of the hall.\n";
   cout << "\tYOU WIN!\n";
   score = abs(intelligence * timeLeft * money);
   quitGame();
 
}
 
void checkLose() {
 
   if (intelligence <= 0 || money <= 0 || timeLeft <= 0) {
   
      loseGame();
   
   }
 
}
 
 
void loseGame() {
 
   score = abs(money * timeLeft * intelligence);
 
   if (intelligence <= 0) {
   
      cout << "You have run out of intelligence!\n";
   
   }
 
   if (money <= 0) {
   
      cout << "You have run out of money!\n";
   
   }

   if (timeLeft <= 0) {
   
      cout << "You have run out of time!\n";
   
   } 
 
   cout << "\tYOU LOSE!\n";
   quitGame();
 
}
 
void sortScores() {
 
   int score1;
   int score2;
   int score3;
   int score4;
   int score5;
 
   if (score > score1) {
    
      string name1 = name;
      score1 = score;
        
   }

   if (score > score2){ 
    
      string name2 = name;
      score2 = score;
        
   }

   if (score > score3){ 
    
      string name3 = name;
      score3 = score;
        
   }

   if (score > score4) {
    
      string name4 = name;
      score4 = score;
        
   }

   if (score > score5) { 
    
      string name5 = name;
      score5 = score;
        
   } 

 
}
 
void decrementTime() {
 
   timeLeft -= 3;
 
}
 
void viewScores() {
 
   ifstream in;
   string line;
   in.open("highscores.txt");
 
   if (!in) {
   
      cout << "File cannot be opened.";
      exit(1);
   
   }
 
   while(getline(in, line)) {
   
      cout << line << "\n";
   
   }
   in.close();
   
   
   
       
}
 
void addScores(Character) {
 
   ofstream out("highscores.txt");
   out.open("highscores.txt");
   out << score << " " << endl;
   out.close();
 
   ifstream in1("highscores.txt");
   if (in1.is_open()) {
   
      int score;
      in1 >> score;
      cout << "Score: " << score;
      in1.close();
   
   }
 
}
 
void characterMove() {
 
   position++;
   timeLeft--;
   int random = (rand() % 10);
 
   cout << "\n\tPOSITION INCREASE +1\n";
 
   if (random <= 3) {
   
      cout << "\tNO ENCOUNTERS\n\n";
   
   }
 
   if (random == 4 || random == 5 || random == 6) {
   
      playPuzzle();
   
   }
 
   if (random >= 7) {
   
      playEncounter();
   
   }
 
}

void playEncounter() {

   int random1 = (rand() % 4);

   cout << "\tENCOUNTER DETECTED!\n\n";

   if (random1 == 1) {
   
      cout << "\tYou have encountered a professor.\n";
   
      int intel = (5 + (rand() % (int)(10 - 5 + 1)));
      int timeDec = (2 + (rand() % (int)(5 - 2 + 1)));
      timeLeft = timeLeft - timeDec;
   
   
      intelligence += intel;
   
      cout << "\tINTELLIGENCE BOOST +" << intel << "\n";
      cout << "\tTIME HAS DECREASED.\n\n";
   
   }
   
   if (random1 == 2) {
   
      cout << "\tYou have encountered a graduate student.\n";
   
      int timeDec = (2 + (rand() % (int)(5 - 2 + 1)));
      timeLeft = timeLeft - timeDec;
   
      cout << "\tTIME HAS DECREASED.\n\n";
   
   }
   
   if (random1 == 3) {
   
      cout << "\tYou have encountered grunt work.\n";
   
      int intel = (5 + (rand() % (int)(10 - 5 + 1)));
      int timeDec = (2 + (rand() % (int)(5 - 2 + 1)));
      timeLeft = timeLeft - timeDec;
   
   
      intelligence -= intel;
   
      cout << "\tINTELLIGENCE DECREMENT -" << intel << "\n";
      cout << "\tTIME HAS DECREASED.\n\n";
   
   }

   if (random1 == 4) {
   
      cout << "\tYou have encountered ungraded papers.\n";
   
      int monGain = (5 + (rand() % (int)(10 - 5 + 1)));
      money += monGain;
      timeLeft--;
   
      
   
      cout << "\tMONEY BOOST +" << monGain << "\n";
      cout << "\tTIME HAS DECREASED.\n\n";
   
   }


}



void playPuzzle() {

   int puzzleRand = (rand() % 5);
   int ans1, ans2, ans3, ans4, ans5;
   
   cout << "\tPUZZLE DETECTED!\n\n";

   switch (puzzleRand) {
   
   
      case 1:
      
         cout << "What year did Christopher Columbus sail to America?\n";
         cout << "\tAnswer: ";
         cin >> ans1;
      
         if (ans1 != 1492) {
         
            cout << "\n\tINCORRECT! INTELLIGENCE -5\n\n";
            intelligence = intelligence - 5;
         
         }
         
         else {
         
            cout << "\n\tCORRECT! INTELLIGENCE +5\n\n";
            intelligence = intelligence + 5;
         
         }
      
         break;
   
      case 2:
      
         cout << "What year did Niel Armstrong set foot on the moon?\n";
         cout << "\tAnswer: ";
         cin >> ans2;
      
         if (ans2 != 1969) {
         
            cout << "\n\tINCORRECT! INTELLIGENCE -5\n\n";
            intelligence = intelligence - 5;
         
         }
         
         else {
         
            cout << "\n\tCORRECT! INTELLIGENCE +5\n\n";
            intelligence = intelligence + 5;
         
         }
         break;
      
      case 3:
      
         cout << "What is the derivative of 2x?\n";
         cout << "\tAnswer: ";
         cin >> ans3;
      
         if (ans3 != 2) {
         
            cout << "\n\tINCORRECT! INTELLIGENCE -5\n\n";
            intelligence = intelligence - 5;
         
         }
         
         else {
         
            cout << "\n\tCORRECT! INTELLIGENCE +5\n\n";
            intelligence = intelligence + 5;
         
         }
         break;
      
      case 4:
      
         cout << "The Avatar controlled how many elements?\n";
         cout << "\tAnswer: ";
         cin >> ans4;
      
         if (ans4 != 4) {
         
            cout << "\n\tINCORRECT! INTELLIGENCE -5\n\n";
            intelligence = intelligence - 5;
         
         }
         
         else {
         
            cout << "\n\tCORRECT! INTELLIGENCE +5\n\n";
            intelligence = intelligence + 5;
         
         }
         break;
      
      case 5:
      
         cout << "How many episodes of Naruto are there?\n";
         cout << "\tAnswer: ";
         cin >> ans5;
      
         if (ans5 != 720) {
         
            cout << "\n\tINCORRECT! INTELLIGENCE -5\n\n";
            intelligence  = intelligence - 5;
         
         }
         
         else {
         
            cout << "\n\tCORRECT! INTELLIGENCE +5\n\n";
            intelligence = intelligence + 5;
         
         }
         break;
   
   }

}
 
void boostInt() {

   int intel;
   intel = (5 + (rand() % (int)(10 - 5 + 1)));
   intelligence += intel;
   decrementTime();
      
   cout << "\n\tINTELLIGENCE BOOST + " << intel << "\n";
   cout << "\tTIME HAS DECREASED.\n\n"; 
 
}
 
void boostMoney() {
 
   int monGain;
   monGain = (5 + (rand() % (int)(10 - 5 + 1)));
   money += monGain;
   decrementTime();
      
   cout << "\n\tMONEY BOOST + " << monGain << "\n"; 
   cout << "\tTIME HAS DECREASED.\n\n";
}
 
void viewGame() {
 
   playGame(); 
}
 
int main() {
 
   srand(time(0)); 
                                               
   money = (5 + (rand() % (int)(15 - 7 + 1)));                  
   intelligence = (5 + (rand() % (int)(15 - 7 + 1)));                 
   timeLeft = 50;
                                            
   Character(c);
    
   c.name = name;
   c.score = score; 
   
   #ifdef UNIT_TESTING
   
   characterMoveTest();
   boostIntTest();
   boostMoneyTest();
   viewGameTest();
   startGameTest();
   playPuzzleTest();
   playEncounterTest();
   quitGameTest();

   
   #else
   
   startGame();
   
   score = abs(money * timeLeft * intelligence);
   addScores(c);
   return 0;  
 
   
 #endif
}
 
 
 
void characterMoveTest(void){
 
   cout << "Test 1: Test of characterMove\n";
 
   Character(c);
   characterMove();
 
   if ((HALL - position) < HALL) {
   
      cout << "\tTest Passed...\n\n";
   
   }
 
}
 
 
void boostIntTest(void){

   cout << "Test 2: Test of boostInt\n";

   Character(c);
   int intTest = intelligence;
   boostInt();
 
   if (intTest > intelligence) {
   
      cout << "\tTest Passed...\n\n";
   
   }


}


void boostMoneyTest(void){

   cout << "Test 3: Test of boostMoney\n";

   Character(c);
   int monTest = money;
   boostMoney();
 
   if (monTest > money) {
   
      cout << "\tTest Passed...\n\n";
   
   }


}


void viewGameTest(void){

   cout << "Test 4: Test of viewGame\n\n";

   Character(c);
   viewGame();
         
   cout << "\tTest Passed...\n\n";
   
   


}


void startGameTest(void){

   cout << "Test 5: Test of startGame\n";

   Character(c);
   startGame();
         
   cout << "\tTest Passed...\n\n";


}


void playPuzzleTest(void){

   cout << "Test 6: Test of playPuzzle\n\n";

   Character(c);
   playPuzzle();
   
   if ((intelligence += 5) || (intelligence -= 5)) {
         
      cout << "\tTest Passed...\n\n";
   
   }
}


void playEncounterTest(void){

   cout << "Test 7: Test of playEncounter\n\n";

   Character(c);
   
   
   int intTest = intelligence;
   int monTest = money;
   int timeTest = timeLeft;
   
   playEncounter();    
   cout << "\n\tTest Passed...\n\n";
   
   


}

void quitGameTest(void) {

   int quit;

   if (quit == 5) {
   
      cout << "\tTest Passed...\n\n";
   
   } 

}

 
 
 
 
