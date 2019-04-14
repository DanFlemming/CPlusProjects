#include <iostream>
#include <iomanip>

using namespace std;

void input(int& meteorSize, int& meteorDistance);
void meteor_data(int meteorSize, int meteorDistance, int& meteorSpeed, int impactTime);
void engagement_data(int meteorSize, int meteorDistance, double interceptRange, int meteorSpeed);

int main()
{
	int meteorSize, meteorDistance, meteorSpeed;
	double impactTime, interceptRange;

	input(meteorSize, meteorDistance);
	meteor_data(meteorSize, meteorDistance, meteorSpeed, impactTime);
	engagement_data(meteorSize, meteorDistance, interceptRange, meteorSpeed);

	return 0;
}

void input(int& meteorSize, int& meteorDistance)
{
	cout << "\nEnter the meteor size in meters: ";
	cin >> meteorSize;

	cout << "\nEnter the meteor's distance from Earth in miles: ";
	cin >> meteorDistance;
}

void meteor_data(int meteorSize, int meteorDistance, int& meteorSpeed, int impactTime)
{
	meteorSpeed = 120 * meteorSize;
	impactTime = (meteorSpeed/meteorDistance) ;
	
	cout << fixed << showpoint << setprecision(2);
	
	cout << "\nMeteor Data: " << endl;
	cout << "	Diameter in meters: " << meteorSize << endl;
	cout << "	Distance from Earth: " << meteorDistance << endl;
	cout << "	Speed in Miles per hour: " << meteorSpeed << endl;
	cout << "	Time to Impact: " << impactTime << endl;
}

void engagement_data(int meteorSize, int meteorDistance, double interceptRange, int meteorSpeed)
{
	interceptRange = (meteorDistance*meteorSpeed) /3.4;

	cout << "\nEngagement Data: " << endl;
	
	if (meteorSize <= 3 && meteorDistance < 440)
	{
		cout << "   Missile Intercrept Range: " << endl;
		cout << "   MDS Status: " << endl;

	}

	else if ( meteorSize <= 2 && meteorDistance <= 330)
	{
		cout << "   Missile Intercrept Range: " << interceptRange << endl;
		cout << "   MDS Status: " << endl;
	}

	else if (meteorSize <= 1 && meteorDistance <= 220)
	{
		cout << "   Missile Intercrept Range: "<< interceptRange << endl;;
		cout << "   MDS Status: " << endl;
	}

	else
	{
		cout << "   Missile Intercrept Range: " << interceptRange << endl;
		cout << "   MDS Status: Missile Intercept Not Possible" << endl;
		cout << "   Earth Impact in " << endl;


	}
}