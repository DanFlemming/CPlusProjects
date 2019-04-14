// Daniel Flemming CSE 110 -lab#1
#include <iostream>
using namespace std;

int main()
{
    int hoursWorked;
    double hourlyRate, grossPay, overtime, basePay;

    cout <<"Enter the hourly rate of pay: $";
    cin >> hourlyRate;
    cout << "Enter the number of hours worked, "<<endl;
    cout << "rounded to a whole number of hours: ";
    cin >> hoursWorked;


    
    //calculations
    if (hoursWorked > 40)
    {
        overtime = (hoursWorked - 40) * hourlyRate * 1.5;
        basePay = hourlyRate * 40;
        grossPay = basePay + overtime;
        
    }
    else 
    {
        basePay = hourlyRate * hoursWorked;
        grossPay = hourlyRate * hoursWorked;
        
    }

    
    //output
    cout.setf(ios::fixed);              //used fixed point
    cout.setf(ios::showpoint);          //display the decimal
    cout.precision(2);                  //display two decimals places

    cout << "Hours worked = " << hoursWorked << endl;
    cout << "Hourly rate = $" << hourlyRate << endl;
    cout << "Base Pay = $ " << basePay << endl;
    cout << "overtime pay = $" << overtime << endl;
    cout << "Gross pay = $" << grossPay << endl;

    return 0;
}
