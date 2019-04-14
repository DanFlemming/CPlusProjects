#include "Person.h"
#include <iostream>
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int fight_moves(int st, int sp, int num) 
{
    srand(time(NULL));
    int rand_num;
    int addition;
 
    switch(num) 
    {
        case 1: 
        {  // Punch
            rand_num = rand() % 40 + 1;
            addition = (st + sp) / rand_num;
            cout << "\n\t\tDamage inflicted: " << addition;
            return addition; break;
        }
        case 2: 
        {  // Kick
            rand_num = rand() % 20 + 1;
            addition = (st + sp) / rand_num;
            cout << "\n\t\tDamage inflicted: " << addition;
            return addition; break;
        }
        case 3: 
        {  // Slam
            rand_num = rand() % 30 + 1;
            addition = (st + sp) / rand_num;
            cout << "\n\t\tDamage inflicted: " << addition;
            return addition; break;
        }
        case 4: 
        {  // Drop kick
            rand_num = rand() % 30 + 1;
            addition = (st + sp) / rand_num;
            cout << "\n\t\tDamage inflicted: " << addition;
            return addition; break;
        }
    }
}