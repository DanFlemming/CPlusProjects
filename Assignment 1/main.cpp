#include <iostream>
#include <cctype>
#include <cstring>
#include <fstream>
#include <cstdlib>
using namespace std;

void stream_fail();
void input(string& password, bool& longEnough, bool& foundUpper, bool& foundLower, bool& foundDigit);
bool validate(string password, bool& longEnough, bool& foundUpper, bool& foundLower, bool& foundDigit);
int conformation(string& password);
void output(string password, bool& longEnough, bool& foundUpper, bool& foundLower, bool& foundDigit);

ifstream in_stream;
ofstream out_stream;

int main()
{
    string password;
    bool longEnough = false;
    bool foundUpper = false;
    bool foundLower = false;
    bool foundDigit = false;

    stream_fail();
    input(password, longEnough, foundUpper, foundLower, foundDigit);
    
    return 0;
}

void stream_fail()      //function reports a failure if the files dont open or write
{
    in_stream.open("wordlist.txt");
    if(in_stream.fail())
    {
        cout << "Input file failed to open." << endl;
        exit(1);
    }

    out_stream.open("DanFlemming.txt");
    if(out_stream.fail())
     {
         cout << "Output file failed to open" << endl;
         exit(1);
     }

}

void input(string& password, bool& longEnough, bool& foundUpper, bool& foundLower, bool& foundDigit)
 {
    string textfile;
    string wordlist; 
    bool procede = false;
    
    cout << "Please enter the name of the text file: ";
    cin >> textfile;


while (procede == false)
{
    if(textfile == wordlist)
        validate(password,longEnough, foundUpper, foundLower, foundDigit);
    
    else if (textfile != wordlist)
        {
            cout << "\nThis file doesnt exist please try again or type Q to quit";
            input(password, longEnough, foundUpper, foundLower, foundDigit);
             
        }
}
 }


bool validate (string password, bool& longEnough, bool& foundUpper, bool& foundLower, bool& foundDigit)
{
    int strLen = password.length();

    if (strLen > 7)
        longEnough = true;

    for (int index = 0; index < strLen; index++)
    {
        if (isdigit(password[index]))
            foundDigit = true;

        if (isupper(password[index]))
            foundUpper = true;

        if (islower(password[index]))
            foundLower = true;
    }

    return (longEnough && foundUpper && foundLower && foundDigit);
}

void output(string password, bool& longEnough, bool& foundUpper, bool& foundLower, bool& foundDigit)
{
    if(!longEnough)
    {
        cout << "*** The password does not contain at least 8 characters\n";
    }

    if(!foundDigit)
    {
        cout << "*** The password does not contain a digit.\n";
    }

    if(!foundUpper)
    {
        cout << "*** The password does not contain an uppercase letter.\n";
    }

    if(!foundLower)
    {
        cout << "*** The password does not contain a lowercase letter.\n";
    }
}
