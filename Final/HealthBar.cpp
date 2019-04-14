#include <iostream>
#include "HealthBar.h"
using namespace std;

Item::Item(int s, int m, int l) 
{
	this-> small_bar = s; 
	this-> medium_bar = m; 
	this-> large_bar = l;
}