#ifndef COMPLEX_H //<-- directive to see if our class exist
#define COMPLEX_H //<-- define our class if non-existing 

#include <iostream> // <-- cout
using namespace std; // <-- string and endl

class Complex // <-- name of the class
{
    private: // <-- access specifier
        // --- private attributes listed below ---
        float real;
        float imaginary;
        // --- private attributes listed above ---
    public: // <-- access specifier
        // --- public member functions listed below ---
        Complex(float r, float i); // <-- constructor
        ~Complex(); // destructor
        float getReal() const;  // <-- accessor method 
        float getImaginary() const; // <-- accessor method
        void setReal(float r);  // <-- mutator method
        void setImaginary(float i);
        Complex add(Complex c) const;
        // --- public member functions listed above ---
};
#endif // <-- end the if NOT defined statement