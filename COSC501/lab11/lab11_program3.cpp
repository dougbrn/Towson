// Lab 11 Program 3: Linked List
// Doug Branton

#include <iostream>
#include <string>

using namespace std;

struct Node {
string name;
Node *link;
};

typedef Node* NodePtr;

int main() {


NodePtr listPtr, tempPtr;
listPtr = new Node;

listPtr->name = "Emily";

tempPtr = new Node;
tempPtr->name = "James";

listPtr->link = tempPtr;
tempPtr->link = new Node;

tempPtr = tempPtr->link;
tempPtr->name = "Joules";
tempPtr->link = NULL;

//Question a: Output in order all names in the list
NodePtr iterPtr_a = listPtr;
cout << "Question a:" << endl;
while(iterPtr_a != NULL){
    cout << iterPtr_a->name << endl;
    iterPtr_a = iterPtr_a->link;
}
cout << endl;

//Question b: Insert the name "Joshua" in the list after "James" then output the modified list
NodePtr searchPtr_b = listPtr, iterPtr_b = listPtr;
string target = "James";

//search the linked list for "James"
while(searchPtr_b->name != target && searchPtr_b->link != NULL){
    searchPtr_b = searchPtr_b->link;
}
//Inserting "Joshua" requires creating a node that is linked to by the "James" Node, and links to the "Joules" node
NodePtr joshPtr = new Node;
joshPtr->name = "Joshua";
joshPtr->link = searchPtr_b->link; //searchPtr_b->link is the link to the Joules node
searchPtr_b->link = joshPtr;//searchPtr_b is the James Node

//read out the list
cout << "Question b:" << endl;
while(iterPtr_b != NULL){
    cout << iterPtr_b->name << endl;
    iterPtr_b = iterPtr_b->link;
}
cout << endl;

//Question c: Delete the node with "Joules" then outputs the modified list
NodePtr searchPtr_c = listPtr, iterPtr_c = listPtr,beforePtr;;
target = "Joules";

//search the linked list for "Joules"
while(searchPtr_c->name != target && searchPtr_c->link != NULL){
    beforePtr = searchPtr_c;
    searchPtr_c = searchPtr_c->link;
}

//Deleting the Joules node means taking the prior node and linking it to the Joules node link
//The joules node link is NULL in this case
beforePtr->link = searchPtr_c->link;
delete searchPtr_c;

//read out the list
cout << "Question c:" << endl;
while(iterPtr_c != NULL){
    cout << iterPtr_c->name << endl;
    iterPtr_c = iterPtr_c->link;
}
cout << endl;

//Question d: Delete all remaining Nodes
NodePtr iterPtr_d = listPtr,herePtr;
while(iterPtr_d != NULL){
    herePtr = iterPtr_d; //create a copy of the current ptr
    iterPtr_d = iterPtr_d->link; //set the ptr to the next linked noded
    delete herePtr; //delete the current ptr
}

cout << "Question d:" << endl;
//This should not print any nodes
while(iterPtr_d != NULL){
    cout << iterPtr_d->name << endl;
    iterPtr_d = iterPtr_d->link;
}
cout << "All nodes are deleted." << endl;





return 0;

}