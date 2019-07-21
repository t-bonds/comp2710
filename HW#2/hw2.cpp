// name: Tanner Bonds, tjb0057
// partner: None
// filename: hw1.cpp
// due date: 09/7/2018
// collaboration: I did not use any external sources for this assignment.
// compliation: compile with g++ compiler.
// problem: determine how many months it will take to pay off any loan 
// and calculate the interest of each loan.


   #include <iostream>
using namespace std;
   
int main() {
   
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);
   
   
   double totalCost;
   double initInterestRate;
   double interestRate;
   double interestRatePercent;
   double interest;
   double interestTotal = 0;
   double monthlyPayment;
   double deductedMonthly;
   double principal;
   int month = 0;
   
   cout << "Loan Amount: ";
   cin >> totalCost;
   
   cout << "\nInterest Rate (% per year): ";
   cin >> initInterestRate;
   
   cout << "\nMonthly Payments: ";
   cin >> monthlyPayment;
   
   interestRate = (initInterestRate / 12);
   interestRatePercent = (interestRate / 100);
   
   cout << "\n\n*****************************************************************";
   cout << "\n        Amortization Table ";
   cout << "\n*****************************************************************\n";
   cout << "Month" << "\t\tBalance" << "\t\tPayment" << "\t\tRate" << "\t\tInterest" << "\t\tPrincipal\n";
   cout << month << "\t\t\t" << totalCost << "\t\tN/A" << "\t\t\tN/A" << "\t\tN/A" << "\t\t\tN/A";
   
   
   
   do {
   
      if (totalCost > monthlyPayment) {
      
         interest = (interestRatePercent * totalCost);
         principal = (monthlyPayment - interest);
         totalCost = (totalCost - principal);
         month++;
         interestTotal += interest;
         
         cout<< "\n" << month << "\t\t\t$" << totalCost << "\t\t$" << monthlyPayment << "\t\t"
            << interestRate << "\t\t" << interest << "\t\t\t" << principal;
      }
      
      else {
      
         interest = (interestRatePercent * totalCost);
         principal = totalCost;
         monthlyPayment = totalCost + interest;
         totalCost = totalCost - principal;
         
         
         month++;
         interestTotal += interest;
      
      
         cout<< "\n" << month << "\t\t\t$" << totalCost << "\t\t\t$" << monthlyPayment << "\t\t"
            << interestRate << "\t\t" << interest << "\t\t\t" << principal;
      
      
      } 
   }
    while (totalCost > 0);
    
      
      
   
   cout << "\n*****************************************************************";
   cout << "\n\n It takes " << month << " months to pay off the loan.";
   cout << "\n Total interest paid is: $" << interestTotal;
   
   return 0;
   
}