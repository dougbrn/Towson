// Lab 10 Program 1: Structure
// Doug Branton

#include <iostream>
#include <ctime>

using namespace std;

// Data structure defining a person
struct Person {
    
    // Data structure defining a date
    struct Date {
    int year;
    int month;
    int day;
};

    string first_name;
    string last_name;
    int age;
    Date date_of_birth;

    //Calculate age from date of birth, call by reference to store in age
    void calcAge(Date date_of_birth, int &age){
        int now_year;
        int now_month;
        int now_day;
        
        time_t now = time(0);
        tm *ltm = localtime(&now);

        now_year = 1900 + ltm->tm_year;
        now_month = 1 + ltm->tm_mon;
        now_day = ltm->tm_mday;

        if ((date_of_birth.month > now_month) && (date_of_birth.day >= now_day)){
            age = now_year - date_of_birth.year + 1; //birthday has happened this year
        }
        else{
            age = now_year - date_of_birth.year; //birthday has not happened yet
        }
  



    }
};


int main(){
    Person new_person;

    //ask user for information
    cout << "First Name: ";
    cin >> new_person.first_name;

    cout << "Last Name: ";
    cin >> new_person.last_name;

    cout << "Birth year: ";
    cin >> new_person.date_of_birth.year;

    cout << "Birth month: ";
    cin >> new_person.date_of_birth.month;


    cout << "Birth day: ";
    cin >> new_person.date_of_birth.day;

    //calculate age
    new_person.calcAge(new_person.date_of_birth, new_person.age);

    //print results out to the user
    cout << endl;
    cout << "Name: " << new_person.first_name << " " << new_person.last_name << endl;
    cout << "Age: " << new_person.age << endl;
}