// Lab 12 Program 1: Stack and Queue
// Doug Branton

#include <iostream>
#include <cstddef>

using namespace std;

struct Frame
{
    int data;
    Frame *link;
};

typedef Frame* FramePtr;

//Last in, First Out
class Stack
{
    public:
        Stack();
        //Initializes the object to an empty stack

        void push(int data);
        //Adds the integer to the stack

        int pop();
        //Precondition: The stack is not empty.
        //Postcondition: Returns the top symbol on the stack and removes that top symbol from the stack

        bool empty() const;
        //Returns true if the stack is empty, false otherwise

    private:
        FramePtr top;
};

//First in, First Out
class Queue
{
    public:
        Queue();
        //Initializes the object to an empty Queue

        void add(int data);
        //Adds the integer to the back of the Queue

        int remove();
        //removes the item on top of the Queue

        bool empty() const;
        //Returns true if the queue is empty, false otherwise

    private:
        FramePtr front; //Points to the head of a linked list
                        //Items removed at the head
        FramePtr back;  //Points to the node at the other end of the link list
                        //Items added at this end


};

int main(){
    Stack s;
    Queue q;
    int data;
    cout << "Enter ten integers." << endl;

    for (int i=0; i < 10; i++){
        cin >> data;
        s.push(data);
        q.add(data);
    }
    cout << endl;

    cout << "Stack Output: ";

    for (int i=0; i < 10; i++){
        cout << s.pop() << " ";
    }
    cout << endl;

    cout << "Queue Output: ";

    for (int i=0; i < 10; i++){
        cout << q.remove() << " ";
    }
    cout << endl;

}

//-------------------------- Stack Functions --------------------------
Stack::Stack() : top(NULL)
{
    //Body intentionally left empty
}

bool Stack::empty() const{
    return (top == NULL);
}

void Stack::push(int data){
    FramePtr newPtr = new Frame;
    newPtr->data = data;

    newPtr->link = top;
    top = newPtr;
}

int Stack::pop(){
    if (empty()){
        cout << "Error: popping an empty stack." << endl;
        exit(1);
    }

    char result = top->data;

    FramePtr temp_ptr;
    temp_ptr = top;
    top = top->link;

    delete temp_ptr;

    return result;
}

//-------------------------- Queue Functions --------------------------
Queue::Queue() : front(NULL), back(NULL){
    //Intentionally Empty
}

bool Queue::empty() const{
    return (back == NULL);
}

void Queue::add(int data){
    if (empty()){
        front  = new Frame;
        front->data = data;
        front->link = NULL;
        back = front;
    }

    else{
        FramePtr temp_ptr;
        temp_ptr = new Frame;
        temp_ptr->data = data;
        temp_ptr->link = NULL;
        back->link = temp_ptr;
        back = temp_ptr;
    }
}

int Queue::remove(){
    if (empty()){
        cout << "Error: Removing an item from an empty Queue." << endl;
        exit(1);
    }

    int result = front->data;

    FramePtr discard;
    discard = front;
    front= front->link;

    if (front == NULL){
        back = NULL;
    }

    delete discard;

    return result;
}