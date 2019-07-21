// name: Tanner Bonds, tjb0057
// partner: None
// filename: Project1.cpp
// due date: 12/7/2018
// collaboration: I did not use any external sources for this assignment.
// compliation: compile with g++ compiler.
// problem: Write a program to act as an automated teller system for a bank.


#include <fstream>
#include <iostream>
#include <stdio.h>
using namespace std;

char username[7];
int password = 0000;
string employStat;
int switchCase2;

void addClient();
void addAccount();
void addBranch();
void manageAccount();
void manageBalance();
void edit();
void save();
void deleteBankClient();
void changePassword();
void terminalBranch();
void terminalClient();
void branchLogin();
void login();
void listStaff();
void terminalAdmin();
void quitSystem();
void menuOptions();

void testLogin(void);
void testAddBranch(void);
void testDeleteBranch(void);
void testAddClient(void);
void testChangePassword(void);
void testEdit(void);
void testManageAccount(void);


struct BankClient {

   const char *username;
   int password;
   string employStat;
   

};



BankClient Client[10];
int numClients = 1;




struct BankClientInfo {

   string name;
   string address;
   string employer;
   int income;
   int socialSecurity;

};



BankClientInfo ClientInfo[10];
int numClientInfo = 0;



struct BankAccount {

   string name;
   string type;
   int numAccount;
   int curAmount;

};



BankAccount AccountInfo[10];
int numAccounts = 0;



void addClient() {

   int confirmation;
   string nameNew;
   string addressNew;
   string employNew;
   int socialNew; 
   int incomeNew;
   numClientInfo++;

   cout << "\n\nClient Creation: Please enter the Name of the Client.";
    
   cout << "\n\tClient Name: ";
   cin.ignore();
   getline(cin, nameNew);
    
   cout << "\n\tClient Address: ";
   cin.ignore();
   getline(cin, addressNew);
    
   cout << "\n\tClient Social Security Number: ";
   cin >> socialNew;
    
   cout << "\n\tClient Employer: ";
   cin.ignore();
   getline(cin, employNew);
    
   cout << "\n\tClient Annual Income: ";
   cin >> incomeNew;

   cout << "\n\nPress 1 to Confirm & Save Changes";
   cout << "\nPress 2 to Cancel Changes\n";
   cout << "\tPlease Select an Option:";
   cin >> confirmation;

   if (confirmation < 0 || confirmation > 2)                    
   {   
      cout << "\n\nError: Unknown Option: Please Try Again.\n";
   
   }

   switch (confirmation) {
   
      case 1:
      
         ClientInfo[numClientInfo].name = nameNew;
         ClientInfo[numClientInfo].address = addressNew;
         ClientInfo[numClientInfo].employer = employNew;
         ClientInfo[numClientInfo].income = incomeNew;
         ClientInfo[numClientInfo].socialSecurity = socialNew;
      
         cout << "\nClient Created.\n";
         cout << "Press any key to continue...\n";       
         cin.ignore().get();
         terminalClient();
         break;
   
      case 2:
                                      
         numClientInfo--;
         cout << "\n\nAction Cancelled.\n";
         terminalClient();
         break; 
   
   }
}

void addAccount() {


   int confirmation;
   int count = 1;
   int switchCase;
   int accountNum;
   int balanceNew;
   string accountType;

   cout << "\n\nAccount Creation: Please Select the Name of the Client.\n";


   for (int i = 1; i < numClientInfo + 1; i++) {
    
      cout << count << ": " << ClientInfo[i].name << "\n";
      count++;
      i++;
           
   }

   cin >> switchCase;
    
   if (switchCase > 10 || switchCase < 0) {
    
      cout << "\n\nError: Unknown Option: Please Try Again.\n";
      addAccount();
        
   }

    
   switch(switchCase) {
        
      case 1:
            
         cout << "An Account Will Be Created For: " << ClientInfo[1].name;
                
         cout << "\n\tAccount Number: ";
         cin >> accountNum;
                
         cout << "\n\tAccount Type: ";
         cin >> accountType;
                
         cout << "\n\tAccount Balance: ";
         cin >> balanceNew;
                
         cout << "\n\nPress 1 to Confirm & Save Changes";
         cout << "\nPress 2 to Cancel Changes\n";
         cout << "\tPlease Select an Option:";
         cin >> confirmation;
      
         if (confirmation < 0 || confirmation > 2) {
                       
            cout << "\n\nError: Unknown Option: Please Try Again.\n";
            addAccount();
         
         }
      
         switch (confirmation) {
         
            case 1:
            
                
               AccountInfo[1].name = ClientInfo[1].name;
               AccountInfo[1].numAccount = accountNum;
               AccountInfo[1].type = accountType;
               AccountInfo[1].curAmount = balanceNew;
               
               break;
         
            case 2:
            
               cout << "\n\nAction Cancelled.\n";
               terminalClient();
               break;                 
         
         }
         
         break;
         
      case 2:
            
         cout << "An Account Will Be Created For: " << ClientInfo[2].name;
                
         cout << "\n\tAccount Number: ";
         cin >> accountNum;
                
         cout << "\n\tAccount Type: ";
         cin >> accountType;
                
         cout << "\n\tAccount Balance: ";
         cin >> balanceNew;
                
         cout << "\n\nPress 1 to Confirm & Save Changes";
         cout << "\nPress 2 to Cancel Changes\n";
         cout << "\tPlease Select an Option:";
         cin >> confirmation;
      
         if (confirmation < 0 || confirmation > 2) {
                       
            cout << "\n\nError: Unknown Option: Please Try Again.\n";
            addAccount();
         
         }
      
         switch (confirmation) {
         
            case 1:
            
                
               AccountInfo[2].name = ClientInfo[2].name;
               AccountInfo[2].numAccount = accountNum;
               AccountInfo[2].type = accountType;
               AccountInfo[2].curAmount = balanceNew;
               
               break;
         
            case 2:
            
               cout << "\n\nAction Cancelled.\n";
               terminalClient();
               break;                 
         
         }
         
         break;
   
      case 3:
            
         cout << "An Account Will Be Created For: " << ClientInfo[3].name;
                
         cout << "\n\tAccount Number: ";
         cin >> accountNum;
                
         cout << "\n\tAccount Type: ";
         cin >> accountType;
                
         cout << "\n\tAccount Balance: ";
         cin >> balanceNew;
                
         cout << "\n\nPress 1 to Confirm & Save Changes";
         cout << "\nPress 2 to Cancel Changes\n";
         cout << "\tPlease Select an Option:";
         cin >> confirmation;
      
         if (confirmation < 0 || confirmation > 2) {
                       
            cout << "\n\nError: Unknown Option: Please Try Again.\n";
            addAccount();
         
         }
      
         switch (confirmation) {
         
            case 1:
            
                
               AccountInfo[3].name = ClientInfo[3].name;
               AccountInfo[3].numAccount = accountNum;
               AccountInfo[3].type = accountType;
               AccountInfo[3].curAmount = balanceNew;
               
               break;
         
            case 2:
            
               cout << "\n\nAction Cancelled.\n";
               terminalClient();
               break;                 
         
         }
         
         break;
         
      case 4:
            
         cout << "An Account Will Be Created For: " << ClientInfo[4].name;
                
         cout << "\n\tAccount Number: ";
         cin >> accountNum;
                
         cout << "\n\tAccount Type: ";
         cin >> accountType;
                
         cout << "\n\tAccount Balance: ";
         cin >> balanceNew;
                
         cout << "\n\nPress 1 to Confirm & Save Changes";
         cout << "\nPress 2 to Cancel Changes\n";
         cout << "\tPlease Select an Option:";
         cin >> confirmation;
      
         if (confirmation < 0 || confirmation > 2) {
                       
            cout << "\n\nError: Unknown Option: Please Try Again.\n";
            addAccount();
         
         }
      
         switch (confirmation) {
         
            case 1:
            
                
               AccountInfo[4].name = ClientInfo[4].name;
               AccountInfo[4].numAccount = accountNum;
               AccountInfo[4].type = accountType;
               AccountInfo[4].curAmount = balanceNew;
               
               break;
         
            case 2:
            
               cout << "\n\nAction Cancelled.\n";
               terminalClient();
               break;                 
         
         }
         
         break;
   
      case 5:
            
         cout << "An Account Will Be Created For: " << ClientInfo[5].name;
                
         cout << "\n\tAccount Number: ";
         cin >> accountNum;
                
         cout << "\n\tAccount Type: ";
         cin >> accountType;
                
         cout << "\n\tAccount Balance: ";
         cin >> balanceNew;
                
         cout << "\n\nPress 1 to Confirm & Save Changes";
         cout << "\nPress 2 to Cancel Changes\n";
         cout << "\tPlease Select an Option:";
         cin >> confirmation;
      
         if (confirmation < 0 || confirmation > 2) {
                       
            cout << "\n\nError: Unknown Option: Please Try Again.\n";
            addAccount();
         
         }
      
         switch (confirmation) {
         
            case 1:
            
                
               AccountInfo[5].name = ClientInfo[5].name;
               AccountInfo[5].numAccount = accountNum;
               AccountInfo[5].type = accountType;
               AccountInfo[5].curAmount = balanceNew;
               
               break;
         
            case 2:
            
               cout << "\n\nAction Cancelled.\n";
               terminalClient();
               break;                 
         
         }
         
         break;
   
      case 6:
            
         cout << "An Account Will Be Created For: " << ClientInfo[6].name;
                
         cout << "\n\tAccount Number: ";
         cin >> accountNum;
                
         cout << "\n\tAccount Type: ";
         cin >> accountType;
                
         cout << "\n\tAccount Balance: ";
         cin >> balanceNew;
                
         cout << "\n\nPress 1 to Confirm & Save Changes";
         cout << "\nPress 2 to Cancel Changes\n";
         cout << "\tPlease Select an Option:";
         cin >> confirmation;
      
         if (confirmation < 0 || confirmation > 2) {
                       
            cout << "\n\nError: Unknown Option: Please Try Again.\n";
            addAccount();
         
         }
      
         switch (confirmation) {
         
            case 1:
            
                
               AccountInfo[6].name = ClientInfo[6].name;
               AccountInfo[6].numAccount = accountNum;
               AccountInfo[6].type = accountType;
               AccountInfo[6].curAmount = balanceNew;
               
               break;
         
            case 2:
            
               cout << "\n\nAction Cancelled.\n";
               terminalClient();
               break;                 
         
         }
         
         break;
   
      case 7:
            
         cout << "An Account Will Be Created For: " << ClientInfo[7].name;
                
         cout << "\n\tAccount Number: ";
         cin >> accountNum;
                
         cout << "\n\tAccount Type: ";
         cin >> accountType;
                
         cout << "\n\tAccount Balance: ";
         cin >> balanceNew;
                
         cout << "\n\nPress 1 to Confirm & Save Changes";
         cout << "\nPress 2 to Cancel Changes\n";
         cout << "\tPlease Select an Option:";
         cin >> confirmation;
      
         if (confirmation < 0 || confirmation > 2) {
                       
            cout << "\n\nError: Unknown Option: Please Try Again.\n";
            addAccount();
         
         }
      
         switch (confirmation) {
         
            case 1:
            
                
               AccountInfo[7].name = ClientInfo[7].name;
               AccountInfo[7].numAccount = accountNum;
               AccountInfo[7].type = accountType;
               AccountInfo[7].curAmount = balanceNew;
               
               break;
         
            case 2:
            
               cout << "\n\nAction Cancelled.\n";
               terminalClient();
               break;                 
         
         }
         
         break;
         
      case 8:
            
         cout << "An Account Will Be Created For: " << ClientInfo[8].name;
                
         cout << "\n\tAccount Number: ";
         cin >> accountNum;
                
         cout << "\n\tAccount Type: ";
         cin >> accountType;
                
         cout << "\n\tAccount Balance: ";
         cin >> balanceNew;
                
         cout << "\n\nPress 1 to Confirm & Save Changes";
         cout << "\nPress 2 to Cancel Changes\n";
         cout << "\tPlease Select an Option:";
         cin >> confirmation;
      
         if (confirmation < 0 || confirmation > 2) {
                       
            cout << "\n\nError: Unknown Option: Please Try Again.\n";
            addAccount();
         
         }
      
         switch (confirmation) {
         
            case 1:
            
                
               AccountInfo[8].name = ClientInfo[8].name;
               AccountInfo[8].numAccount = accountNum;
               AccountInfo[8].type = accountType;
               AccountInfo[8].curAmount = balanceNew;
               
               break;
         
            case 2:
            
               cout << "\n\nAction Cancelled.\n";
               terminalClient();
               break;                 
         
         }
         
         break;
   
      case 9:
            
         cout << "An Account Will Be Created For: " << ClientInfo[9].name;
                
         cout << "\n\tAccount Number: ";
         cin >> accountNum;
                
         cout << "\n\tAccount Type: ";
         cin >> accountType;
                
         cout << "\n\tAccount Balance: ";
         cin >> balanceNew;
                
         cout << "\n\nPress 1 to Confirm & Save Changes";
         cout << "\nPress 2 to Cancel Changes\n";
         cout << "\tPlease Select an Option:";
         cin >> confirmation;
      
         if (confirmation < 0 || confirmation > 2) {
                       
            cout << "\n\nError: Unknown Option: Please Try Again.\n";
            addAccount();
         
         }
      
         switch (confirmation) {
         
            case 1:
            
                
               AccountInfo[9].name = ClientInfo[9].name;
               AccountInfo[9].numAccount = accountNum;
               AccountInfo[9].type = accountType;
               AccountInfo[9].curAmount = balanceNew;
               
               break;
         
            case 2:
            
               cout << "\n\nAction Cancelled.\n";
               terminalClient();
               break;                 
         
         }
         
         break;
         
      case 10:
            
         cout << "An Account Will Be Created For: " << ClientInfo[10].name;
                
         cout << "\n\tAccount Number: ";
         cin >> accountNum;
                
         cout << "\n\tAccount Type: ";
         cin >> accountType;
                
         cout << "\n\tAccount Balance: ";
         cin >> balanceNew;
                
         cout << "\n\nPress 1 to Confirm & Save Changes";
         cout << "\nPress 2 to Cancel Changes\n";
         cout << "\tPlease Select an Option:";
         cin >> confirmation;
      
         if (confirmation < 0 || confirmation > 2) {
                       
            cout << "\n\nError: Unknown Option: Please Try Again.\n";
            addAccount();
         
         }
      
         switch (confirmation) {
         
            case 1:
            
                
               AccountInfo[10].name = ClientInfo[10].name;
               AccountInfo[10].numAccount = accountNum;
               AccountInfo[10].type = accountType;
               AccountInfo[10].curAmount = balanceNew;
               
               break;
         
            case 2:
            
               cout << "\n\nAction Cancelled.\n";
               terminalClient();
               break;                 
         
         }
         
         break;
   
   }
            
           
   cout << "\n\n New Account Confirmed.\n";
   cout << "Press any key to continue...";       
   cin.ignore().get();
   terminalClient();
    
}

void addBranch() {

   char usernameNew[7];
   int passwordNew;
   int switchCase;
   int confirmation;
   string employStat1;
    

   cout << "Please enter your User Name: ";
   cin >> usernameNew;
   
   cout << "\nPlease enter your Password: ";
   cin >> passwordNew;


   cout << "\n\nPress 1 if the New User is a System Administrator.\n";
   cout << "Press 2 if the New User is a Branch Staff Member.\n";
   cout << "\tPlease Select an Option: ";
   cin >> switchCase;

      
   if (switchCase < 1  || switchCase > 2) {                       
    
      cout << "\nError: Unknown Option: Please Try Again.\n";
      addBranch();
        
        
   }
    
   numClients++;
    
   switch (switchCase) {   
     
      case 1:                             
      
         employStat1 = "System Administrator";
         break;
   
      case 2:                                  
      
         employStat1 = "Branch Staff";
         break;
    
   }

   cout << "\n\nPress 1 to Confirm & Save Changes";
   cout << "\nPress 2 to Cancel Changes\n";
   cout << "\tPlease Select an Option: ";
   cin >> confirmation;

   if (confirmation < 0 || confirmation > 2)                    
   {   
      cout << "\n\nError: Unknown Option: Please Try Again.\n";
   
   }

   switch (confirmation) {
   
      case 1:
      
         
         Client[numClients].username = usernameNew;
         Client[numClients].password = passwordNew;
         Client[numClients].employStat = employStat1;
      
         cout << "New Branch Staff Member Confirmed.\n";
         cout << "User Name: " << usernameNew << "\n\tRole: " << employStat1 << endl;
         cout << "Press any key to continue...";        
         cin.ignore().get();
         terminalAdmin();
         break;
   
      case 2:
      
                                           
         numClients--;
         cout << "\n\nAction Cancelled.\n";
         terminalAdmin();
         break; 
        
   }
}

void manageBalance() {

   int switchCase;
   int deposit;
   int withdraw;
   int confirmation;
      
   cout << "\n\nAccount Management";
   cout << "\n\nPress 1 to Deposit.";
   cout << "\nPress 2 to Withdraw.";
   cout << "\nPress 3 To Cancel & Return To Menu.";
   cout << "\n\tPlease Select An Option: ";
   cin >> switchCase;

   switch (switchCase) {
   
      case 1:
      
         cout << "\n\nDeposit Amount: ";
         cin >> deposit;
            
         cout << "\n\nPress 1 to Confirm Deposit";
         cout << "\nPress 2 to Cancel Deposit\n";
         cout << "\tPlease Select an Option:";
         cin >> confirmation;
      
         if (confirmation < 0 || confirmation > 2) {                    
          
            cout << "\n\nError: Unknown Option: Please Try Again.\n";
            manageBalance();
            
         }
      
         switch (confirmation) {
         
            case 1:
            
            
               AccountInfo[switchCase2].curAmount += deposit;
               cout << "\n\nAccount Balance " << AccountInfo[switchCase2].numAccount << " is: " 
                  <<  AccountInfo[switchCase2].curAmount << endl;
               manageBalance();
               break;
            
            case 2:
            
               cout << "\n\nDeposit Cancelled.\n";
               terminalClient();
               break; 
         
         }
            
      case 2:
            
         cout << "\n\nWithdrawal Amount: ";
         cin >> withdraw;
         
         cout << "\n\nPress 1 to Confirm Withdrawal";
         cout << "\nPress 2 to Cancel Withdrawal\n";
         cout << "\tPlease Select an Option:";
         cin >> confirmation;
      
         if (confirmation < 0 || confirmation > 2) {                    
          
            cout << "\n\nError: Unknown Option: Please Try Again.\n";
            manageBalance();
            
         }
      
         switch (confirmation) {
         
            case 1:
            
            
               AccountInfo[switchCase2].curAmount -= withdraw;
               cout << "\n\nAccount Balance " << AccountInfo[switchCase2].numAccount << " is: " 
                  <<  AccountInfo[switchCase2].curAmount << endl;
               manageBalance();
               break;
         
            case 2:
            
               cout << "\n\nDeposit Cancelled.\n";
               terminalClient();
               break; 
         
         }
      
         break;
            
      case 3:
            
         terminalClient();
         break;
   
   }
}

void manageAccount() {

   int switchCase;
   int confirmation;
   int count = 1;
    
   cout << "\n\nSelect Account To Manage: \n";

   for (int i = 1; i < numClientInfo + 1; i++) {
    
      cout << count << ": " << AccountInfo[i].name << "\n";
      count++;
      i++;
        
   }

   cin >> switchCase;
   switchCase2 = switchCase;
    
    

   if (switchCase > 10 ||  switchCase < 0) {
    
      cout << "\n\nError: Unknown Option: Please Try Again.\n";
      manageAccount();
   
   }

   cout << "\n\nPress 1 to Confirm Management of Account.";
   cout << "\nPress 2 to Cancel.\n";
   cout << "\tPlease Select an Option:";
   cin >> confirmation;

       

   switch (confirmation) {
   
      case 1:
        
         manageBalance();
            
         break;
   
      case 2:
        
         terminalClient();
            
         break;
   
   }

}

void edit() {

   int switchCase;
   int confirmation;
   string updateAddress; 
   string updateEmploy;
   int updateSocialSecurity;
   int updateIncome;

   int count = 1;
    
   cout << "\n\nPlease Select a Client: \n";

   for (int i = 1; i < numClientInfo + 1; i++) {
    
      cout << count << ": " << ClientInfo[i].name << "\n";
      count++;
      i++;
    
   }

   cin >> switchCase;

   if (switchCase > 10 || switchCase < 0) {
    
      cout << "\n\nError: Unknown Option: Please Try Again.\n";
      edit();
        
   }

   cout << "\n\nDisplaying " << ClientInfo[switchCase].name << "'s information: \n";
   cout << "\tAddress: " << ClientInfo[switchCase].address << "\n";
   cout << "\tSocial Security: " << ClientInfo[switchCase].socialSecurity << "\n";
   cout << "\tEmployer: " << ClientInfo[switchCase].employer << "\n";
   cout << "\tAnnual Income: " << ClientInfo[switchCase].income << "\n";

   cout << "\n\nPress 1 to Confirm Management of Account.";
   cout << "\nPress 2 to Cancel.\n";
   cout << "\tPlease Select an Option:";
   cin >> confirmation;
 

   switch (confirmation) {
   
      case 1:
        
                  
         cout << "\n\nAddress: ";
         cin.ignore();
         getline(cin, updateAddress);
        
         cout << "\nSocial Security: ";
         cin >> updateSocialSecurity;
        
         cout << "\nEmployer: ";
         cin >> updateEmploy;
        
         cout << "Income: ";
         cin >> updateIncome;
       
      
         ClientInfo[switchCase].address = updateAddress;
         ClientInfo[switchCase].socialSecurity = updateSocialSecurity;
         ClientInfo[switchCase].employer = updateEmploy;
         ClientInfo[switchCase].income = updateIncome;
      
         cout << "\n\nClient Information Updated\n";
         cout << "Press any key to continue...";       
         cin.ignore().get();
         terminalClient();
            
         break;
   
      case 2:
        
         terminalClient();
            
         break;
   
   }

}

void save() {

   ofstream out ("client-info.txt");
   ofstream outf ("account-info.txt");
   out.open ("client-info.txt", ios::out | ios::app); 
    
   if (outf.is_open()) {
    
      out << "Name: " << ClientInfo[0].name << endl;
      out << "Address: " << ClientInfo[0].address << endl;
      out << "Social: xx-xxx-xxxx" << endl;
      out << "Employer: " << ClientInfo[0].employer << endl;
      out << "Income: " << ClientInfo[0].income << endl;
   
      out << "Name: " << ClientInfo[1].name << endl;
      out << "Address: " << ClientInfo[1].address << endl;
      out << "Social: xx-xxx-xxxx" << endl;
      out << "Employer: " << ClientInfo[1].employer << endl;
      out << "Income: " << ClientInfo[1].income << endl;
   
      out.close();
   }

   outf.open ("account-info.txt", ios::out | ios::app);

   if (outf.is_open()) {
    
      outf << "Account Number: " << AccountInfo[0].numAccount << endl;
      outf << "Account Type: " << AccountInfo[0].type << endl;
      outf << "Balance: " << AccountInfo[0].curAmount << endl;
   
      outf << "Account Number: " << AccountInfo[1].numAccount << endl;
      outf << "Account Type: " << AccountInfo[1].type << endl;
      outf << "Balance: " << AccountInfo[1].curAmount << endl;
   
      outf.close();
        
   }

   cout << "Client information Saved To client-info.txt";
   cout << "\nAccount Information Saved To account-info.txt\n";
   cout << "Press any key to continue...";       
   cin.ignore().get();

}

void deleteBankClient() {

   int confirmation;
   int switchCase;
   int count = 1;

   cout << "\n\nUser Deletion: Please enter the user you wish to delete\n";
    
   for (int i=0; i < numClients + 1; i++) {
    
      cout << count << ": " << Client[i].username << "\n";
      count++;
      i++;
        
   }

   cin >> switchCase;

   cout << "\n\nPress 1 to Confirm & Save Changes";
   cout << "\nPress 2 to Cancel Changes\n";
   cout << "\tPlease Select an Option: ";
   cin >> confirmation;
    

   if (confirmation < 1 || confirmation > 2)                    
   {   
      cout << "\n\nError: Unknown Option: Please Try Again.\n";
      deleteBankClient();
   }

   switch (confirmation) {
   
      case 1:
      
         switch(switchCase) {
         
            case 1: 
               Client[1].username = NULL;
               Client[1].password = 0000;
               Client[1].employStat = "";
               break;
         
            case 2:
               Client[2].username = NULL;
               Client[2].password = 0000;
               Client[2].employStat = "";
               break;
         
            case 3:
            
               Client[3].username = NULL;
               Client[3].password = 0000;
               Client[3].employStat = "";
               break;
                
            case 4:
            
               Client[4].username = NULL;
               Client[4].password = 0000;
               Client[4].employStat = "";
               break;
         
            case 5:
            
               Client[5].username = NULL;
               Client[5].password = 0000;
               Client[5].employStat = "";
               break;
         
            case 6:
            
               Client[6].username = NULL;
               Client[6].password = 0000;
               Client[6].employStat = "";
               break;
         
            case 7:
            
               Client[7].username = NULL;
               Client[7].password = 0000;
               Client[7].employStat = "";
               break;
         
            case 8:
            
               Client[8].username = NULL;
               Client[8].password = 0000;
               Client[8].employStat = "";
               break;
            
            case 9:
            
               Client[9].username = NULL;
               Client[9].password = 0000;
               Client[9].employStat = "";
               break;
         
                
            case 10:
            
               Client[10].username = NULL;
               Client[10].password = 0000;
               Client[10].employStat = "";
               break;
         
         } 
            
         numClients--;
         cout << "\n\nUser Deleted.\n";
         cout << "Press any key to continue...";       
         cin.ignore().get();
         terminalAdmin();
      
         break;
    
   
      case 2:                                 
      
         cout << "\n\nAction Cancelled.\n";
         terminalAdmin();
         break;
        
   }  
}

void changePassword() {

   int passwordNew;
   int switchCase;
   int confirmation;
   int count = 1;

   cout << "\n\nPlease enter your new Password: ";
   cin >> passwordNew;

   if (password == passwordNew) {
    
      cout << "\n\tYour new password must be different from the old one!\n";
      changePassword();
        
   } 

   cout << "\n\nPlease select the user you wish to change the password of: \n";
    
   for (int i=0; i < numClients + 1; i++) {
    
      cout << count << ": " << Client[i].username << "\n";
      count++;
      i++;
        
   }
    
   cin >> switchCase; 
   
   cout << "\n\nPress 1 to Confirm & Save Changes";
   cout << "\nPress 2 to Cancel Changes\n";
   cout << "\tPlease Select an Option:";
   cin >> confirmation;
    

   if (confirmation < 1 || confirmation > 2)                    
   {   
      cout << "\n\nError: Unknown Option: Please Try Again.\n";
      changePassword();
   }

   switch (confirmation) {
   
      case 1:
      
      
         if (switchCase < 1 || switchCase > 10) {
         
            cout << "\nError: Unknown Option: Please Try Again.\n";
            changePassword();
         
         }
      
         switch(switchCase) {
         
            case 1: 
            
               Client[1].password = passwordNew;
               break;
         
            case 2:
            
               Client[2].password = passwordNew;
               break;
         
            case 3:
                
               Client[3].password = passwordNew;
               break;
                
            case 4:
                            
               Client[4].password = passwordNew;
               break;
         
            case 5:
            
               Client[5].password = passwordNew;
               break;
         
            case 6:
                            
               Client[6].password = passwordNew;
               break;
         
            case 7:
                            
               Client[7].password = passwordNew;
               break;
                
            case 8:
            
               Client[8].password = passwordNew;
               break;
            
            case 9:
            
               Client[9].password = passwordNew;
               break; 
                               
            case 10:
            
               Client[10].password = passwordNew;
               break;
                
         }
                        
         cout << "Password Successfully Changed\n";
         cout << "Press any key to continue...";       
         cin.ignore().get();
         terminalAdmin();
         break;
   
      case 2:
      
         cout << "\n\nAction Cancelled.\n";
         terminalAdmin();
         break;
           
   }
}

void terminalBranch() {

   int switchCase;

   cout << "\n\n****************************************************\n";
   cout << "   Teller Terminal System - Branch Staff Access  \n";
   cout << "*************************************************\n\n";
   
   cout << "Press 1 For Client and Account Management.\n";
   cout << "Press 2 To Change Password.\n";
   cout << "Press 3 To Quit\n";
   cout << "\t Please choose an option: ";
   cin >> switchCase;
   
   
   
   if (switchCase < 1 || switchCase > 3) {
   
      cout << "\nError: Unknown Option: Please Try Again.\n";
      terminalBranch();
      
   }
      
   switch (switchCase) {
      
      case 1:
      
         terminalClient();
         break;
      
      case 2:
      
         changePassword();
         break;
      
      case 3:
      
         quitSystem();
         break;  
      
   }  
}

void branchLogin() {

   char userNameNew[7];
   int passwordNew;

   cout << "\n\n******************************************************\n";
   cout << "   Please Login to Access the Teller Terminal System  \n";
   cout << "******************************************************\n\n";

   cout << "Please enter your User Name: ";
   cin >> userNameNew;
   
   cout << "\nPlease enter your Password: ";
   cin >> passwordNew;
   
   if (passwordNew == Client[2].password || passwordNew == Client[3].password || 
      passwordNew == Client[4].password) {
    
      terminalBranch();
        
   } 
    
   else {
    
      cout << "\n\nYour User Name or Password is incorrect.\n";
      cout << "\tPlease Try Again.\n\n"; 
      
      branchLogin();
     
   }
}

void terminalClient() {

   int switchCase;

   cout << "\n\n*****************************************************\n";
   cout << "   Teller Terminal System - Client & Account Access  \n";
   cout << "*****************************************************\n\n";
   
   cout << "Press 1 To Add a Client\n";
   cout << "Press 2 To Add an Account.\n";
   cout << "Press 3 To Manage an Account.\n";
   cout << "Press 4 To Edit Client Information.\n";
   cout << "Press 5 To Save Account & Client Information.\n";
   cout << "Press 6 To Quit.\n";
   cout << "\t Please choose an option: ";
   cin >> switchCase;
   
   if (switchCase < 1 || switchCase > 6) {
   
      cout << "\nError: Unknown Option: Please Try Again.\n";
      terminalAdmin();
   
   }
   
   switch (switchCase) {
   
      case 1:
      
         addClient();
         break;
   
      case 2:
      
         addAccount();
         break;
   
      case 3:
      
         manageAccount();
         break;
   
      case 4:
      
         edit();
         break;
   
      case 5:
      
         save();
         break;
   
      case 6:
      
         quitSystem();
         break;
   
   }


}

void login() {

      
   string username;
   int password;
      
   cout << "\n\n******************************************************\n";
   cout << "   Please Login to Access the Teller Terminal System  \n";
   cout << "******************************************************\n\n";
   
   cout << "Please enter your User Name: ";
   cin >> username;
   
   cout << "\nPlease enter your Password: ";
   cin >> password;
   
   if ((username ==  "admin") && (password != 0000)) {
   
      cout << "\n\nYour User Name or Password is incorrect.\n";
      cout << "\tPlease Try Again.\n\n";
      login(); 
   
   }
   
   else {
   
      terminalAdmin();
   
   }
}


void listStaff() {

   numClients++;
   cout << "\n\n";

   for (int i = 0; i < numClients + 1; i++) {
    
      cout << "User Name: " << Client[i].username << "\tPassword: " << Client[i].password << "\tEmployee Status: " << Client[i].employStat << "\n";
      i++;
        
   } 

   cout << "Press any key to continue...";       
   cin.ignore().get();
   terminalAdmin();

}

void terminalAdmin() {

   int switchCase;

   cout << "\n\n*********************************************************\n";
   cout << "   Teller Terminal System - System Administrator Access  \n";
   cout << "*********************************************************\n\n";
   
   cout << "Press 1 For Client and Account Management.\n";
   cout << "Press 2 To Add a Branch Staff Member.\n";
   cout << "Press 3 To Delete a Branch Staff Member.\n";
   cout << "Press 4 To Change Password.\n";
   cout << "Press 5 To Display Branch Staff.\n";
   cout << "Press 6 To Quit.\n";
   cout << "\t Please choose an option: ";
   cin >> switchCase;
   
   if (switchCase < 1 || switchCase > 6) {
   
      cout << "\nError: Unknown Option: Please Try Again.\n";
      terminalAdmin();
   
   }
   
   switch (switchCase) {
   
      case 1:
      
         branchLogin();
         break;
   
      case 2:
      
         addBranch();
         break;
   
      case 3:
      
         deleteBankClient();
         break;
   
      case 4:
      
         changePassword();
         break;
   
      case 5:
      
         listStaff();
         break;
   
      case 6:
      
         quitSystem();
         break;
   
   }
}

void quitSystem() {

   cout << "\nHave a Nice Day!";
   exit(1);

}

void mainOptions() {

   int switchCase;

   cout << "******************************************\n";
   cout << "   Welcome to Tiger Bank: Auburn Branch   \n";
   cout << "******************************************\n\n";
   

   cout << "Press 1 to Login.\n";
   cout << "Press 2 to Quit.\n";
   cout << "\tPlease Select an Option: ";
   cin >> switchCase;

   if (switchCase > 2 || switchCase < 1) {
   
      cout << "\n\nError: Unknown Option: Please Try Again.\n";
      mainOptions();
   
   }

   switch (switchCase) {
   
      case 1:
      
         login();
         break;
   
      case 2:
      
         quitSystem(); 
         break;
   
   
   }
}

int main() {

   Client[0].username = "admin";
   Client[0].password = 0000;
   Client[0].employStat = "System Administrator";

   //testLogin();
   //testAddBranch();
   //testDeleteBranch();
   //testAddClient();
   //testChangePassword();
   //testEdit();
   //testManageAccount();

   mainOptions();

}

void testLogin(void) {

   cout << "Test 1: Login";

 //username: admin
//password: 0000


   cout << "\n\tCase 1.1 - Correct User Name & Password.";

   login();

   cout << "\n\tCase 1.2 - Incorrect User Name or Password.";

   login();

}

void testAddBranch(void) {

   cout << "Test 2: addBranch";
   cout << "\n\tCase 2.1 - Add Branch Staff Member.";
   terminalAdmin();
   
   cout << "\n\tCase 2.2 - Add System Administrator.";
   terminalAdmin();
   
   cout << "\n\tCase 2.3 - Cancel Changes.";
   terminalAdmin();

  
}

void testDeleteBranch(void) {

   cout << "Test 3: deleteBranch";
   cout << "\n\tCase 3.1 - Delete Branch Staff Member.";
   terminalAdmin();
    
   cout << "\n\tCase 3.2 - Cancel Changes.";
   terminalAdmin();


}

void testAddClient(void) {

   cout << "Test 4: addClient";
   cout << "\n\tCase 4.1 - Add Client.";
   terminalClient();
    
   cout << "\n\tCase 4.2 - Cancel Changes.";
   terminalClient();


}

void testChangePassword(void) {

   cout << "Test 5: changePassword";
   cout << "\n\tCase 5.1 - Change Password.";
   terminalAdmin();
    
   cout << "\n\tCase 5.2 - Cancel Changes.";
   terminalAdmin();

}

void testEdit(void) {

   cout << "Test 6: edit";
   cout << "\n\tCase 6.1 - Change Information.";
   terminalClient();
    
   cout << "\n\tCase 6.2 - Cancel Changes.";
   terminalClient();


}

void testManageAccount(void) {

   cout << "Test 7: manageBalance";
   cout << "\n\tCase 7.1 - Manage Account & Balance.";
   terminalClient();
    
      
}