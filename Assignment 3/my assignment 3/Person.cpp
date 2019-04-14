#include "Person.h"
#include <iostream>
using namespace std;

Person::Person()
{
	this-> status = SINGLE;
	this-> gender = MALE;
	this-> spousePtr = NULL;
	cout << "\nDEFAULT CONSTRUCTOR CALLED for ";
}

Person::Person(string first, string last, Gender gender)
{
    this-> firstName = first;
    this-> lastName = last;
    this -> gender = gender;
    this -> status = SINGLE;
    this -> spousePtr = NULL;
    cout << "OVERLOADED CONSTRUCTOR CALLED for a person named " << first <<" "<< last << endl;

}

Person::~Person()
{
	cout <<"DECONSTRUCTOR CALLED for - "<< firstName << " " << lastName << endl;
}

string Person::getFirstName() const
{
	return this-> firstName;
}

string Person::getLastName() const
{
	return this-> lastName;
}

Gender Person::getGender() const
{
	return this-> gender;
}

Person* Person::getSpouse() const
{
	return this-> spousePtr;
}

void Person::setFirstName(string firstName)
{
	cout << "SETFIRSTNAME FUNCTION CALLED " << endl;
	this-> firstName = firstName;
}

void Person::setLastName(string lastName)
{
	cout << "SETLASTNAME FUNCTION CALLED"<< endl;
	this-> lastName = lastName;
}

void Person::setGender(Gender gender)
{
	cout<< "SETGENDER FUNCTION CALLED" << endl;
	this-> gender = gender;
}

void Person::setSpouse(Person &spousePtr)
{
	if((spousePtr.lastName == spousePtr.firstName && spousePtr.firstName == "")	//if there is no name
		||(this->lastName == this-> firstName && this->firstName == ""))
			return;

	this-> spousePtr = &spousePtr;	//this instance of spoucePtr is set to the passby reference of &spouse
	spousePtr.spousePtr = &(*this); //set that persons spouse to the current instance

	this -> status = MARRIED; // pointer to an object
	spousePtr.status = MARRIED; // object, not a pointer to an object

	if(this-> gender == MALE)
		spousePtr.lastName = this-> lastName;	// if gender is male set spouses last name to males
	else
		this -> lastName = spousePtr.lastName;

	cout << firstName << " " << lastName << "'s " << "SETSPOUSE FUNCTION CALLED" << endl;
}

void Person::setStatus(Status status)
{
	cout << "SETSTATUS FUNCTION CALLED" << endl;
	this-> status = status;
}

bool Person::isMarried()
{
	if(status == MARRIED)
		return true;
	else
		return false;
}

string Person::toString()
{
  string name;
 
  if (status == MARRIED && spousePtr) // married person with spouse
    {
    	name = firstName + " " + lastName + " is married to " + spousePtr-> firstName;
    }
  
  else if(status == SINGLE && firstName == "") // single person with no name
  	{
  		cout << "NAME-LESS SINGLE MALE" << endl;	
    }

  else
    {
    	name = firstName + " " + lastName + " is ";
    	name += (status == SINGLE) ? "a single " : "married ";
    	name += (gender == MALE) ? "male." : "female";
    }
  
  return name;
}
