// name: Tanner Bonds, tjb0057
// partner: None
// filename: hw3.cpp
// due date: 09/21/2018
// collaboration: I did not use any external sources for this assignment.
// compliation: compile with g++ compiler.
// problem: Write a program to take file input and sort 
//    the resulting numbers within each file.


#include <fstream>
#include <iostream>
#include <cstdlib>
#include <string>
#include <cassert>
using namespace std;

string fileName;
const int MAX_SIZE = 100;



int readFile(int inputArray[], ifstream& inStream){ 

   int index = 0;
   inStream >> inputArray[index];
    
   while (! inStream.eof()) {
      index++;
      inStream >> inputArray[index];
      
   }
   return index;
}




      
int sort(int iArray1[], int iArray1Size, int iArray2[], int iArray2Size, int finalArray[]) {

   int i = 0;
   int j = 0;
   int k = 0;
   int finalArraySize;

   finalArraySize = (iArray1Size) + (iArray2Size);

   while (i < iArray1Size && j < iArray2Size) {
   
      if (iArray1[i] < iArray2[j]) {
      
         finalArray[k] = iArray1[i];
         i++;
         k++;
      
      }
      
      else {
      
         finalArray[k] = iArray2[j];
         j++;
         k++; 
        
      }
   }

   if (i == iArray1Size) {
   
      while (j < iArray2Size) {
      
         finalArray[k] = iArray2[j];
         j++;
         k++;
      
      } 
   }
   
   else {
   
      while (i < iArray1Size) {
      
         finalArray[k] = iArray1[i];
         i++;
         k++;
      
      }
   }
   
   assert(k == finalArraySize);
   return finalArraySize;

}





void writeFile(int finalArray[], int finalArraySize, ofstream& ostream) {

   for (int i = 0; i <= finalArraySize; i++) {
   
      ostream << finalArray[i] << endl;
   
   }
}




void sortTest(void) {

   ifstream istream;

   int testArray[MAX_SIZE];
   int testArray1[MAX_SIZE];
   int testArray2[MAX_SIZE];
   
   int testArraySize;
   int testArraySize1;
   int testArraySize2;
   
   int outArray[MAX_SIZE];
   int outArray1[MAX_SIZE];
   int outArray2[MAX_SIZE];
   
   int sort1;
   int sort2;
   int sort3;
   
   std::string fileName1 = "test1.txt";
   std::string fileName2 = "test2.txt";
   std::string fileName3 = "test3.txt";

   istream.open(fileName1.c_str());
   testArraySize = readFile(testArray, istream);
   istream.close();
   
   istream.open(fileName2.c_str());
   testArraySize1 = readFile(testArray1, istream);
   istream.close();
   
   istream.open(fileName3.c_str());
   testArraySize2 = readFile(testArray2, istream);
   istream.close();
   
         


   cout << "Unit Test Case 2: Function Name - sortTest.\n";
   cout << "\tCase 2.1: test1.txt, test2.txt (Equal Size - Shared Integer)\n";
   
   sort1 = sort(testArray, testArraySize, testArray1, testArraySize1, outArray);
   assert(sort1);
   
   cout << "\tCase Passed\n\t...\n";
   cout << "Press any key to continue...";
   cin.ignore().get();
   
   cout << "\tCase 2.2: test2.txt, test3.txt (Different Size)\n";

   sort2 = sort(testArray1, testArraySize1, testArray2, testArraySize2, outArray1);
   assert(sort2);

   cout << "\tCase Passed\n\t...\n";
   cout << "Press any key to continue...";
   cin.ignore().get();
   
   cout << "\tCase 2.3: test1.txt, test3.txt (Different Size)\n";

   sort3 = sort(testArray, testArraySize, testArray2, testArraySize2, outArray2);
   assert(sort3);

   cout << "\tCase Passed\n\t...\n";
      

}





void writeFileTest(void) {

   std::string fileName = "test1.txt";
   std::string fileOut = "test4.txt";
   ifstream istream;
   ofstream ostream;
   int testArray[MAX_SIZE];
   int testArray1[MAX_SIZE];
   int testArraySize;
   int testArraySize1;
   
   cout << "Unit Test Case 3: Function Name - writeFileTest.\n";
   cout << "\tCase 3.1: test1.txt rewrite to new file.\n";
   
   istream.open(fileName.c_str());
   testArraySize = readFile(testArray, istream);
   istream.clear();
   istream.close();

   ostream.open((char*)fileOut.c_str());

   writeFile(testArray, testArraySize, ostream);
   ostream.close();
   
   istream.open(fileOut.c_str());
   testArraySize1 = readFile(testArray1, istream);
   istream.close();
    
   assert(testArraySize1 != 0);
   cout << "\tCase Passed\n\t...\n";
            
}





void readFileTest(void) {

   cout << "Unit Test Case 1: Function Name - readFileTest.\n";
   cout << "\tCase 1.1: test1.txt - 5 integers\n";
   int testArray[MAX_SIZE];
   int testArraySize;
   int assert;
   int assert1;
   int assert2;
   ifstream istream;
   
   std::string fileName1 = "test1.txt";
   std::string fileName2 = "test2.txt";
   std::string fileName3 = "test3.txt";
   
   
   
   istream.open(fileName1.c_str());
   assert = readFile(testArray, istream);
   istream.close();
   assert(assert);
   
   cout << "\tCase Passed\n\t...\n";
   cout << "Press any key to continue...";
   cin.ignore().get();

   
   cout << "\tCase 1.2: test2.txt - 5 integers (1 equal integer with test1)\n";
   
   istream.open(fileName2.c_str());
   assert1 = readFile(testArray, istream);
   istream.close();
   assert(assert1);
   
   cout << "\tCase Passed\n\t...\n";
   cout << "Press any key to continue...";
   cin.ignore().get();

   cout << "\tCase 1.3: test3.txt - 8 integers\n";

   istream.open(fileName3.c_str());
   assert2 = readFile(testArray, istream);
   istream.close();
   assert(assert2);

   cout << "\tCase Passed\n\t...\n";
      


}




 
int main() {

   ifstream istream;
   ofstream ostream;

   std::string fileName1;
   std::string fileName2;
   std::string fileNameOut;

   int iArray1[MAX_SIZE];
   int iArray1Size;
   int iArray2[MAX_SIZE];
   int iArray2Size;
   int finalArray[MAX_SIZE];
   int finalArraySize;


   cout << "*** Unit Test Cases ***\n";

   readFileTest();
   cout << "Press any key to continue...";
   cin.ignore().get();
   
   sortTest();
   cout << "Press any key to continue...";
   cin.ignore().get();
   
   writeFileTest();
   cout << "Press any key to continue...";
   cin.ignore().get();

   
   cout << "*** Welcome to Tanner Bonds' sorting program ***\n";
   cout << "Enter the first input file name: ";             
   cin >> fileName1;
   
   istream.open((char*)fileName1.c_str());
   
   if (istream.fail()) {
   
      cout << "\tFile Opening Failed.\n";
      exit(1);
   
   }
   
   iArray1Size = readFile(iArray1, istream);
   iArray1Size++;
   istream.close();
   istream.clear();
   
   cout << "The list of " << (iArray1Size) << " numbers in file "
      << fileName1 << " is: \n";
      
   for(int i = 0; i <= iArray1Size; i++) {
      
      cout << iArray1[i] << "\n";
      
   }
   
   cout << "Enter the second input file name: ";             
   cin >> fileName2;
   
   
   istream.open((char*)fileName2.c_str());
   
   if (istream.fail()) {
   
      cout << "\tFile Opening Failed.\n";
      exit(1);
   
   }
 
   iArray2Size = readFile(iArray2, istream);
   iArray2Size++;
   istream.close();
   istream.clear();

   cout << "The list of " << (iArray2Size) << " numbers in file "
      << fileName2 << " is: \n";
      
   for(int i = 0; i <= iArray2Size; i++) {
      
      cout << iArray2[i] << "\n";
      
   }
   
   
   finalArraySize = sort(iArray1, iArray1Size, iArray2, iArray2Size, finalArray);
   
   cout << "The sorted list of " << finalArraySize << " numbers is: ";
      
   for (int i = 0; i <= finalArraySize; i++){
      
      cout << finalArray[i] << " ";
      
   }
      
      

   cout << "\nEnter the output file name: ";
   cin >> fileNameOut;
   
   ostream.open((char*)fileNameOut.c_str());
   if (ostream.fail()) {
      cout << "Output file opening failed.";
      exit(1);
   }
      
   writeFile(finalArray, finalArraySize, ostream);
   
   cout << "*** Please check the new file - " << fileNameOut << " ***\n";
   cout << "*** Goodbye ***";
    
   
   
   
   
  
}