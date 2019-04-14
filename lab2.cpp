// Daniel Flemming CSE 110 -lab#2
#include <iostream>
using namespace std;

int main()
{
    int hoursWorked;
    double hourlyRate, grossPay, overtime, basePay, doubleTime, overtimePay, overtime_hours, doubletime_hours;

    cout <<"Enter the hourly rate of pay: $";
    cin >> hourlyRate;
    cout << "Enter the number of hours worked, " << endl;
    cout << "rounded to a whole number of hours: ";
    cin >> hoursWorked;

    //calculations
    overtime = 0;
    doubleTime = 0;
    doubletime_hours = 0;
    overtime_hours = 0;

    if (hoursWorked > 40 && hoursWorked <= 50)
    {
    	overtime = (hoursWorked - 40) * hourlyRate * 1.5;
        basePay = hourlyRate * 40;
        grossPay = basePay + overtime;
        overtime_hours = hoursWorked - 40;
        overtimePay = overtime;

	}
    else if(hoursWorked > 50)
    {
        doubleTime = (hoursWorked - 50) * hourlyRate * 2;
        doubletime_hours = hoursWorked - 50;
        overtime = 10 * (hourlyRate * 1.5);
        basePay = hourlyRate * 40;
        grossPay = basePay + doubleTime + overtime;
        overtimePay = overtime + doubleTime;
        overtime_hours = 10;
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
    cout << "Overtime hours at time and a half = " << overtime_hours << endl;
    cout << "Overtime pay at time and a half = $" << overtime << endl;
    cout << "Overtime hours at double time = " << doubletime_hours << endl;
    cout << "Overtime pay at double time = $" << doubleTime << endl;
    cout << "Overtime pay = $" << overtimePay << endl;
    cout << "Gross pay = $" << grossPay << endl;

    return 0;
}
