#include<iostream>
using namespace std;

//Class of the Doubly Linked List Node
class ListNode{
public:
    //Members
    int val;
    ListNode* prev;
    ListNode* next;

    //Constructors
    ListNode(int val){
        this->val = val;
        this->prev = NULL;
        this->next = NULL;
    }
};

//Doubly Linked List Class Implementation
class Doubly_Linked_List{
private:
    int size;       //Size of the Doubly Linked List
    ListNode* head; // Head Node of the Doubly Linked List

public:
    //Consstructors
    Doubly_Linked_List(){
        size = 0;           //Initializing Size with
        head = NULL;        //Initializing head with NULL
    }


    //Function to insert an element at head
    void insert_at_head(int val){
        ListNode* temp = new ListNode(val);
        temp->next = head;

        if(head) head->prev = temp;

        head = temp;
        size++;
    }

    //Function to insert an element at tail
    void insert_at_tail(int val){
        ListNode* temp = new ListNode(val);

        if(!head){
            head = temp;
        }
        else{
            ListNode* ptr = head;
            while(ptr->next) ptr = ptr->next;   //Traversing Ptr pointer upto the tail Node

            ptr->next = temp;
            temp->prev = ptr;
        }

        size++;
    }

    //Function to insert an element at kth index 
    void insert_at_index(int idx, int val){
        if(idx > size + 1 || idx <= 0){
            cout<<"Invalid Index\n";
            return;
        }
        if(idx == 1) insert_at_head(val);
        else if(idx == size + 1) insert_at_tail(val);
        else{
            ListNode* ptr = head;
            int i = 1;
            while(i < idx - 1){
                ptr = ptr->next;
                i++;
            }
            ListNode* temp = new ListNode(val);
            temp->next = ptr->next;
            temp->prev = ptr;
            ptr->next->prev = temp;
            ptr->next = temp;
        }
        size++;
    }

    //Function for displaying elements in the Doubly Linked List
    void display(){
        ListNode* ptr = head;
        while(ptr){
            cout<<ptr->val<<" ";
            ptr = ptr->next;
        }
        cout<<endl;
    }

    //Function for reversing the Doubly Linked List
    void reverse(){
        if(!head || !head->next) return;
        ListNode* curr = head, *previous = NULL;
        while(head->next){
            head = head->next;
            curr->next = previous;
            curr->prev = head;
            previous = curr;
            curr = head;
        }

        head->next = previous;
        head->prev = NULL;
    }

    //Function to check an element present in the Doubly Linked List or Not
    bool isPresent(int val){
        ListNode* ptr = head;
        if(!head) return false;

        while(ptr){
            if(ptr->val == val) return true;
            ptr = ptr->next;
        }
        return false;
    }

    //Function to get length of the Doubly Linked List
    int length(){
        return size;
    }

    //Function of deleting element of Doubly Linked List present at head
    void delete_at_head(){
        if(!head) return; // Head == NULL

        ListNode* ptr = head;
        head = head->next;
        head->prev = NULL;
        delete(ptr);
        size--;
    }

    //Function of deleting element of Doubly Linked List present at tail
    void delete_at_tail(){
        if(!head) return;

        if(!head->next){
            ListNode* ptr = head;
            head = NULL;
            delete(ptr);
            size--;
            return;
        }

        ListNode* ptr = head;

        while(ptr->next->next){
            ptr = ptr->next;
        }

        ListNode* temp = ptr->next;
        ptr->next = NULL;
        temp->prev = NULL;
        delete(temp);
        size--;
    }

    //Function to delete element of Doubly Linked List present at index k
    void delete_at_index(int idx){
        if(idx <= 0 || idx > size){
            cout<<"Invalid Index\n";
            return;
        }
        if(idx == 1) delete_at_head();
        else if(idx == size) delete_at_tail();
        else{
            int i = 1;
            ListNode* temp = head;

            while(i < idx - 1){
                i++;
                temp = temp->next;
            }

            ListNode* ptr = temp->next;
            temp->next = ptr->next;
            ptr->next->prev = temp;
            delete(ptr);
            size--;
        }
    }

    //Function to delete an element by value in the Doubly Linked List
    void delete_by_value(int val){
        if(!head) return;
        if(isPresent(val)){
            ListNode* curr = head, *previous = NULL;

            if(curr->val == val) delete_at_head();
            else{
                while(curr){
                    if(curr->val == val) break;
                    previous = curr;
                    curr = curr->next;
                }
                previous->next = curr->next;
                curr->next->prev = previous;
                delete(curr);
                size--;
            }
        }

        else{
            cout<<"Element is not present in the List\n";
        }
    }
};



int main(){
    Doubly_Linked_List list;        //Initializing Doubly Linked List
    list.insert_at_head(1);         //list: 1-> NULL
    list.insert_at_head(2);         //list: 2-> 1-> NULL
    list.insert_at_head(3);         //list: 3-> 2-> 1-> NULL
    list.insert_at_head(4);         //list: 4-> 3-> 2-> 1-> NULL

    list.display();
    list.reverse();                 //list: 1-> 2-> 3-> 4-> NULL
    list.display();

    list.insert_at_tail(5);         //list: 1-> 2-> 3-> 4-> 5-> NULL
    list.insert_at_tail(6);         //list: 1-> 2-> 3-> 4-> 5-> 6-> NULL
    list.insert_at_tail(7);         //list: 1-> 2-> 3-> 4-> 5-> 6-> 7-> NULL

    list.display();

    list.insert_at_index(4,8);      //list: 1-> 2-> 3-> 8-> 4-> 5-> 6-> 7-> NULL
    list.display();

    list.delete_at_head();          //list: 2-> 3-> 8-> 4-> 5-> 6-> 7-> NULL
    list.delete_at_tail();          //list: 1-> 2-> 3-> 8-> 4-> 5-> 6-> NULL
    list.delete_at_index(5);        //list: 1-> 2-> 3-> 8-> 4-> 6-> NULL

    list.display();

    cout<<list.length()<<endl;      //Length = 5
}