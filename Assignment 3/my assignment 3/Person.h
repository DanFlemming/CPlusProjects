#ifndef PERSON_H
#define PERSON_H
#include <iostream>
using namespace std;


/******************************
 *     enum declaration(s)    *
 ******************************/
  enum Status //2.1, MARRIED OR NOT
  {
    SINGLE,
    MARRIED
  };
  
  enum Gender //2.2, GENDER
  {
    MALE,
    FEMALE
  };

/******************************
 *    class declaration(s)   *
 ******************************/
  class Person //initilize the struct
    {
        private:
            string firstName;
            string lastName;
            Status status;  //2.1
            Gender gender; //2.2
            Person *spousePtr;
        public:
            Person();
            Person(string first, string last, Gender gender);
            ~Person();
            string getFirstName() const;
            string getLastName() const;
            Gender getGender() const;
            Person* getSpouse() const;
            void setFirstName(string firstName);
            void setLastName(string lastName);
            void setGender(Gender gender);
            void setSpouse(Person & spouse);
            void setStatus(Status status);
            bool isMarried();
            string toString();
	};
#endif // PERSON_H