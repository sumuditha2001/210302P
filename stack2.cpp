#include <iostream>
#include <chrono>
using namespace std::chrono;
using namespace std;

class Node {
public:
    int data;        //declaring the structure of the linked list
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;        //take the data and set the next pointer to null
    }
};

class Stack {      //implementing the stack by the linked list
public:
    Node* top;     //declaring the top of the stack

    Stack() {
        top = NULL;
    }

    bool isEmpty() {        //checkin whether the stack is empty or not
        return top == NULL;   
    }

    void push(int value) {           //pushing to the stack
        Node* newNode = new Node(value);
        if (isEmpty()) {
            top = newNode;
        }
        else {
            newNode->next = top;
            top = newNode;
        }
    }

    int pop() {         //poping from the stack
        if (isEmpty()) {
            cout << "Stack Overflow." << endl;
            return 0;
        }
        else {
            int poppedValue = top->data;
            top = top->next;
            return poppedValue;
        }
    }

    int stackTop() {         //displaying the top element of the stack
        if (isEmpty()) {
            cout << "Stack is empty.No element to display." << endl;
            return 0;
        }
        else {
            return top->data;
        }
    }

    void Display() {         //displaying the elements in the stack
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
        }
        else {
            Node* temp = top;
            cout << "Current stack is : [ ";
            while (temp != NULL) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << "]"<<endl;
        }
    }
};

int main() {
    double total_duration1 = 0;
    auto start1 = high_resolution_clock::now();
    Stack Arr;
    Arr.push(8);
    Arr.push(10);
    Arr.push(5);
    Arr.push(11);
    Arr.push(15);
    Arr.push(23);
    Arr.push(6);
    Arr.push(18);
    Arr.push(20);
    Arr.push(17);
    Arr.Display();
    Arr.pop();
    Arr.pop();
    Arr.pop();
    Arr.pop();
    Arr.pop();
    Arr.Display();
    Arr.push(4);
    Arr.push(30);
    Arr.push(3);
    Arr.push(1);  
    Arr.Display(); 
    auto stop1 = high_resolution_clock::now();
    auto duration1 = duration_cast<microseconds>(stop1 - start1);
    total_duration1 += duration1.count();                     //calculating the time for the  opertations
    cout <<"time for linked list stack: "<<total_duration1<< endl;

    return 0;
}
