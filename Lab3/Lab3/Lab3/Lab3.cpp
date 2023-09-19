// Lab3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<iostream>
#include<string>
#include"complex.h"

std::ostream& operator << (std::ostream& out, complex& number) {    // Show the result

    if (number.complex_ >= 0) {out << number.real_ << " + " << number.complex_ << "i " << std::endl;}
    else { out << number.real_ << " - " << abs(number.complex_) << "i " << std::endl; }
    return out;
}

complex createComplex() {       // So that the creation code doesnt copy/paste

    double x, y;
    std::cout << "Enter a cartesian component: ";
    std::cin >> x;

    std::cout << "\nEnter a complex component: ";
    std::cin >> y;

    return complex(x, y);

}

int main()
{
    
    while (true)    // Repeat as many times as you want
    {
        double scalar = 0;
        int a = 0;



        std::cout << "Select an operation: \n1: Addition \n2: Subtraction \n3: Scalar Multiplication \n4: Scalar Division \n0: Exit Program" << std::endl;
        std::cout << "Enter the number of the operation: ";
        std::cin >> a;


        switch (a) {
        default:
            system("CLS");
            std::cout << "No valid option selected. \nPlease enter the number to the left of your desired operation." << std::endl;
        case 0:
            return 0;
        case 1:
            system("CLS");
            std::cout << "Create the first complex number" << std::endl;
            complex complex1 = createComplex();

            std::cout << "Create the second complex number" << std::endl;
            complex complex2 = createComplex();

            complex complex3 = complex1 + complex2;

            system("CLS");
            std::cout << "Result is: " << complex3 << std::endl;
        case 2:
            system("CLS");
            std::cout << "Create the first complex number" << std::endl;
            complex complex1 = createComplex();

            std::cout << "Create the second complex number" << std::endl;
            complex complex2 = createComplex();

            complex complex3 = complex1 - complex2;

            system("CLS");
            std::cout << "Result is: " << complex3 << std::endl;
        case 3:
            system("CLS");
            std::cout << "Create the first complex number" << std::endl;
            complex complex1 = createComplex();

            std::cout << "enter your scalar quantity: ";
            std::cin >> scalar;

            complex complex3 = complex1 * scalar;

            system("CLS");
            std::cout << "Result is: " << complex3 << std::endl;
        case 4:
            system("CLS");
            std::cout << "Create the first complex number" << std::endl;
            complex complex1 = createComplex();

            std::cout << "enter your scalar quantity: ";
            std::cin >> scalar;

            complex complex3 = complex1 / scalar;

            system("CLS");
            std::cout << "Result is: " << complex3 << std::endl;
        }
    }
    return 0;
}
