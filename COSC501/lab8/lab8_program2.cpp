//Lab 8 Program 2: String and Vector
//Doug Branton


#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main() {
ifstream fin("Lab8_2data.txt");
string text;
vector<string> word;

// Exit on failed file load    
if(fin.fail()){
cout << "Unable to read the file.";
return -1;
}

//Function that reads in a line from an InputStream (fin) to a String (text)
getline(fin, text);

// *** IMPLEMENT YOUR CODE HERE ***
cout << "Text: " << text << endl;

int search_elem = 0, match_elem_start=0, match_elem_end;

//only stop searching when find returns -1
while(match_elem_start != -1){
    match_elem_start = text.find("(",search_elem); //find a left parenthese

    if (match_elem_start != -1){
        match_elem_end = text.find(")", match_elem_start); //find a right parenthese
        if (match_elem_end != -1){
            //store the substring between the parentheses into the vector word
            word.push_back(text.substr(match_elem_start+1, match_elem_end-match_elem_start-1));
        }
    }
    search_elem = match_elem_end; //update the search elem to dictate where to continue the next search
}
cout << endl;
cout << "Extracted Word: ";

for (int i=0; i< word.size(); i++){
    cout << word.at(i) << " ";
}





fin.close();
return 0;

}