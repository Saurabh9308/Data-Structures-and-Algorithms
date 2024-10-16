#include<iostream>
using namespace std;

//Class of the Circular Linked List Node
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


//Circular Linked List Class
class Circular_Linked_List{
private:
    ListNode* head;     //Head Node of the Circular Linked List
    int size;           //Size of the Circular Linked List

public:
    //Constructor
    Circular_Linked_List(){
        head = NULL;
        size = 0;
    }

    //Function to insert an element at the head of the Circular Linked List
    void insert_at_head(int val){
        ListNode* temp = new ListNode(val);
        
        if(!head){  //head == NULL
            head = temp;
            head->next = head;
        }
        else{
            temp->next = head;
            ListNode* ptr = head;
            while(ptr->next != head) ptr = ptr->next;
            ptr->next = temp;
            head = temp;
        }

        size++;
    }

    //Function to insert an element at the tail of the Circular Linked List
    void insert_at_tail(int val){
        ListNode* ptr = head;
        ListNode* temp = new ListNode(val);
        if(!head){  //(head == NULL)
            head = temp;
            head->next = head;
        }
        else{
            while(ptr->next != head) ptr = ptr->next;
            ptr->next = temp;
            temp->next = head;
        }
        size++;
    }

    //Function to insert an element at index k assuming 1-based indexing
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
            ptr->next = temp;
        }
        size++;
    }

    //Function for displaying elements of the Circular Linked List
    void display(){
        ListNode* ptr = head;
        while(ptr){
            cout<<ptr->val<<" ";
            ptr = ptr->next;
            if(ptr == head) break;
        }
        cout<<endl;
    }

    //Function for reversing the Circular Linked List
    void reverse(){
        if(!head || head->next == head) return;
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* ptr = NULL;
        do{
            ptr = curr->next;
            curr->next = prev;
            prev = curr;
            curr = ptr;
        }while(curr != head);
        head->next = prev;
        head = prev;
    }

    //Function to check an element present in the Circular Linked List or Not
    bool isPresent(int val){
        ListNode* ptr = head;
        if(!head) return false;

        while(ptr){
            if(ptr->val == val) return true;
            ptr = ptr->next;
            if(ptr == head) break;
        }
        return false;
    }

    int length(){
        return size;
    }

    //Function of deleting element of Circular Linked List present at head
    void delete_at_head(){
        if(!head) return; // Head == NULL

        ListNode* ptr = head;
        while(ptr->next != head) ptr = ptr->next;
        ListNode* temp = head;
        head = head->next;
        ptr->next = head;
        delete(temp);
        size--;
    }

    //Function of deleting element of Circular Linked List present at tail
    void delete_at_tail(){
        if(!head) return;

        if(head->next == head){
            ListNode* ptr = head;
            head = NULL;
            delete(ptr);
            size--;
            return;
        }

        ListNode* ptr = head;

        while(ptr->next->next != head){
            ptr = ptr->next;
        }

        ListNode* temp = ptr->next;
        ptr->next = head;
        delete(temp);
        size--;
    }

    //Function to delete element of Circular Linked List present at index k
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
            delete(ptr);
            size--;
        }
    }

    //Function to delete an element by value in the Circular Linked List
    void delete_by_value(int val){
        if(!head) return;
        if(isPresent(val)){
            ListNode* curr = head, *prev = NULL;

            if(curr->val == val) delete_at_head();
            else{
                while(curr){
                    if(curr->val == val) break;
                    prev = curr;
                    curr = curr->next;
                }
                prev->next = curr->next;
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
    Circular_Linked_List list;
    list.insert_at_head(1);     //list: 1 -> 1
    list.insert_at_head(2);     //list: 2 -> 1 -> 2
    list.insert_at_head(3);     //list: 3 -> 2 -> 1 -> 3
    list.insert_at_head(4);     //list: 4 -> 3 -> 2 -> 1 -> 4

    list.display();

    list.reverse();             //list: 1 -> 2 -> 3 -> 4 -> 1
    list.display();

    list.insert_at_tail(5);     //list: 1 -> 2 -> 3 -> 4 -> 5 -> 1
    list.insert_at_tail(6);     //list: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 1
    list.display();

    list.insert_at_index(3,7);     //list: 1 -> 2 -> 7 -> 3 -> 4 -> 5 -> 6 -> 1
    list.display();

    list.delete_at_head();      //list: 2 -> 7 -> 3 -> 4 -> 5 -> 6 -> 2
    list.display();

    list.delete_at_tail();      //list: 2 -> 7 -> 3 -> 4 -> 5 -> 2
    list.display();
    list.delete_at_index(3);    //list: 2 -> 7 -> 4 -> 5 -> 2
    list.display();

    list.delete_by_value(8);    //list: 2 -> 7 -> 4 -> 5 -> 2

    cout<<"Size of the Circular Linked List: "<<list.length();
}