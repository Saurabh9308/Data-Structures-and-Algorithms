//Implementing Function which will search the given value in Binary Search Tree and return true if present else return -1

#include<iostream>
#include "implementing_BST.cpp"
using namespace std;



//Function to search given value in Binary Search Tree
bool search(TreeNode* root, int data){
    //Base Condition: When we reach to the NULL 
    if(!root) return false;

    //Case 1: We found our value in Binary Search tree
    if(root->data == data) return true;

    //Case 2: data < root->data then go left
    else if(data < root->data){
        return search(root->left, data);
    }

    //Case 3: data > root->data then go right
    else return search(root->right, data);
}



int main(){
    vector<int> arr = {1,2,3,4,5,6,7,8,9,10};

    //Building Binary Search Tree
    TreeNode* root = buildBST(root, arr, 0, arr.size() - 1);

    /*
    Implemented Binary Search Tree:


                                    5
                                   / \
                                  2   8
                                 / \ / \
                                1  3 6  9
                                    \    \
                                     4    10

    */

    //Searching the val 4 in Binary Search Tree
    if(search(root, 4)){//As 4 is present then if statement will run
        cout<<"Value 4 is present in the BST."<<endl;
    }
    else{
        cout<<"Value 4 is not present in the BST"<<endl;
    }

    //Searching the val 12 in Binary Search Tree
    if(search(root, 12)){
        cout<<"Value 12 is present in the BST."<<endl;
    }
    else{//As 12 is not present then else statement will run
        cout<<"Value 12 is not present in the BST"<<endl;
    }

    //Output:
    //Value 4 is present in the BST.
    //Value 12 is not present in the BST

}