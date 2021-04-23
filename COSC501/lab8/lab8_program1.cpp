//Lab 8 Program 1: Sorting a String Array
//Doug Branton


#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//Precondition: number used <= declared size of array a
//Postcondition: The values of arr[0] through arr[length -1] have
//been rearranged so that arr[0] <= arr[1] <= .. <= arr[length - 1]
void bubblesort(string arr[], int length);

int main(){

    ifstream in_stream;
    string str_arr[30];
    int i = 0;

    in_stream.open("fruits.txt");

    //read the input file into an array of length 30
    cout << "Before Sorting:" << endl;
    while(!in_stream.eof()){

        in_stream >> str_arr[i];
        
        //avoid a trailing comma
        if (i!=29){
            cout << str_arr[i] << ", ";
        }
        else{
            cout << str_arr[i] << endl;
        }
        i++;
    }
    cout << endl << endl;

    in_stream.close();

    //sort the values from "smallest" to "largest"
    bubblesort(str_arr,30);

    cout << "After Sorting:" << endl;
    for (int j=0; j < 30; j++){

        //avoid a trailing comma
        if (j!=29){
            cout << str_arr[j] << ", ";
        }
        else{
            cout << str_arr[j] << endl;
        }

    }

}

void bubblesort(string arr[], int length){
    //Bubble "largest" string toward the right
    for (int i = length-1; i > 0; i--){
        for (int j = 0; j < i; j++){
            if (arr[j] > arr[j+1]){
                // Swap the numbers
                string temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
