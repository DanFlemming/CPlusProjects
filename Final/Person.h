#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>

using namespace std;
 
class Person 
{
    private: 
        string name;
        int Health;
        int strength;
        int speed;
 
    public:
        Person();
        Person(string n, int h, int st, int sp);
        ~Person();
        string get_name();
        int get_health();
        int get_strength();
        int get_speed();
     
        void set_name(string n);
        void set_health(int h);
        void set_strength(int st);
        void set_speed(int sp);
};
 
#endif // PERSON_H