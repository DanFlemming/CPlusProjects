#include "Person.h"
#include <iostream>
using namespace std;

Person::Person() 
{
	this-> name = "Empty"; 
	this-> Health = 0; 
	this-> strength = 0; 
	this-> speed = 0;
}
    

Person::Person(string n, int h, int st, int sp) 
{
	this-> name = n; 
	this-> Health = h; 
	this-> strength = st; 
	this-> speed = sp;
}

Person::~Person()
{
	
}

string Person::get_name() 
{
	return name;
}
        
int Person::get_health() 
{
	return Health;
}

int Person::get_strength() 
{
	return strength;
}

int Person::get_speed() 
{
	return speed;
}
     
void Person::set_name(string n) 
{
	name = n;
}

void Person::set_health(int h) 
{
	Health = h;
}

void Person::set_strength(int st) 
{
	strength = st;
}

void Person::set_speed(int sp) 
{
	speed = sp;
}

