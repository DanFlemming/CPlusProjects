
#include "Complex.h" // <-- bring the Complex class into scope
#include <iostream>

using namespace std;

int main()
{
    // initialize 3 Complex objects
    Complex number1(5.0,2.0); // call the constructor

     // dynamically allocate a Complex object
    Complex* number2Ptr = new Complex(-5.0,2.0);
    
    // call the add member function
    /* Note: because number2Ptr is a pointer and add is 
       looking for a Complex object we dereference number2Ptr 
       inorder to call the add function with it */
    Complex number3 = number1.add(*number2Ptr); 
    

    // display the contents of the object 
    // with their get functions
    cout << "number1 = " << number1.getReal()  << " + " 
         << number1.getImaginary() << "j" << endl;
    cout << "number2 = " << number2Ptr->getReal()  << " + " 
         << number2Ptr -> getImaginary() << "j" << endl;
    cout << "number3 = " << number3.getReal()  << " + " 
         << number3.getImaginary() << "j" << endl;
    
    number1.setReal(100.0);
    number1.setImaginary(100.0);
    cout << "number1 = " << number1.getReal()  << " + " 
         << number1.getImaginary() << "j" << endl;
    
    delete number2Ptr;
    // when the program concludes the destructors 
    // for the number1 and number3 gets called
    return 0;
}
