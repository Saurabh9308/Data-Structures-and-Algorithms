#include<iostream>
#include "implementation_of_tree.cpp"
#include<queue>
using namespace std;

/*
Tree we are implementing looks like: 

        2
       / \
      4  10
     / \   \
    6   5   1

*/


//Level Order traversal on the tree: A method to traverse a Tree such that all nodes present in the same level are traversed completely before traversing the next level.

void levelOrderTraversal(TreeNode* root){
    if(!root) return;

    queue<TreeNode*> q;
    q.push(root);
    q.push(NULL);       //Pushing NULL so that we can differentiate the levels of the tree
    while(!q.empty()){
        TreeNode* temp = q.front();
        q.pop();

        if(!temp){
            cout<<endl;
            if(!q.empty()) q.push(NULL);
        }
        else{
            cout<<temp->val<<" ";

            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
        
    }
}
//Level Order traversal of our tree: 
//Level 1: 2
//Level 2: 4 10
//Level 3: 6 5 1

