// COSC 501 Semester Programming Assignment
// Doug Branton

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

//check a string to see if it's a student ID
bool check_if_id(const string s);

//find the number of students in the file
int num_students(string f_name);

//return the numerical gpa from a letter grade
double gpa_from_letter(string letter_grade);

//Precondition: A 2d-array, the number of rows and columns, and the column to sort on
//Postcondition: The array sorted in ascending order based on the selected sort column
void bubblesort_2d(string **array, int row_len, int col_len, int sort_col);

//Produces a formatted report of student information
string student_report(string array[]);

//Produces a formatted report of student information for the most recent semester
string semester_report(string array[], int semester_credits, int total_credits, double cumulative_gpa);

int main(){
    ifstream in_stream, count_stream;
    ofstream out_stream;
    string current_str;
    const int N_COLS = 25;
    int n_students, row_idx=-1, col_idx=0;

    n_students = num_students("Students.txt"); //Find the number of students

    in_stream.open("Students.txt");
    out_stream.open("GradeReportsFall2020.txt");

    //Read the input data into a 2d array
    //Create a 2d array of size n_students x 25
    string **array = new string*[n_students];
    for (int count = 0; count < n_students; ++count){
        array[count] = new string[N_COLS];
    }

    //Initialize the 2d array to have the empty string "" in every element
    for (int i=0; i < n_students; i++){
        for (int j=0; j < N_COLS; j++){
            array[i][j] = "";
        }
    }

    // loop through the in_stream and populate the array
    while (!in_stream.eof()){
        in_stream >> current_str;

        if (check_if_id(current_str)){
            //cout << current_str << endl;
            col_idx=0; //reset the col_idx as we're onto a new student
            row_idx++; //Increment up the row as we're onto a new student

            array[row_idx][col_idx] = current_str; //assign id to 2d array

            col_idx++;  //Increment up the column after array assignment
        }
        else{
            array[row_idx][col_idx] = current_str;
            col_idx++; 
        }
    }

    //Sort the students by ID in ascending order
    bubblesort_2d(array, n_students, N_COLS, 0);

    
    //Calculate the Fall 2020 semester grade and update the cumulative GPA
    for (int i=0; i < n_students; i++){
        double grade, semester_gpa = 0.0;
        int credits, total_semester_credits = 0;
        string letter_grade, student_info, semester_info;

        //Print out Student Report
        student_info = student_report(array[i]);
        cout << student_info;
        out_stream << student_info;

        //Fall course begin after the 8th element in order: Total Classes, [Course, Credits, Letter Grade (repeating)]
        if (stoi(array[i][9]) != 0){ //Calculate only if the student is enrolled
            for (int j=10; j < N_COLS; j++){
                if (j%3 == 2){  //Credits
                    if (array[i][j] == ""){
                        j=j+2; //skip forward if no credit weight or empty
                    }
                    else{
                        credits = stoi(array[i][j]);
                    }
                }
                else if (j%3 == 0){ //Grade
                    letter_grade = array[i][j];
                    if (letter_grade != "W"){
                        grade = gpa_from_letter(letter_grade);
                        semester_gpa += grade * credits;
                        total_semester_credits += credits;
                    }
                }
            }
            semester_gpa /= total_semester_credits;  //Semester GPA

            //Calculate new cumulative GPA
            int total_credits_old = stoi(array[i][7]);
            double cumulative_gpa_old = stod(array[i][8]);
            double cumulative_gpa_new;
            int total_credits_new;

            total_credits_new = total_credits_old + total_semester_credits;
            cumulative_gpa_new = ((total_credits_old*cumulative_gpa_old)+(total_semester_credits*semester_gpa))
            /(total_credits_new);

            //cout << cumulative_gpa_new << " " << total_credits_new << endl; 
            array[i][7] = total_credits_new;
            array[i][8] = cumulative_gpa_new;

            semester_info = semester_report(array[i], total_semester_credits, 
            total_credits_new, cumulative_gpa_new);
            cout << semester_info;
            out_stream << semester_info;
            }
    }

    in_stream.close();
    out_stream.close();
}

bool check_if_id(const string s){
    bool digits, length;
    //check that the string only contains digits
    digits = s.find_first_not_of( "0123456789" ) == string::npos;
    //check that the string is of the correct length of a student ID (9)
    length = s.length() == 9;

    return digits * length;
}

int num_students(string f_name){
    ifstream in_stream;
    string current_str;
    int n_students = 0;

    in_stream.open(f_name);

    while (!in_stream.eof()){
        in_stream >> current_str;
        if (check_if_id(current_str)){
            //a student is a student only if they have a student ID
            n_students++;
        }
    }
    in_stream.close();
    return n_students;
}

void bubblesort_2d(string **array, int row_len, int col_len, int sort_col){
    //Bubble largest number toward the bottom
    for (int i = row_len - 1; i > 0; i--){
        for (int j = 0; j < i; j++){
            if (array[j][sort_col] > array[j+1][sort_col]){
                // Swap the rows
                for (int k=0; k < col_len; k++){
                    string temp = array[j+1][k];
                    array[j+1][k] = array[j][k];
                    array[j][k] = temp;
                }
            }
        }
    }
}

double gpa_from_letter(string letter_grade){
    if (letter_grade == "A"){
        return 4.0;
        }
    else if (letter_grade == "B"){
        return 3.0;
    }
    else if (letter_grade == "C"){
        return 2.0;
    }
    else if (letter_grade == "D"){
        return 1.0;
    }
    else if (letter_grade == "F"){
        return 0.0;
    }
    else{
        return 0.0;
    }
}

//Produces a formatted report of student information
string student_report(string array[]){
    string report = "";
    report += "Student ID number: " + array[0] + "\n";
    report += "Name: " + array[1] + ", " + array[2] + " " + array[3] + "\n";
    report += "Tel.: " + array[4] + "\n";
    report += "Gender: ";
    if (array[5] == "M"){
        report += "Male\n";
    }
    else if (array[5] == "F"){
        report += "Female\n";
    }
    else{
        report += "Other\n";
    }
    report += "Class Level: ";
    if (array[6] == "FR"){
        report += "Freshman\n";
    }
    else if (array[6] == "SO"){
        report += "Sophomore\n";
    }
    else if (array[6] == "JR"){
        report += "Junior\n";
    }
    else if (array[6] == "SR"){
        report += "Senior\n";
    }
    report += "Total Credits: " + array[7] + "\n";
    report += "Cumulative GPA: " + array[8] + "\n";
    report += "Registration of Fall 2020: ";
    if (stoi(array[9]) != 0){
         report += "Yes\n";
    }
    else{
        report += "No\n";
    }
    report += "\n";
    return report;
}

//Produces a formatted report of student information for the most recent semester
string semester_report(string array[], int semester_credits, int total_credits, double cumulative_gpa){
    string report = "";
    int i=10; //iterator index
    report += "Unofficial Report Card\n";
    report += "COURSE  CREDITS  GRADE\n";
    report += "======  =======  =====\n";

    while((array[i] != "") && (i < 25)){
        report += ""+array[i] + "     ";
        if (i%3 == 0){ //grades
            report += "\n";
        }
        i++;
    }
    report +="\n";
    report += "Credits for Fall 2020: " + to_string(semester_credits) + "\n";
    report += "New Total Credits: " + to_string(total_credits) + "\n";

    //rounding to two decimal places
    float gpa = (int)(cumulative_gpa * 100 + .5); 
    gpa = (float)gpa / 100; 

    
    report += "New Cumulative GPA: " + to_string(gpa).substr(0,4) + "\n";
    report +="\n";
    return report;
}