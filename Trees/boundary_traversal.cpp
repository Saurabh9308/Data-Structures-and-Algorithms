#include<iostream>
#include "implementation_of_tree.cpp"
#include<stack>
#include<queue>
using namespace std;


/*
Tree we are implementing looks like: 

        1 
      /   \
     2     3  
    / \   / \ 
   4   5 6   7
      / \
     8   9

*/
//1 2 4 -1 -1 2 8-1 -1 9 -1 -1 3 6 -1 -1 7 -1 -1


//Boundary Traversal : Boundary traversal of a binary tree involves visiting its boundary nodes in an anticlockwise direction, starting from the root.


//Traversing through the left boundary of the tree
void leftBoundary(TreeNode* root){
    if(!root) return;
    if(!root->left && !root->right) return;     //Excluding Leaf Nodes

    cout<<root->val<<" ";
    leftBoundary(root->left);

    if(!root->left) leftBoundary(root->right);  //This will run only when node->left == NULL
}


//Traversing througn the leaf nodes i.e bottom boundary of the tree
void bottomBoundary(TreeNode* root){
    if(!root) return;

    if(!root->left && !root->right){
        //We found the leaf node
        cout<<root->val<<" ";
        return ;
    }

    bottomBoundary(root->left);
    bottomBoundary(root->right);
}


//Traversing through the right boundary of the tree
void rightBoundary(TreeNode* root, stack<TreeNode*> &st){
    if(!root) return;
    if(!root->left && !root->right) return;    //Excluding Leaf Nodes

    st.push(root);
    rightBoundary(root->right, st);
    if(!root->right) rightBoundary(root->left, st);     //This will run only when node->right == NULL

}



void boundaryTraversal(TreeNode* root){
    if(!root) return;

    //First we will print left boundary of tree but excluding leaf nodes
    leftBoundary(root);

    //Printing Bottom Boundary of the tree
    bottomBoundary(root);

    stack<TreeNode*> st;
    //Collecting all the nodes which are at the right boundary of the tree
    rightBoundary(root->right, st);     //Passing root->right as we don't want to print root node of the tree again


    //Printing right boundary reversely
    while(!st.empty()){
        cout<<st.top()->val<<" ";
        st.pop();
    }
}
//Boundary traversal of our tree : 1 2 4 8 9 6 7 3


