// COSC 501 Lab 9 Program 1: Pointer Palindrome
// Doug Branton

#include <iostream>
#include <cstring>

using namespace std;

bool isPalindrome(char* cstr);

int main(){
    char s1[50] = "neveroddoreven";
    char s2[50] = "notapalindrome";
    cout << isPalindrome(s1) << endl; // true 
    cout << isPalindrome(s2) << endl; // false 
    return 0;
}

bool isPalindrome(char* cstr){
    char* front = cstr;
    char* back = cstr + strlen(cstr)-1;
    int i=0;

    while (front < back){
        //cout << front[0] << "  " << back[i] << endl;
        //Check forwards and backwards index by index, return false if any indices have different values
        if (front[0] != back[i]){
            return false;
        }

        //increment by 1 index in the forwards and backwards directions
        front++;
        i--;
        }

    return true;
}