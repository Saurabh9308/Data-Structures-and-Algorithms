//Insertion in a Binary Search Tree (BST) involves placing a new value in the tree while maintaining the properties of the BST.
#include<iostream>
#include "implementing_BST.cpp"
using namespace std;

//Function to insert the new Node with value Data in the Binary Search Tree
TreeNode* insertNode(TreeNode* root, int data){
    if(root == NULL){
        //We reached to the NULL and place where we can place our new Node

        return new TreeNode(data);
    }

    //If data < root->data then we will place that New Node in our left SubTree
    if(data < root->data){
        root->left = insertNode(root->left,data);
    }
    //If data > root->data then we will place that New Node in our right SubTree
    else{
        root->right = insertNode(root->right,data);
    }

    //After placing the new Node we will return the root of the BST
    return root;
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

    root = insertNode(root, 11);

    /*
    After Inserting Node with value 11 in earlier Binary Search Tree


                                     5
                                    / \
                                   2   8
                                  / \ / \
                                 1  3 6  9
                                     \   \
                                      4   10
                                            \
                                             11


    */

}