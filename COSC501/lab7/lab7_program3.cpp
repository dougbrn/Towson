// Lab 7: Program 3
// Doug Branton
// Counting numbers in a file

#include <iostream>
#include <fstream>

using namespace std;


//Precondition: number used <= declared size of array a
//Postcondition: The values of arr[0] through arr[length -1] have
//been rearranged so that arr[0] <= arr[1] <= .. <= arr[length - 1]
void bubblesort(int arr[], int length);

//Precondition: An input array, a storage array for the unique elements, a storage array for
// the occurence counts of those unique elements, an initialized (set to 0) idx, the input array length,
// and the value to skip (the DEFAULT)
//Postcondition: Populated unique_arr and count_arr that have the unique elements in in_arr and their number
//of occurences.
void count_arr_vals(int in_arr[], int unique_arr[], int count_arr[], int& new_idx, int in_arr_length, int skip_val);


int main(){
    ifstream in_stream;
    const int DEFAULT = 999;
    int in_arr[50], unique_arr[50], count_arr[50], i=0, current_int;

    //initialize the input array
    for (int x=0; x < 50; x++){
        in_arr[x] = DEFAULT; //assign a standardized default value
    }

    //create the file stream object
    in_stream.open("Lab7_3input.txt");

    //store each file element into the array
    while (!in_stream.eof()){
        in_stream >> current_int;
        in_arr[i] = current_int;
        i++;
    }


    //sort the array from smallest to largest
    bubblesort(in_arr, 50);

    //count array values
    int new_idx = 0;
    count_arr_vals(in_arr, unique_arr, count_arr, new_idx, 50, DEFAULT);

    cout.width(5);
    cout << left << "N" << "  " << "Count" << endl;
    //print out the results
    for (int j=(new_idx-1); j >= 0; j--){
        cout.width(5); 
        cout << left << unique_arr[j] <<  "  " << count_arr[j] << endl;
    }




    in_stream.close();


}

void bubblesort(int arr[], int length){
    //Bubble largest number toward the right
    for (int i = length-1; i > 0; i--){
        for (int j = 0; j < i; j++){
            if (arr[j] > arr[j+1]){
                // Swap the numbers
                int temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void count_arr_vals(int in_arr[], int unique_arr[], int count_arr[], int& new_idx, int in_arr_length, int skip_val){
    //the sorted array features like-elements adjacent to one another
    //can use this to count where array[index+1] = array[index] to establish
    //the unique elements and their number of occurences
    //skip elements equal to the skip_val
    bool counting = false;
    for (int idx = 0; idx < in_arr_length; idx++){
        if (in_arr[idx] != skip_val){ //ignore specified skip value

            //if we aren't counting, that means we've encountered a new unique element
            if (!counting){
                unique_arr[new_idx] = in_arr[idx]; // add it to the array
                count_arr[new_idx] = 1; // set the count to 1
                if (in_arr[idx + 1] == in_arr[idx]){ // check to see if the next element is the same as the current element
                    counting = true; // if it is, start counting
                }
                else{
                    new_idx++; //move one array element forward
                }
            }
            else if (counting){ // if we're counting, stay at the array index and tick up the count
                count_arr[new_idx] += 1;
                if (in_arr[idx + 1] != in_arr[idx]){ // check to see if the next element is different
                    counting=false; // if it's different, we are no longer counting the current element
                    new_idx++; //move one array element forward
                }
            }
        }
    }
}
