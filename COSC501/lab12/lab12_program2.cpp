// Lab 12 Program 3: Recursion 1
// Doug Branton

#include <iostream>

using namespace std;

//returns the nth fibonacci number
int fibonacci(int n);

int main(){
    cout << "Fibonacci Number for 0: " << fibonacci(0) << endl;
    cout << "Fibonacci Number for 1: " << fibonacci(1) << endl;
    cout << "Fibonacci Number for 2: " << fibonacci(2) << endl;
    cout << "Fibonacci Number for 3: " << fibonacci(3) << endl;
    cout << "Fibonacci Number for 6: " << fibonacci(6) << endl;
    cout << "Fibonacci Number for 12: " << fibonacci(12) << endl;
}

int fibonacci(int n){
    if (n==0){
        return 0; //F_0 = 0
    }
    if (n==1){
        return 1; //F_1 = 1
    }
    else{
        return fibonacci(n-2) + fibonacci(n-1); //F_n = F_n-2 + F_n-1
    }

}