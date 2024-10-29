#include<iostream>
#include "implementation_of_tree.cpp"
#include<stack>
#include<queue>
#include<unordered_map>
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

//left view of a binary tree, which consists of the nodes that are visible when the tree is viewed from the left side.
void leftSideView(TreeNode* root){
    if(!root) return ;

    queue<TreeNode*> q;
    unordered_map<int,int> m;
    int level = 0;

    q.push(root);
    q.push(NULL);       //Pushing NULL for differentiating levels of the tree

    while(!q.empty()){
        TreeNode* temp = q.front();
        q.pop();

        if(!temp){
            level++;
            if(!q.empty()) q.push(NULL);
        }
        else{

            if(m.find(level) == m.end()){
                //Level key is not present in the map
                m[level] = temp->val;
            }

            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
    }

    //Printing the nodes that are visible when the tree is viewed from the left side.
    for(int i = 0; i < level; i++) cout<<m[i]<<" ";
}
//Left View of the our binary tree : 1 2 4 8


//The right side view of a binary tree consists of the nodes that are visible when the tree is viewed from the right side.
void rightSideView(TreeNode* root){
    if(!root) return ;

    queue<TreeNode*> q;
    unordered_map<int,int> m;
    int level = 0;

    q.push(root);
    q.push(NULL);       //Pushing NULL for differentiating levels of the tree

    while(!q.empty()){
        TreeNode* temp = q.front();
        q.pop();

        if(!temp){
            level++;
            if(!q.empty()) q.push(NULL);
        }
        else{

            m[level] = temp->val;

            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
    }

    //Printing the nodes that are visible when the tree is viewed from the right side.
    for(int i = 0; i < level; i++) cout<<m[i]<<" ";
}
//Right View of the our binary tree : 1 3 7 9


//The top view of a binary tree is a visual representation of the nodes that are visible when the tree is viewed from above.
void topView(TreeNode* root){

    if(!root) return ;
        
    int leftMostNode = 0;
    int rightMostNode = 0;
    int level = 0;
        
    queue<pair<TreeNode*,int>>q;
    q.push({root,level});
    unordered_map<int,int> m;
        
    while(!q.empty()){
        TreeNode* temp = q.front().first;
        int lvl = q.front().second;
            
        q.pop();
            
        leftMostNode = min(leftMostNode, lvl);
        rightMostNode = max(rightMostNode, lvl);
            
        if(m.find(lvl) == m.end()){
            m[lvl] = temp->val;
        }
            
        if(temp->left) q.push({temp->left, lvl - 1});
        if(temp->right) q.push({temp->right, lvl + 1});
    }
    //Printing the nodes that are visible when the tree is viewed from above.
    for(int i = leftMostNode; i <= rightMostNode; i++){
        cout<<m[i]<<" ";
    }
}
//Top View of the our binary tree : 4 2 1 3 7


//The bottom view of a binary tree is the set of nodes that are visible when the tree is viewed from below.
void bottomView(TreeNode* root){

    if(!root) return ;
        
    int leftMostNode = 0;
    int rightMostNode = 0;
    int level = 0;
        
    queue<pair<TreeNode*,int>>q;
    q.push({root,level});
    unordered_map<int,int> m;
        
    while(!q.empty()){
        TreeNode* temp = q.front().first;
        int lvl = q.front().second;
            
        q.pop();
            
        leftMostNode = min(leftMostNode, lvl);
        rightMostNode = max(rightMostNode, lvl);
            
        m[lvl] = temp->val;
            
        if(temp->left) q.push({temp->left, lvl - 1});
        if(temp->right) q.push({temp->right, lvl + 1});
    }

    //Printing the nodes that are visible when the tree is viewed from below.
    for(int i = leftMostNode; i <= rightMostNode; i++){
        cout<<m[i]<<" ";
    }
}
//Bottom View of the our binary tree : 4 8 6 9 7
