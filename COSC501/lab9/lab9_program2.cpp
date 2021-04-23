// COSC 501 Program 2: Dynamic Array
// Doug Branton

#include <iostream>
#include <string>

using namespace std;

typedef string* StrArrayPtr;

// Add an entry to the array
string* addEntry( string *dynamicArray, int &size, string newEntry);
// Delete an entry, if found, from the array
string* deleteEntry(string *dynamicArray, int &size, string entryToDelete);

int main(){
    int array_size = 3, choice;
    string newEntry, entryToDelete;
    StrArrayPtr arr;
    arr = new string[array_size];

    //Initial Three Names
    arr[0] = "Edwin Hubble";
    arr[1] = "James Webb";
    arr[2] = "Nancy Roman";


    do{

        cout << "List of names:" << endl;
        for (int index=0; index < array_size; index++){
            cout << arr[index] << endl;
        }
        cout << endl;

        cout << "1. Add a new name" << endl;
        cout << "2. Remove a name" << endl;
        cout << "3. Quit" << endl;
        cout << endl;

        // Act on the user's choice
        cin >> choice;

        if (choice == 1){
            cout << "Please enter a new name to be added." << endl;
            cin.ignore();
            getline(cin, newEntry);
            arr = addEntry(arr, array_size, newEntry);
        }

        else if (choice == 2){
            cout << "Please enter a name to be deleted." << endl;
            cin.ignore();
            getline(cin, entryToDelete);
            arr = deleteEntry(arr, array_size, entryToDelete);
        }

        else if (choice ==3){
            cout << "Quit the Program." << endl;
            cout << endl;
        }

    } while(choice != 3);

    cout << "List of names:" << endl;
        for (int index=0; index < array_size; index++){
            cout << arr[index] << endl;
        }
        cout << endl;

    return 0;
}

string* addEntry( string *dynamicArray, int &size, string newEntry){

    //Initialize the new array
    size++;
    StrArrayPtr new_arr;
    new_arr = new string[size];

    // Add the existing entries to the new array
    for (int index=0; index < size-1; index++){
        new_arr[index] = dynamicArray[index];
    }

    // Add the new entry
    new_arr[size-1] = newEntry;

    //Delete the old array
    delete [] dynamicArray;

    //Return the new dynamic array
    return new_arr;

}

string* deleteEntry(string *dynamicArray, int &size, string entryToDelete){
    //search the array for the entry to delete
    bool found = false;
    int find_index, new_idx=0;
    for (find_index=0; find_index < size; find_index++){
        if (dynamicArray[find_index] == entryToDelete){
            found = true;
            break;
        }
    }
    //return the original array of the entry is not found
    if (!found){
        cout << "Entry not found in list." << endl;
        return dynamicArray;
    }

    //Initialize the new array
    size--;
    StrArrayPtr new_arr;
    new_arr = new string[size];

    // Add the existing entries to the new array
    for (int index=0; index < size+1; index++){
        if (index != find_index){ //find_index is the location of the found entry
            new_arr[new_idx] = dynamicArray[index];
            new_idx++;
        }
    }

    //Delete the old array
    delete [] dynamicArray;

    //Return the new dynamic array
    return new_arr;   
}