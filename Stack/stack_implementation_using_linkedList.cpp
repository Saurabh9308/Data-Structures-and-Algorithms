#include<iostream>
using namespace std;

//Class of Linked List Node
class ListNode{
public:
    int val;
    ListNode* next;

    //Constructors
    ListNode(int val){
        this->val = val;
        next = NULL;
    }

    ListNode(int val, ListNode* next){
        this->val = val;
        this->next = next;
    }
};

//Class of Stack
class Stack{
private:
    ListNode* head;      //Head Node of the Stack
    int s;               //Size of the Stack

public:
    //Constructor Function
    Stack(){
        head = NULL;
        s = 0;
    }


    //Function of pushing element in the Stack
    void push(int val){
        ListNode* temp = new ListNode(val,head);
        head = temp;
        s++;
    }


    //Function of popping last pushed element from the Stack
    void pop(){
        if(head){
            ListNode* temp = head;
            head = head->next;
            temp->next = NULL;
            delete(temp);
            s--;
        }
        else{
            //Stack is Empty
            cout<<"Stack is underflow\n";
            return;
        }
    }


    //Function of getting top element in the Stack
    int top(){
        if(head){
            return head->val;
        }
        else{
            cout<<"Stack is empty\n";
            return -1;
        }
    }


    //Function of getting size of the Stack
    int size(){
        return s;
    }


    //Function of checking is Stack is empty or not
    bool empty(){
        return (s > 0) ? 0 : 1;
    }
};


int main(){
    Stack S;            //Created a Stack object
    S.push(1);          //Pushed element 1 in the Stack
    S.push(2);          //Pushed element 2 in the Stack
    S.push(3);          //Pushed element 3 in the Stack
    S.push(4);          //Pushed element 4 in the Stack

    S.pop();            //Popped element 4 from the Stack

    cout<<"Top element in the Stack: "<<S.top()<<endl;  //Getting topmost element
    cout<<"Size of the Stack: "<<S.size()<<endl;        //Getting size of the Stack
    cout<<"Is Stack empty? "<<S.empty()<<endl;          //Checking is Stack is empty or not
}