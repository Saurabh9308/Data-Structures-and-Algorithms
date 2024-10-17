#include<iostream>
using namespace std;

//Class of the Node of the Linked List
class ListNode{
public: 
    int val;
    ListNode* next;

    //Constructor
    ListNode(int val){
        this->val = val;
        this->next = NULL;
    }
};

//Implementation of the Queue
class Queue{
private:
    ListNode* head;
    ListNode* tail;
    int size;

public:
    //Constructor
    Queue(){
        head = NULL;
        tail = NULL;
        size = 0;
    }

    //Function to Push the elements in the Queue
    void push(int val){
        ListNode* temp = new ListNode(val);
        if(!tail){
            head = temp;
            tail = temp;
        }
        else{
            tail->next = temp;
            tail = temp;
        }
        size++;
    }

    //Function to pop the front element of the Queue
    void pop(){
        if(!head) return;
        ListNode* temp = head;
        if(head == tail){
            head = NULL;
            tail = NULL;
        }
        else{
            head = head->next;
        }
        delete(temp);
        size--;
    }

    //Function to get value of element present at front of the Queue
    int front(){
        return (!head) ? -1 : head->val;
    }

    //Function to get size of the Queue
    int length(){
        return size;
    }

    //Function to check is Queue is Empty or Not
    bool isEmpty(){
        return (size == 0) ? true : false;
    }
};

int main(){
    Queue q;            //Implementing Queue Object
    q.push(1);          //Queue: 1
    q.push(2);          //Queue: 1 -> 2
    q.push(3);          //Queue: 1 -> 2 -> 3
    q.push(4);          //Queue: 1 -> 2 -> 3 -> 4

    cout<<q.front()<<endl;      //Getting the element preset at the front of the Queue i.e. 1

    q.pop();                    //Popping the element present at the Front i.e 1

    cout<<q.front();            //Getting the element preset at the front of the Queue i.e. 2

    cout<<endl<<"Size of the Queue: "<<q.length();     //Getting the length of the Queue
    //Checking is Queue Empty or NOT
    if(q.isEmpty()){
        cout<<endl<<"Queue is Empty\n";
    }
    else cout<<endl<<"Queue is not Empty\n";
}