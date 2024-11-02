//Morris traversal is an algorithm used for in-order traversal of a binary tree without using any additional space for a stack or recursion. This method modifies the tree structure temporarily to achieve the traversal, ensuring that the tree is restored after the traversal is complete.

#include<iostream>
#include "implementing_BST.cpp"
using namespace std;

void morrisTraversal(TreeNode* root){
    TreeNode* curr = root;

    //Loop will run until current Node is not NULL
    while(curr){
        //Current Node's left child exist
        if(curr->left){
            //Finding inorder predecessor
            TreeNode* pred = curr->left;

            while(pred->right && pred->right != curr) pred = pred->right;

            if(!pred->right){//Linking predecessor's right child to the current Node
                pred->right = curr;
                curr = curr->left;
            }
            else{//Pred->right == curr : Unlinking predecessor's right child
                pred->right = NULL;
                cout<<curr->data<<" ";
                curr = curr->right;
            }
        }
        else{//curr->left == NULL
            cout<<curr->data<<" ";
            curr = curr->right;
        }
    }

    return;
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

    morrisTraversal(root);
    //Output of the Morris Traversal: 1 2 3 4 5 6 7 8 9 10
}
