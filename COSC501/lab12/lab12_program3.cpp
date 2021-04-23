// Lab 12 Program 3: Recursion 2
// Doug Branton

#include <iostream>

using namespace std;

//returns the factorial of n
//needs to be an unsigned long long to have enough bits to handle 50!
unsigned long long int factorial(int n);

int main(){
    cout << "5! = " << factorial(5) << endl;
    cout << "10! = " << factorial(10) << endl;
    cout << "25! = " << factorial(25) << endl;
    cout << "50! = " << factorial(50) << endl;
}

unsigned long long int factorial(int n){
    if (n==0){
        return 1; //0! = 1
    }
    else{
        return n*factorial(n-1);
    }
}