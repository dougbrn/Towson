// Lab 11 Program 1: Class
// Doug Branton

#include <iostream>

using namespace std;

class RationalNumber{
    public:

        // Overload the constructors to account for the denominator and non-denominator case
        RationalNumber(int Numerator, int Denominator);
        RationalNumber(int Numerator);

        // Print the number to screen
        void printNumber();

        // Arithmetic operations
        void add(RationalNumber number_to_add);
        void subtract(RationalNumber number_to_subtract);
        void multiply(RationalNumber number_to_multiply);
        void divide(RationalNumber number_to_divide);

        int numerator;
        int denominator;
};


int main() {
RationalNumber rn1(1,6);
RationalNumber rn2(2);

cout << "First number: ";
rn1.printNumber();

cout << "\nSecond number: ";
rn2.printNumber();

cout << "\nAddition: ";
rn1.add(rn2);

cout << "\nSubtraction: ";
rn1.subtract(rn2);

cout << "\nMultiplication: ";
rn1.multiply(rn2);

cout << "\nDivision: ";
rn1.divide(rn2);

return 0;
}

RationalNumber::RationalNumber(int Numerator, int Denominator){
    numerator = Numerator;
    denominator = Denominator;
}

RationalNumber::RationalNumber(int Numerator){
    numerator = Numerator;
    denominator = 1;
}

void RationalNumber::printNumber(){
    cout << numerator << "/" << denominator;
}

void RationalNumber::add(RationalNumber number_to_add){

    int sum_numerator, sum_denominator;
    sum_numerator = (numerator * number_to_add.denominator) + (denominator * number_to_add.numerator);
    sum_denominator = denominator * number_to_add.denominator;
    RationalNumber sum(sum_numerator,sum_denominator);
    sum.printNumber();
}

void RationalNumber::subtract(RationalNumber number_to_subtract){

    int difference_numerator, difference_denominator;
    difference_numerator = (numerator * number_to_subtract.denominator) - (denominator * number_to_subtract.numerator);
    difference_denominator = denominator * number_to_subtract.denominator;
    RationalNumber difference(difference_numerator,difference_denominator);
    difference.printNumber();
}

void RationalNumber::multiply(RationalNumber number_to_multiply){

    int product_numerator, product_denominator;
    product_numerator = numerator * number_to_multiply.numerator;
    product_denominator = denominator * number_to_multiply.denominator;
    RationalNumber product(product_numerator,product_denominator);
    product.printNumber();
}

void RationalNumber::divide(RationalNumber number_to_divide){

    int quotient_numerator, quotient_denominator;
    quotient_numerator = numerator * number_to_divide.denominator;
    quotient_denominator = number_to_divide.numerator * denominator;
    RationalNumber quotient(quotient_numerator,quotient_denominator);
    quotient.printNumber();
}