#include "Person.h"
#include <iostream>

using namespace std;

// function prototypes ;
//string personToString(Person p);
//void displayPeople(Person* p, int n);

int main()
{
	// Create 2 people
    
    // make person 1
    Person person1; // default constructor called
    person1.toString();// for NAME-LESS MALE
    Person("Daniel", "Flemming", MALE); // OVERLOADED CONSTRUCTOR for ...
    
    // PERSON1 .... SET first/last/gender 
    person1.setGender(MALE);
    cout << person1.toString();
    person1.setFirstName("Daniel");
	cout << person1.toString() << endl;
    person1.setLastName("Flemming");
    cout << person1.toString() << endl;
    
    // make PERSON2 a dynamically allocated object
    Person* person2Ptr = new Person;
    cout << person2Ptr-> toString();
    Person("Nicole", "Dover", FEMALE); 
    
    //PERSON2 SET first/last/gender
    person2Ptr->setGender(FEMALE);
    cout << person2Ptr-> toString();
    person2Ptr->setFirstName("Jacqueline");
    cout << person2Ptr-> toString() << endl;
    person2Ptr->setLastName("Brescia");
    cout << person2Ptr-> toString() << endl;

    // SET STATUS for people 1-2
    cout << endl;
    person1.setStatus(MARRIED);
    cout << person1.toString() << endl;

    // MARRY THEM
    //Person isMarried;
    if(person1.isMarried())
    {
        cout << endl;
        person1.setSpouse(*person2Ptr);
        cout << person1.toString() << endl;
        cout << person2Ptr-> toString() << endl;
    }

    else
        cout << "The bride chokes and runs away" << endl;

    //why doesnt this program run... because i was compiling wrong for dayzzz
    // to compile use: g++ Person.cpp
    // then: g++ Person.o main.cpp -o main
    // lastly: main
    
    delete person2Ptr;
    return 0;
}