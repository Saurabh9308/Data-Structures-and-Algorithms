#include<iostream>
#include "implementation_of_tree.cpp"
#include<queue>
#include<stack>
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

//Function for finding height of the binary tree
//Height of Binary tree s defined as the number of edges on the longest downward path from the root to a leaf.
int height(TreeNode* root){
    if(!root) return 0;

    return max(height(root->left),height(root->right)) + 1;
}

//Function for counting the total number of nodes the tree
int countNodes(TreeNode* root){
    if(!root) return 0;

    queue<TreeNode*> q;
    q.push(root);
    int count = 0;
    while(!q.empty()){
        TreeNode* temp = q.front();
        q.pop();

        count++;
        if(temp->left) q.push(temp->left);
        if(temp->right) q.push(temp->right);
    }

    return count;
}

//Function for counting total number of leaf nodes present in the tree
int countLeafNodes(TreeNode* root){
    if(!root) return 0;

    queue<TreeNode*> q;
    q.push(root);
    int count = 0;

    while(!q.empty()){
        TreeNode* temp = q.front();
        q.pop();

        if(!temp->left && !temp->right) count++;    //Leaf Node found

        if(temp->left) q.push(temp->left);
        if(temp->right) q.push(temp->right);
    }

    return count;
}


//Functions for searching the data value in the tree
bool searchValue(TreeNode* root, int data){
    if(!root) return false;

    //Using preorder traversal to traverse tree and searching the given data value
    stack<TreeNode*> st;
    st.push(root);

    while(!st.empty()){

        TreeNode* temp = st.top();
        st.pop();

        if(temp->val == data) return true;      //If data found return true
        if(temp->right) st.push(temp->right);
        if(temp->left) st.push(temp->left);
    }

    return false;
}


//Balanced Binary Tree is defined as a binary tree in which the height of the left and right subtrees for every node differs by no more than one.
//Functions for checking is Binary Tree is balanced or not.

pair<bool,int> checkBalanced(TreeNode* root){//Helper function for finding is tree balanced or not
    if(!root) return {true,0};
    /*
        Here,
            pair.first = tells us is tree is balanced for not
            pair.second = gives height of the tree
    */
    pair<bool,int> leftSubtree = checkBalanced(root->left);
    pair<bool,int> rightSubtree = checkBalanced(root->right);

    pair<bool,int> ans;
    ans.first = abs(leftSubtree.second - rightSubtree.second) <= 1 && leftSubtree.first && rightSubtree.first;
    ans.second = max(leftSubtree.second,rightSubtree.second) + 1;

    return ans;
}


bool isBalanced(TreeNode* root){
    return checkBalanced(root).first;
}


//Diameter Of the Binary Tree is defined as the longest path between any two nodes in the tree.
//Function for finding diameter of the tree
pair<int,int> findDiameter(TreeNode* root){//Helper function to find the diameter of the tree
    if(!root) return {0,0};

    /*
        Here,
            pair.first = longest diameter with respect to the current TreeNode
            pair.second = gives height of the tree
    */

    pair<int,int> leftSubtree = findDiameter(root->left);
    pair<int,int> rightSubtree = findDiameter(root->right);

    pair<int,int> ans;
    //Height of the tree rooted at the current node
    ans.second = max(leftSubtree.second,rightSubtree.second) + 1;

    // Diameter at the current node
    int diameterThroughRoot = leftSubtree.second + rightSubtree.second;

    ans.first = max(diameterThroughRoot,max(leftSubtree.first,rightSubtree.first));

    return ans;

}
int diameter(TreeNode* root){
    return findDiameter(root).first;
}