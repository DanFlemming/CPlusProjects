#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

void input(double& temperature, double& windSpeed, double& dewPoint);
double wind_chill(double temperature, double windSpeed);
double cloud_base(double tempSpread);
void output(double windChill, double cloudBase, double temperature, double windSpeed, double dewPoint);

int main()
{

	double windChill, cloudBase, temperature, windSpeed, dewPoint, tempSpread;



	input(temperature, windSpeed, dewPoint);

	windChill = wind_chill(temperature, windSpeed);

	tempSpread = temperature - dewPoint;

	cloudBase = cloud_base(tempSpread);

	output(windChill, cloudBase, temperature, windSpeed, dewPoint);
	return 0;
}

void input(double& temperature, double& windSpeed, double& dewPoint)
{
	const char* script =
        "    ------------------------------------------------------\n"
        "   |""                                                      " "|\n"
        "   |" " This program determines wind chill using temperature " "|\n"
        "   |" " in Fahrenheit and wind speed in mph, and computes    " "|\n"
        "   |" " the cloud base using the dew point in Fahrenheit.    " "|\n"
        "   |""                                                      ""|\n"
        "    ------------------------------------------------------\n\n\n";
	cout << script << endl;


	cout << "   Enter the temperature in degrees Fahrenheit: ";
	cin >> temperature;
	cout << "   Enter the wind speed in mph: ";
	cin >> windSpeed;
	cout << "   Enter the dew point in degrees Fahrenheit: ";
	cin >> dewPoint;
}

double wind_chill(double temperature, double windSpeed)
{
    double windChill; 
    
    windChill = 35.74 + 0.6215 * temperature - 35.75 * pow(windSpeed, 0.16) + 0.4275 * temperature * pow(windSpeed, 0.16);

	return (windChill);
}

double cloud_base(double tempSpread)
{
    double cloudBase;

    cloudBase = tempSpread / 4.4 * 1000;

	return (cloudBase);
}

void output(double windChill, double cloudBase, double temperature, double windSpeed, double dewPoint)
{
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(1);

    cout << endl;
    cout << "   Temperature    Wind Speed   Dew Point   Wind Chill  Cloud Base" << endl;
    cout <<"   ---------------------------------------------------------------------" << endl;

    if (temperature <= 50 && windSpeed >= 3)
    {
        cout << setw(9) << temperature << " dF " << setw(10) << windSpeed << " mph" << setw(10) << dewPoint;
        cout << " dF" << setw(10) << windChill << " dF " << setw(10) << cloudBase << " ft \n" << endl;
    }

    else
    {
        cout << setw(9) << temperature << " dF " << setw(10) << windSpeed << " mph " << setw(10) << dewPoint;
        cout << " dF " << setw(10) << " *** " << setw(10) << cloudBase << " ft \n" << endl;

        cout << "   *** " << "Temperature must be 50 degrees or less. and windspeed" << endl;
        cout << "       must be 3 mph or more to compute wind chill.\n\n";


    }

}

