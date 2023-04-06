#include<iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

class ArrayStack{
    int top;           //declaring the top and size of the stack
    int size;
    int* stack;

    public : ArrayStack(int value){
        size=value;
        stack = new int[size];
        top=-1;                    //initializing the top as -1 at the start of the stack
    }

    public :void push(int value){
        if (top+1>=size){                 
            cout<<"stack is full"<<endl;
        }else{
            top=top+1;                    //increment the top
            stack[top]=value;             //add the new value to the updated top
        }
    }
    public :int pop(){
        if (top==-1){
            cout<<"stack is empty"<<endl;
            return 0;
        }else{
            int pop_element=stack[top];    //poping the element at the top and returning the poped value
            top=top-1;
            return pop_element;
        }
    }
    public :bool IsEmpty(){     //checking whether the stack is empty or not
        if(top==-1){
            return true;
        }else{
            return false;
        }
    }
    public :bool IsFull(){           //checking whether the stack is full or not
        if(top==size-1){
            return true;
        }else{
            return false;
        }
    }
    public :int StackTop(){          //finding the elemnt at the top of the stack
        if(top==-1){
            cout<<"stack is empty";
            return 0;
        }else{
            return stack[top];
        }
    }
    public :void Display(){            //displaying the elemnts in the stack
        if(top==-1){
            cout<<"stack is empty"<<endl;
    }else{
        cout<<"Current stack is : [";
        for(int i=0;i<=top;i++){
            cout<<stack[i]<<" ";
        }
        cout<<']'<<endl;
    }
    }
};
int main(){
    double total_duration1 = 0;                
    auto start1 = high_resolution_clock::now();  
    ArrayStack Arr(10);
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
    total_duration1 += duration1.count();                            //calculating the time for the operations
    cout <<"time for array stack: "<<total_duration1<< endl;
    return 0;
}    



