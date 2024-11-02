//Deletion in a Binary Search Tree (BST) involves removing a node while maintaining the properties of the BST.
#include<iostream>
#include "implementing_BST.cpp"
using namespace std;


//Function for Finding inorder predecessor of the Given Node
TreeNode* inorderPredecessor(TreeNode* root){
    //Going left first
    TreeNode* temp = root->left;

    //Going right until we found NULL
    while(temp->right) temp = temp->right;

    return temp;
}

//Function to delete the node from the Given Binary Search Tree
TreeNode* deleteNode(TreeNode* root, int val){

    //In case we reach to the NULL means Node with value not present in the BST
    if(!root) return NULL;

    //If we found the Node with given value
    if(root->data == val){
        //Case 1: Node with given data has no Child i.e. leaf Node
        if(!root->left && !root->right) return NULL;

        //Case 2: Node with given value has one child either Left or Right
        else if(!root->left || !root->right){
            //Node with given Value has left child
            if(root->left) return root->left;

            //Node with given Value has right child
            else return root->right;
        }

        //Case 3: Node with given Value has both Child's
        else{
            //Finding Inorder Predecessor of the Node
            TreeNode* predecessor = inorderPredecessor(root);

            //Changing Node's Data with it's inorder predecessor
            root->data = predecessor->data;

            root->left = deleteNode(root->left, predecessor->data);
        }
    }
    
    // val < root->data so we will get the Node with given Value in left Subtree
    else if(val < root->data){
        root->left = deleteNode(root->left, val);
    }
    // val > root->data so we will get the Node with given Value in right Subtree
    else{
        root->right = deleteNode(root->right,val);
    }

    //Finally returning the tree node after deleting the node with given value
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

    root = deleteNode(root, 2);
    /*
    After deleting Node with value 2 in earlier Binary Search Tree


                                     5
                                    / \
                                   1   8
                                    \ / \
                                    3 6  9
                                     \   \
                                      4   10


    */

}