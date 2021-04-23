//Lab 11 Program 2: Inheritance
//Doug Branton

#include <iostream>

using namespace std;

class Employee{
    public:

    Employee(string Name, string SSN);
    Employee();

    string get_name();
    string get_ssn();

    void print_info();

    void change_name(string new_name);
    void change_ssn(string new_ssn);

    private:
        string name;
        string ssn;
};

class HourlyEmployee : public Employee{
    public:
        HourlyEmployee(string Name, string SSN);
    private:
};

class SalariedEmployee : public Employee{
    public:
        SalariedEmployee(string Name, string SSN);
        //Do you not need a second constructor to handle the no input case given in main?
        //Included below as my compiler wasn't happy otherwise
        SalariedEmployee();
    private:
};

int main() {
Employee emp("John Doe", "123456789");
emp.print_info();

HourlyEmployee hemp("William Ford","222334444");

cout << "Name: " << hemp.get_name() << endl;
cout << "SSN: " << hemp.get_ssn() << endl;


SalariedEmployee semp;

semp.change_name("Helen Drew");
semp.change_ssn("321654879");
semp.print_info();

return 0;
}


Employee::Employee(string Name, string SSN){
    name = Name;
    ssn = SSN;
}

Employee::Employee(){
    name="";
    ssn="";
}

string Employee::get_name(){
    return name;
}

string Employee::get_ssn(){
    return ssn;
}

void Employee::print_info(){
    cout << "Name: " << get_name() << endl;
    cout << "SSN: " << get_ssn() << endl;
}

void Employee::change_name(string new_name){
    name = new_name;
}

void Employee::change_ssn(string new_ssn){
    ssn = new_ssn;
}

HourlyEmployee::HourlyEmployee(string Name, string SSN):
    Employee(Name,SSN){

    }


SalariedEmployee::SalariedEmployee(string Name, string SSN):
    Employee(Name,SSN){

}

SalariedEmployee::SalariedEmployee():
    Employee(){
        
}



