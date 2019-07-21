// name: Tanner Bonds, tjb0057
// partner: None
// filename: hw5.cpp
// due date: 10/05/2018
// collaboration: I did not use any external sources for this assignment.
// compliation: compile with g++ compiler.
// problem: Write a program to simulate a trivia game,
//     taking user questions and answers.

#include <iostream>
#include <string>
#include <cstdlib>
#include <cassert>
using namespace std;

//#define UNIT_TESTING

//Remove comment to run test cases.


struct TriviaNode {

   string quest;
   string ans;
   int point;
  

};

typedef TriviaNode* TriviaNPoint;
int score = 0;

class TriviaList {

public:

   TriviaList(){}
   TriviaList(string question, string answer, int points, TriviaList* links)
   
   {node.quest = question; node.ans = answer; node.point = points; link = links;}
   
   
   string getQuestion()
   {
      return node.quest;
      
   }
   void setQuestion(string question)
   
   {node.quest = question;}
   
   string getAnswer()
   {
      return node.ans;
   } 
   void setAnswer(string answer)
   
   {node.ans = answer;}
   
   int getPoints() 
   {
      return node.point;
   }
      
   void setPoints(int points)
   
   {node.point = points;} 
        
   TriviaList* getLink()
   {
      return link;
   }
      
   void setLink(TriviaList* pointer) 
   
   {link = pointer;}   
             

private:

   TriviaNode node;
   TriviaList* link;

};

typedef TriviaList* TriviaLPoint;

   
TriviaLPoint initialList() {

   TriviaLPoint read;
   string quest;
   string ans;
   int points = 0;



   quest = "What is the best-selling video game of all time? (Hint: Call of Duty or Wii Sports)";
   ans = "Wii Sports";
   points = 20;
   read = new TriviaList(quest, ans, points, NULL);
   
   quest = "What was Bank of America's original name? (Hint: Bank of Italy or Bank of Germany)";
   ans = "Bank of Italy";
   points = 50;
   read = new TriviaList(quest, ans, points, read);

   quest = "How long was the shortest war on record? (Hint: how many minutes)";
   ans = "38";
   points = 100;
   read = new TriviaList(quest, ans, points, read);
   return read;
}

TriviaLPoint Add(string question, string answer, int points, TriviaLPoint links) {

   TriviaLPoint read;
   read = new TriviaList(question, answer, points, links);
   return read;
}

int Quiz(TriviaLPoint list, int questNum) {

   if (questNum <= 0) {
      cout << "Warning – The number of trivia to be asked must equal to or larger \nthan 1.\n\n";
      return 1;
   
   }
   
   else if (list == NULL) {
   
      return 1;
   
   }
   
   else {
   
      TriviaLPoint read = list;
      TriviaLPoint nextLink = read -> getLink();
      int i = 1;
   
      while (nextLink != NULL) {
      
         nextLink = nextLink -> getLink();
         i++;
      
      }
   
      if (i < questNum) {
      
         return 1;
      
      }
      
      else {
      
         nextLink = read;
         string ans;
         int j = 0;
      
         do {
         
            cout << "Question: " << nextLink -> getQuestion() << endl;
            cout << "Answer: ";
            getline(cin, ans);
         
         
         
            if (ans == "") {
            
               getline(cin, ans);
            
            }
         
            if (ans == nextLink -> getAnswer()) {
            
               cout << "Your answer is correct. You receive " << nextLink -> getPoints() << " points.\n";
               score += nextLink -> getPoints();
               
            }
            
            else {
            
               cout << "Your answer is wrong. The correct answer is: " << nextLink -> getAnswer() << "\n";
            
            }
         
            cout << "Your total points : " << score << "\n\n";
            nextLink = nextLink -> getLink();
            j++;
         
         }
         
         while (nextLink != NULL && j < questNum);
         return 0; 
         
      }
   }
}

TriviaLPoint Trivia(TriviaLPoint list) {

   TriviaLPoint read = list;
   string quest;
   string ans;
   int points;

   cout << "Enter a question: ";
   getline(cin, quest);
   cout << "Enter an answer: ";
   getline(cin, ans);
   cout << "Enter award points: ";

   while (!(cin >> points) || (points <= 0)) {
   
      cout << "Point number must be greater than 0 ";
      cin.clear(); 
      cin.ignore(1000, '\n');
   
   }

   read = Add(quest, ans, points, read);
   cin.clear();
   cin.ignore(1000, '\n');
   return read;

}

void testInitialList(){

   TriviaLPoint read = initialList();
   cout << "\tInitial List Test\n\n";


   cout << "Question 1: How long was the shortest war on record? (Hint: how many \nminutes)\n";
   cout << "Answer: 38\n";
   
   assert("How long was the shortest war on record? (Hint: how many minutes)" == read -> getQuestion());
   assert("38" == (read -> getAnswer()));
   assert(100 == (read -> getPoints()));
   TriviaLPoint read1 = read -> getLink();
   cout << "Question 1 passes...\n\n";
   
   
   cout << "Question 2: What was Bank of America's original name? (Hint: \nBank of Italy or Bank of Germany)\n";
   cout << "Answer: Bank of Italy\n";
   
   assert("What was Bank of America's original name? (Hint: Bank of Italy or Bank of Germany)" == read1 -> getQuestion());
   assert("Bank of Italy" == (read1 -> getAnswer()));
   assert(50 == (read1 -> getPoints()));
   TriviaLPoint read2 = read1 -> getLink();

   cout << "Question 2 passes...\n\n";
   
           
    

   cout << "Question 3: What is the best-selling video game of all time? (Hint: \nCall of Duty or Wii Sports)\n";
   cout << "Answer: Wii Sports\n";
   assert("What is the best-selling video game of all time? (Hint: Call of Duty or Wii Sports)" == read2 -> getQuestion());
   assert("Wii Sports" == (read2 -> getAnswer())); 
   assert(20 == (read2 -> getPoints()));
   cout << "Question 3 passes...\n\n";
      
         
   
}

void testAdd(){

   cout << "Test of Add function with empty list\n";

   TriviaLPoint read = NULL;
   read = Add("testq", "testa", 5, read);

   assert("testq" == read -> getQuestion());
   assert("testa" == read -> getAnswer());
   assert(5 == read -> getPoints());
   assert(NULL == read -> getLink());

   cout << "Add with empty list passed\n\n";
   cout << "Test of Add function with known list\n\n";

   read = Add("test1q", "test1a", 8, read);

   assert("test1q" == read -> getQuestion());
   assert("test1a" == read -> getAnswer());
   assert(8 == read -> getPoints());

   TriviaLPoint read1 = read -> getLink();

   assert("testq" == read1 -> getQuestion());
   assert("testa" == read1 -> getAnswer());
   assert(5 == read1 -> getPoints());
   assert(NULL == read1 -> getLink());

   cout << "Add w/ known list passed\n\n";

}

void testQuiz(){

   TriviaLPoint read = initialList();
   int testList;  
      

   cout << "Unit Test Case 1: Ask no question. \n\tThe program should give a warning message.\n\n";
   testList = Quiz(read, 0);   
   


   cout << "Unit Test Case 2.1: Ask 1 question in the linked list. The tester \nenters an incorrect answer.\n";
   testList = Quiz(read, 1);
   assert(score == 0);        
   cout << "Case 2.1 passed...\n\n";
   
   cout << "Unit Test Case 2.2: Ask 1 question in the linked list. The tester \nenters a correct answer.\n";
   testList = Quiz(read, 1);
   assert(score == 100);    
   cout << "Case 2.2 passed...\n\n";
          
          
    
   cout << "Unit Test Case 3.1: Ask all the questions of the last trivia in the \nlinked list with incorrect answers.\n";     
   score = 0;
   testList = Quiz(read, 3);
   assert(score == 0);        
   cout << "Case 3.1 passed...\n\n";
      
   cout << "Unit Test Case 3.2: Ask all the questions of the last trivia in the \nlinked list with correct answers.\n";
   testList = Quiz(read, 3);
   assert(score == 170);  
   cout << "Case 3.2 passed...\n\n";
   
   int numQuest = 5;
   cout << "Unit Test Case 4: Ask five questions in the linked list.\n";
   testList = Quiz(read, 5);
   cout << "Case 4 passed...\n\n";


}

void testTrivia(){

   cout << "Trivia test. \nPlease enter the following: \nQuestion: What is your favorite movie?\nAnswer: The Martian\nPoints: 50\n";

   TriviaLPoint read = NULL;
   read = Trivia(read);
   
   assert("What is your favorite movie?" == read -> getQuestion());
   assert("The Martian" == read -> getAnswer());
   assert(50 == read -> getPoints());
   
   cout << "Test passed\n\n";

}


int main() {

#ifdef UNIT_TESTING

   cout << "*** This is a debugging version ***\n";

   testInitialList();
   testAdd();
   testQuiz();
   testTrivia();
   
   cout << "*** End of the Debugging Version ***\n";
   
   #else

   cout << "Welcome to Tanner Bonds' trivia quiz game ***\n";
   
   TriviaLPoint read = NULL;
   string contin;
   string in;
   cout << "Do you wish to create your own trivia questions? (Yes/No): ";
   getline(cin, in); 
   
   while (in != "Yes" && in != "No") {
      cout << "Please enter (Yes/No): ";
      getline(cin, in);
      
   }
   
   if (in == "Yes") {
   
      do {
      
         read = Trivia(read);
      
         cout << "Continue? (Yes/No): ";
         getline(cin, contin);
      
         while (contin != "No" && contin != "Yes") {
         
            cout << "Please enter (Yes/No): ";
            getline(cin, contin);
         }
      }
      
      while (contin == "Yes"); 
      cout << endl;
   }
   
   else {
   
      read = initialList();
   
   }
   
   
   int numQuest;
   int quiz;
   cout << "Please enter the number of questions \nyou would like to answer: ";
   cin >> numQuest;
   
   quiz = Quiz(read, numQuest);  
   
   while (quiz == 1) {
   
      cout << "Number of questions invalid. \nPlease try again: ";
      cin >> numQuest;
      quiz = Quiz(read, numQuest);
   
   }
   
   cout << "*** Thank you for playing the trivia quiz game. Goodbye! ***";
   

   #endif
}