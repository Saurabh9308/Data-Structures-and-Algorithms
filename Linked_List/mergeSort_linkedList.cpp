#include<iostream>
using namespace std;

//Linked List Node Class
class ListNode{
public:
    //Members of the Node Class
    int val;
    ListNode* next;

    //Constructors 
    ListNode(int val){
        this->val = val;
        this->next = NULL;
    }

    ListNode(int val, ListNode* next){
        this->val = val;
        this->next = next;
    }
};

//Function for merging two sorted Lists into a single sorted List
ListNode* merge(ListNode* list1, ListNode* list2){
    if(!list1) return list2;
    if(!list2) return list1;

    ListNode* head = new ListNode(0);    
    ListNode* ptr = head;

    while(list1 && list2){
        if(list1->val <= list2->val){
            ptr->next = list1;
            ptr = list1;
            list1 = list1->next;
        }
        else{
            ptr->next = list2;
            ptr = list2;
            list2 = list2->next;
        }
    }

    if(!list1) ptr->next = list2;
    else ptr->next = list1;

    return head->next;
}

//Merge Sort algorithm to sort the Linked List
ListNode* mergeSort(ListNode* head){
    if(!head || !head->next) return head; //Base Condition
    ListNode* slow = head, *fast = head, *prev = NULL;

    while(fast && fast->next){
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    prev->next = NULL;      //Here, two independent lists are created
    head = mergeSort(head); //Sorting first list
    slow = mergeSort(slow); //Sorting second list

    head = merge(head,slow);    //Merging two sorted Lists

    return head;
}
//Function to display the Linked List Elements
void display(ListNode* head){
    while(head){
        cout<<head->val<<" ";
        head = head->next;
    }
    cout<<endl;
}


int main(){
    //Head of the Linked List
    ListNode* head = new ListNode(9); 
    ListNode* ptr = head;

    //Initializing Array witht random elements
    int arr[] = {4,8,6,2,3,1,5};
    int n = sizeof(arr)/sizeof(arr[0]);

    //Converting Array into the Linked List
    for(int i = 0; i < n; i++){
        ListNode* temp = new ListNode(arr[i]);
        ptr->next = temp;
        ptr = temp;
    }

    display(head);          //List: 9-> 4-> 8-> 6-> 2-> 3-> 1-> 5-> NULL

    head = mergeSort(head); //Sorting the Linked List

    display(head);          //List: 1-> 2-> 3-> 4-> 5-> 6-> 8-> 9-> NULL
}