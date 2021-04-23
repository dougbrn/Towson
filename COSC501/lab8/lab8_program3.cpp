//Lab 8 Program 3: 2-dimensional array
//Doug Branton

#include <iostream>
#include <string>

using namespace std;
//pre-condition: A 2d-array mapping to seats on an airplane
//post-condition: A formatted seatmap
void printSeatmap(string seatmap[][4], int n_rows, int n_cols);

//pre-condition: A 2d-array mapping to seats on an airplane
//post-condition: a bool of whether there are available seats left
bool checkAvailableSeats(string seatmap[][4], int n_rows, int n_cols);

int main(){
    string seatmap[7][4] = {{"A","B","C","D"},
                            {"A","B","C","D"},
                            {"A","B","C","D"},
                            {"A","B","C","D"},
                            {"A","B","C","D"},
                            {"A","B","C","D"},
                            {"A","B","C","D"}};
    bool reserving_seats = true;
    string seat_to_reserve, reserve_another;
    int selected_row, selected_col;

    
    do{
        printSeatmap(seatmap, 7, 4);

        //grab input from the user
        cout << "Enter the seat you want to reserve (e.g. 1A, 2B, ...): ";
        cin >> seat_to_reserve;

        //ASCII Conversions to array indices
        selected_row = seat_to_reserve[0] - 49;
        selected_col = seat_to_reserve[1] - 65;

        if (seatmap[selected_row][selected_col] != "X"){
            seatmap[selected_row][selected_col] = "X";
            printSeatmap(seatmap, 7, 4);

            // check to see if the user would like to continue
            cout << "Would you like to reserve another seat (Y or N)? ";
            cin >> reserve_another;
            if (reserve_another == "N"){
                reserving_seats = false;
            }
        }
        else{
           cout << "That seat has already been reserved, please enter an available seat." << endl;
        }

    } while ((reserving_seats) && (checkAvailableSeats(seatmap, 7, 4)));
    
}

void printSeatmap(string seatmap[][4], int n_rows, int n_cols){
    cout << "Available Seats" << endl;
    for (int i = 0; i < n_rows; i++){
        cout << i+1 << " ";
        for (int j=0; j < n_cols; j++){
            cout << seatmap[i][j] << " ";
        }
        cout << endl;

    }
}

bool checkAvailableSeats(string seatmap[][4], int n_rows, int n_cols){
    bool seats_available = false;

    for (int i = 0; i < n_rows; i++){
        for (int j=0; j < n_cols; j++){
            if (seatmap[i][j] != "X"){
                seats_available = true;
            }
        }
    }
    return seats_available;

}