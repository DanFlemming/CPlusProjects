#include <iostream>
#include <iomanip>
using namespace std;

void input(double& cableLength, double& cableThickness);
void stretching(double cableLength, double cableThickness);
void output(double cableLength, double tension);

int main()
{
   double cableLength, cableThickness, tension;

   input(cableLength, cableThickness);
   stretching(cableLength, cableThickness);

    return 0;

}

void input(double& cableLength, double& cableThickness)
{
	bool validInput = false;

	cout << "Enter the length of the cable in feet: ";
    cin >> cableLength;
    cout << "Enter the thickness of the cable: ";
    cin >> cableThickness;

	// this while loop validates the input from user and prints out a statement on what they typed wrong
	// and asks them to re-input the values.
	while(validInput == false)
    {
		if (cableThickness > 2.0 && cableLength < 0)        //this if has to be first or else it does'nt read at the end
    	{
    		cout << "\n\nEnter a valid cable length.\n\n";
    		cout << "The thickness must be 2.0 inches or less.\n\n";

    		cout << "Enter the length of the cable in feet: ";
			cin >> cableLength;
    		cout << "Enter the thickness of the cable up to 2.0 inches: ";
    		cin >> cableThickness;

    	}

		else if(cableLength < 0)
		{
			cout << "\n\n Enter a valid cable length.\n\n";

			cout << "Enter the length of the cable in feet: ";
			cin >> cableLength;
    		cout << "Enter the thickness of the cable up to 2.0 inches: ";
    		cin >> cableThickness;
        }

    	else if(cableThickness > 2.0)
    	{
    		cout << "\n\nThe thickness must be 2.0 inches or less.\n\n";

    		cout << "Enter the length of the cable in feet: ";
    		cin >> cableLength;
    		cout << "Enter the thickness of the cable up to 2.0 inches: ";
    		cin >> cableThickness;
    	}

    	else
    		validInput = true;                      //  ends the loop because it is true and not false like what I started with

    }


}

void stretching(double cableLength, double cableThickness)
{
    int tension = 0.0;                                  // start the tension at 0
    double breakingPoint = cableLength * 1.16;          //set the breaking point

    // every time the loop goes through one itteration,
    //it calls the output and displays the data 

    while(cableLength < breakingPoint)                	//while it has'nt broken
    {
    	tension++;
    	cableLength = cableLength +(cableThickness * .3);    //the stretching of the cable
    	output(cableLength, tension);

    }
    cout << "\n\n<<<<< The cable has broken >>>>>" << endl;

}





void output(double cableLength, double tension)
{
	cout << fixed << showpoint << setprecision(2);

	cout << "\n\nThe tension on the cable is: " << tension << " lbs\n" << endl;

	cout << "The length of the cable is: " << cableLength << " feet" << endl;
}
