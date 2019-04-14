#include "Complex.h" // <-- must link to the header file

// BELOW IMPLEMENT EACH FUNCTION DEFINED IN THE HEADER

Complex::Complex(float real, float imaginary)
{
    this->real = real;
    this->imaginary = imaginary;
    cout << "constructor was called" << endl;
}

Complex::~Complex()
{
    cout << "destructor was called" << endl;
}

float Complex::getReal() const{
    
    return this->real;
}

float Complex::getImaginary() const{
    return this->imaginary;
}

void Complex::setReal(float real)
{
    cout << "setReal() was called" << endl;
    this->real = real;
}

void Complex::setImaginary(float imaginary)
{
    cout << "setImaginary() was called" << endl;
    this->imaginary = imaginary;
}


Complex Complex::add(Complex c) const
{
    float r = this->real + c.getReal();
    float i = this->imaginary + c.getImaginary();
    return Complex(r,i);
}