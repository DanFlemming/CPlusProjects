#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

int main()
{
    stack< int, vector<int> > w;//vector iStack *pg 1083
    
    //stack <int> x;

    //push values onto Stack
    cout << "Pushing numbers now" << endl;
    w.push(0);
    w.push(9);
    w.push(12);
    w.push(1);
    //end pushing values in 
    
    int MAXw = w.size(); // max value the iStack can store *table 18-3 // only reconginzes this whe
    //when its placed after the pushes.... 
    
    //pop off Stack values
    cout << "Displaying pushed numbers with pop"<< endl;
    for (int i=0; i<MAXw; i++)
    {
        cout << "Popping " << w.top() << endl;
        w.pop();
    }
    cout<< "End popping\n" << endl;

  //*******************************************
  //               EXERCISE 23 
  //*******************************************
    
    stack< int, vector<int> > x;//vector iStack *pg 1083
    // pushing numbers 
    x.push(8);
    x.push(7);
    //pop off top value
    x.pop();
    x.push(19);
    x.push(21);
    x.pop();
    // end of pushing values in

    int MAXx = x.size();
    
    // display stack numbers
    cout << "Displaying pushed numbers with pop"<< endl;
    
    for (int i=0; i<MAXx; i++)
    {
        cout << "Popping " << x.top() << endl;
        x.pop();
    }
    cout<< "End popping\n" << endl;

    //******************************************
    //              EXERCISE 24
    //******************************************

     queue<int> y;//pg 1098
     
     y.push(5);
     y.push(7);
     y.push(9);
     y.push(12);
     //end populaton of enquenue

     int MAXy = y.size();
     cout << "Displaying the enquenue items" << endl;
     
     //loop with the proper changed values for the enquenue
     for(int i=0; i<MAXy; i++)
     {
        cout << "Popping " << y.front() << endl;
        y.pop();
     }
     cout<< "End popping\n" << endl;

     //*******************************************
     //             EXERCISE 25
     //*******************************************

     queue<int> z;
     z.push(5);
     z.push(7);
     z.pop();
     y.push(9);
     y.push(12);

     int MAXz = z.size();

     cout << "Displaying the enquenue items" << endl;
 
     for(int i=0; i<MAXz; i++)
     {
        cout << "Popping " << z.front() << endl;
        z.pop();
     }
     cout<< "End popping\n" << endl;
  
  
    return 0;
}
