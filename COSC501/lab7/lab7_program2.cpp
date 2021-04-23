//Lab 7: Program 2
//Doug Branton
//Random Array and Some Functions

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void printArray(int a[], int size);  //Print array elements from a[0] to a[size-1]
void printArrayReverse(int a[], int size);  //Print array elements from a[size-1] to a[0]
int max(int a[], int size);  //return the maximum value of the array
int min(int a[], int size);  //return the minimum value of the array


int main(){
    int min_val = 1, max_val = 100, rand_array[20], range;

    //seed the random number generator
    srand(time(0));

    for (int i=0; i<20; i++){
        range = max_val - min_val;

        //use the modulus to specify the range of values returned, add the minimum
        rand_array[i] = (rand() % (range+1)) + min_val;   
    }
    cout << "Randomly Generated Array: " << endl;
    printArray(rand_array, 20);
    cout << endl;
    cout << "Randomly Generated Array: (reverse order)" << endl;
    printArrayReverse(rand_array, 20);
    cout << endl;

    cout << "Max value of the array: " << max(rand_array, 20) << endl;
    cout << "Min value of the array: " << min(rand_array, 20) << endl;
}

void printArray(int a[], int size){
    int i;
    cout << "[";
    for (i=0; i < size; i++){
        cout << " " <<  a[i] << " ";
    }
    cout << "]" << endl;
}

void printArrayReverse(int a[], int size){
    int i;
    cout << "[";
    for (i=size-1; i >= 0; i--){
        cout << " " <<  a[i] << " ";
    }
    cout << "]" << endl;
}

int max(int a[], int size){
    int max_val = a[0], i;

    for (i=0; i < size; i++){
        if (a[i] > max_val){
            max_val = a[i];
        }
    }

    return max_val;
}

int min(int a[], int size){
    int min_val = a[0], i;

    for (i=0; i < size; i++){
        if (a[i] < min_val){
            min_val = a[i];
        }
    }

    return min_val;
}