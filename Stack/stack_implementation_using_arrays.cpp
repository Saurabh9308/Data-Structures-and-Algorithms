#include<iostream>
using namespace std;

//Class of the Stack
class Stack{
private:
    int *arr;    //Array 
    int s;       //Size of the stack
    int top_ptr; //Top pointer of the stack

public:
    //Constructor Function taking size of stack as input
    Stack(int s){
        this->s = s;
        arr = new int[s];
        top_ptr = -1;           //Initializing top_ptr with -1
    }

    //Push Function
    void push(int num){
        if(top_ptr == s - 1){
            //If Stack is full
            cout<<"Stack Overflow\n";
            return;
        }
        else{
            top_ptr++;
            arr[top_ptr] = num;
            s++;
        }
    }

    //Pop Function
    void pop(){
        if(top_ptr == -1){
            //If stack is Empty
            cout<<"Stack underflow\n";
            return;
        }
        else{
            top_ptr--;
            s--;
        }
    }

    //Function of getting last pushed element in the stack
    int top(){
        if(top_ptr == -1){
            cout<<"Stack is Empty\n";
            return -1;
        }
        else{
            return arr[top_ptr];
        }
    }

    //Function of getting size of the stack
    int size(){
        return top_ptr + 1;
    }

    //Function of checking is stack empty or not
    bool empty(){
        if(top_ptr == -1) return 1;
        else return 0;
    }
};
int main(){
    Stack S(10);  //Creating Stack of size 10
    S.push(1);    //Pushing element 1 in the Stack
    S.push(2);    //Pushing element 2 in the Stack
    S.push(3);    //Pushing element 3 in the Stack
    S.push(4);    //Pushing element 4 in the Stack
    S.pop();      //Popping last pushed element from the Stack


    cout<<"Top element of the Stack: "<<S.top()<<endl;      //Getting the top element of the Stack
    cout<<"Size of the Stack: "<<S.size()<<endl;            //Getting size of the Stack
    cout<<"Is stack Empty? "<<S.empty()<<endl;              //Checking is Stack empty or not
}