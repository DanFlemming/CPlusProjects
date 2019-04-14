/*
  Developer: Daniel Flemming
  Language: C++
  Course: CSE-111
  Assignment: Lab #1
*/

#include <stdlib.h>
#include <cctype> // for tolower(char) - converts a char to lower case
#include <iostream> // cout and cin
#include <fstream> // ofstream

using namespace std;

// function prototypes
bool isPalindrome(string word);
ofstream close(int index, ofstream files[2]);

int main ()
{
  string word;
  int index =0;

  ofstream files[2];

  bool isPalindrome(string word);


   do{

    cout << "\nEnter a word: ";
    cin >> word;

    isPalindrome(word);

    if(isPalindrome(word))
      { 
        cout << word << " IS Valid!" << endl;
        index = 0; 
        files[index].open("palindromes.txt"); 

      }

    else 
      {  
        cout << word << " IS Not Valid." << endl;
        index = 0;
        files[index].open("non-palindromes.txt"); // opens a different file when the word isnt valid
      }

    //output
    files[index]<< word;  // fills array index 0 with the typed word 
    files[index].close();
    index = 0;
   
   cout << "\nWould you like to quit the program? (yes or no): ";
   cin >> word;


  }while(word != "yes");

  return 0;
}

// is palindrome with recursion
bool isPalindrome(string word)
{
  int length;
  char first, last;

     length = word.length();
     first = word[0];
     last = word[length-1];

    if (first != last)  
      return false;

    if (length == 1)
      return true;

    else if (length == 2)
      return first == last;

    else  
      word = isPalindrome (word.substr(1, length-2));  // comparing the middle characters of the word (start,length)
    
 
}

ofstream close(int index, ofstream files[2])
{ 
    files[index].close();
    index = 0;
}