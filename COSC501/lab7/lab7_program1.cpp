// Lab 7: Program 1
// Doug Branton
// Averaging Even and Odd Numbers

#include <iostream>
#include <iomanip>

using namespace std;

//pre-conditions: An integer array and an integer length of the array
//post-conditions: the array printed to the terminal
void printArray(int array[], int array_len);

int main(){
    const int ARRAY_LEN = 10;
    int array[ARRAY_LEN], i, even_tot = 0, odd_tot=0, even_count=0, odd_count=0;
    double even_avg, odd_avg;

    cout << "Enter 10 numbers:" << endl;
    //cin >> array[0];
    for (i=0; i < ARRAY_LEN; i++){
        cin >> array[i];

        //even
        if (i % 2 == 0){
            even_tot += array[i];
            even_count++;
        }
        else{
            odd_tot += array[i];
            odd_count++;
        }
    }
    cout << endl;
    printArray(array, ARRAY_LEN);

    even_avg = 1.0 * even_tot/even_count;
    odd_avg = 1.0 * odd_tot/odd_count;

    cout << fixed << setprecision(2) << "Average of even elements: " << even_avg << endl;
    cout << fixed << setprecision(2) << "Average of odd elements: " << odd_avg << endl;


}

void printArray(int array[], int array_len){
    int i;

    cout << "List of the array elements" << endl;

     for (i=0; i < array_len; i++){
        cout << "array[" << i << "]: " << array[i] << endl;
    }
}