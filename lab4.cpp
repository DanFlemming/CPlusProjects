// Daniel Flemming CSE 110 -lab#4
#include <iostream>
using namespace std;

double tax_withholdings(int dependents, double modGross);
double ira_deduction(double grossPay);

int main()
{
    int hoursWorked, dependents, overtimeHours, doubletimeHours;
    double hourlyRate, grossPay, overtimePay, basePay, doubletimePay, totalOvertime, tax, netPay, modGross, deduction;

    //input
    cout <<"Enter the hourly rate of pay: $";
    cin >> hourlyRate;
    cout << "Enter the number of hours worked, " << endl;
    cout << "rounded to a whole number of hours: ";
    cin >> hoursWorked;
    cout << "Enter your number of dependents: ";
    cin >> dependents;

    //calculations
    overtimePay = 0;
    doubletimePay= 0;
    doubletimeHours = 0;
    overtimeHours = 0;
    totalOvertime = 0;

	if (hoursWorked > 40 && hoursWorked <= 50)
    {
    	overtimePay = (hoursWorked - 40) * hourlyRate * 1.5;
        basePay = hourlyRate * 40;
        grossPay = basePay + overtimePay;
        overtimeHours = hoursWorked - 40;
        totalOvertime = overtimePay;
	}

    else if(hoursWorked > 50)
    {
        doubletimePay = (hoursWorked - 50) * hourlyRate * 2;
        doubletimeHours = hoursWorked - 50;
        overtimePay = 10 * (hourlyRate * 1.5);
        basePay = hourlyRate * 40;
        grossPay = basePay + doubletimePay + overtimePay;
        totalOvertime = overtimePay + doubletimePay;
        overtimeHours = 10;
    }

    else
    {
        basePay = hourlyRate * hoursWorked;
        grossPay = hourlyRate * hoursWorked;
    }

    deduction = ira_deduction(grossPay);
    modGross = grossPay - ira_deduction(grossPay);
    tax = tax_withholdings(dependents, modGross); // function call
    netPay = modGross - tax;


	//output
    cout.setf(ios::fixed);              //used fixed point
    cout.setf(ios::showpoint);          //display the decimal
    cout.precision(2);                  //display two decimals places

    cout << "Hours worked = " << hoursWorked << endl;
    cout << "Hourly rate = $" << hourlyRate << endl;
    cout << "Base Pay = $ " << basePay << endl;
    cout << "Overtime hours at time and a half = " << overtimeHours << endl;
    cout << "Overtime pay at time and a half = $" << overtimePay << endl;
    cout << "Overtime hours at double time = " << doubletimeHours << endl;
    cout << "Overtime pay at double time = $" << doubletimePay << endl;
    cout << "Overtime pay = $" << totalOvertime << endl;
    cout << "Gross pay = $" << grossPay << endl;
    cout << "IRA deduction =$" << deduction << endl;
    cout << "Modified gross pay =$" << modGross << endl;
    cout << "Tax Withholding Amount = $" << tax << endl;
    cout << "Net pay = $" << netPay << endl;

    return 0;
}


double tax_withholdings(int dependents, double modGross) // calculate taxes for netPay
{
    double tax;

	if (dependents == 0)
    	{tax = modGross * .28;}

    else if (dependents == 1)
    	{tax = modGross * .20;}

    else if (dependents == 2)
    	{tax = modGross * .18;}

    else if (dependents >= 3)
    	{tax = modGross * .15;}

    else
    	{return 0;}

    return (tax);
}

double ira_deduction(double grossPay)
{
    double deduction;

    if(grossPay > 400 && grossPay < 500)
        deduction = grossPay * .05;

    else if(grossPay >= 500)
        deduction = grossPay * .10;
    
    else
        deduction = 0;

    return(deduction);
}