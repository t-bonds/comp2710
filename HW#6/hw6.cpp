// name: Tanner Bonds, tjb0057
// partner: None
// filename: hw6.cpp
// due date: 10/19/2018
// collaboration: I did not use any external sources for this assignment.
// compliation: compile with g++ compiler.
// problem: Write a program that implements a class with three member variables.


#include <string>
#include <iostream>
#include <sstream>
#include <assert.h>
using namespace std;

#define UNIT_TESTING
void testDoctorCon();
void testDoctorOver();
void testName();
void testSpaces();
void testNum();
void testDestructor();
void testPointer();
void testCallCon();


class Doctor {

protected:

   string name;
   int numPatients;
   string *patientList;

public:

   Doctor();
   Doctor(string nameIn, int numPatientsIn, string *patientListIn);
   Doctor(const Doctor& doctorCon);
   string getName()
   const {
      return name;}
   int getNumPatients()
   const {
      return numPatients;}
   string *getPatientList()
   const {
      return patientList;}
   void setName(string setName) 
   {name = setName;}
   void setNumPatients(int setNumPatients)
   {numPatients = setNumPatients;}
   void setPatientList(string *setPatientList)
   {patientList = setPatientList;}
   
   void reset();
   Doctor& operator=(const Doctor& doctorCon);

   ~Doctor();
       
};


int main() {

#ifdef UNIT_TESTING

   testDoctorCon();
   testDoctorOver();
   testName();
   testSpaces();
   testNum();
   testDestructor();
   testPointer();
   testCallCon();


#else

return 0;

#endif
}

Doctor::Doctor() {

   name = "";
   numPatients = 0;
   patientList = NULL;

}

Doctor::Doctor(string nameIn, int numPatientsIn, string *patientListIn) {

   name = nameIn;
   numPatients = numPatientsIn;
   patientList = patientListIn;
   
}

Doctor::Doctor(const Doctor& doctorCon):name(doctorCon.getName()), numPatients(doctorCon.getNumPatients()) {

   if (doctorCon.getPatientList() != NULL) {
   
      patientList = new string[numPatients];
      
      for (int i = 0; i < numPatients; i++) {
      
         patientList[i] = doctorCon.getPatientList()[i];
         
      }
   }
}


void Doctor::reset() {

   numPatients = 0;
   if (patientList != NULL){
   
      delete[] patientList;
      patientList = NULL;
   }
}

Doctor& Doctor::operator=(const Doctor& doctorCon) {

   if (this == &doctorCon) {
   
      return *this;
   
   }
   
   else {
   
      name = doctorCon.getName();
      numPatients = doctorCon.getNumPatients();
   
      if (patientList != NULL) {
      
         delete[] patientList;
      
      }
   
      patientList = new string[numPatients];
   
      for (int i = 0; i < numPatients; i++) {
      
         patientList[i] = doctorCon.getPatientList()[i];
      
      }
      return *this;
   }
}



Doctor::~Doctor() {

   name = "";
   numPatients = 0;
   if (patientList != NULL) {
   
      delete[] patientList;
      patientList = NULL;
   
   }

}

void testDoctorCon() {

   cout << "Test of Doctor Constuctor.\n";

   Doctor doc = Doctor();

   assert(doc.getName() == "");

   cout << "\tTest Passed.\n";
}

void testDoctorOver() {

   cout << "\nTest of overloaded constructor.\n";

   int numPatientsIn = 3;
   string *patientListIn = new string[numPatientsIn];
   
   patientListIn[0] = "Brady";
   patientListIn[1] = "Gregory";
   patientListIn[2] = "Jake";

   Doctor doc = Doctor("Corey Spurlin", numPatientsIn, patientListIn);

   assert(doc.getNumPatients() == 3);
   assert(doc.getPatientList()[1] == "Gregory");

   cout << "\tTest Passed.\n";

}

void testName() {

   cout << "\nTest of setName().\n";

   Doctor doc;
   string set = "Corey Spurlin";
   doc.setName(set);

   assert(doc.getName() == set);

   cout << "\tTest Passed.\n";

}


void testSpaces() {

   cout << "\nTest of setName() with multiple spaces.\n";

   Doctor doc;
   string set = "Tanner James Bonds";
   doc.setName(set);

   assert(doc.getName() == set);

   cout << "\tTest Passed.\n";


}

void testNum() {

   cout << "\nTest of setNumPatients().\n";

   Doctor doc;

   int numPatients = 2;

   doc.setNumPatients(numPatients);

   assert(doc.getNumPatients() == numPatients);

   cout << "\tTest Passed.\n";

}

void testReset() {

   cout << "\nTest of reset().\n";

   int numPatientsIn = 3;
   string *patientListIn = new string[numPatientsIn];
   
   patientListIn[0] = "Brady";
   patientListIn[1] = "Gregory";
   patientListIn[2] = "Jake";

   Doctor doc = Doctor("Corey Spurlin", numPatientsIn, patientListIn);
   
   doc.reset();
   
   assert(doc.getPatientList() == NULL);
   
   cout << "\tTest Passed.\n";

}

void testDestructor() {

   cout << "\nTest of the Destructor.\n";

   int numPatientsIn = 3;
   string *patientListIn = new string[numPatientsIn];
   
   patientListIn[0] = "Brady";
   patientListIn[1] = "Gregory";
   patientListIn[2] = "Jake";

   Doctor *doc = new Doctor("Corey Spurlin", numPatientsIn, patientListIn);

   doc -> ~Doctor();
   
   assert(doc->getPatientList() == NULL);
   
   cout << "\tTest Passed.\n";   


}

void testPointer() {

   cout << "\nTest of overload operator with pointers.\n";

   int numPatientsIn = 2;
   string *patientListIn = new string[numPatientsIn];
   
   patientListIn[0] = "Brady";
   patientListIn[1] = "Gregory";
   

   Doctor *doc = new Doctor("Corey Spurlin", numPatientsIn, patientListIn);

   int numPatientsIn1 = 1;
   string *patientListIn1 = new string [numPatientsIn1];
   
   patientListIn1[0] = "Jake";
   
   Doctor *doc1 = new Doctor("Nikki Gross", numPatientsIn1, patientListIn1);
   
   doc->operator=(*doc1);
   
   assert(doc->getPatientList()[0] == "Jake");
   
   cout << "\tTest Passed.\n"; 
   

}

void testCallCon() {

   cout << "\nTest of the Copy Constructor\n";

   int numPatientsIn = 2;
   string *patientListIn = new string[numPatientsIn];
   
   patientListIn[0] = "Brady";
   patientListIn[1] = "Gregory";
   

   Doctor *doc = new Doctor("Corey Spurlin", numPatientsIn, patientListIn);
   Doctor *doc1 = new Doctor(*doc);
   
   assert(doc1->getPatientList()[0] == "Brady");

   cout << "\tTest Passed.\n";
   
   

}