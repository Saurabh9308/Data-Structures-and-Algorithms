#include<iostream>
#include "implementation_of_tree.cpp"
#include<stack>
using namespace std;

/*
Tree we are implementing looks like: 

        2
       / \
      4  10
     / \   \
    6   5   1

*/



//Following are the Recursive methods of traversals on tree

//Pre-order Traversal : Root->Data - leftSubtree - rightSubtree
void preorderTraversal(TreeNode* root){
    if(!root) return;       //Base Condition: (root == NULL)

    //Printing Root Data
    cout<<root->val<<" ";

    //Recursive call to the left Subtree
    preorderTraversal(root->left);

    //Recursive call to the right Subtree
    preorderTraversal(root->right);
}
//Pre-order traversal of our tree: 2 4 6 5 10 1


//In-order Traversal : leftSubtree - Root->Data - rightSubtree
void inorderTraversal(TreeNode* root){
    if(!root) return;       //Base Condition: (root == NULL)


    //Recursive call to the left Subtree
    inorderTraversal(root->left);

    //Printing Root Data
    cout<<root->val<<" ";

    //Recursive call to the right Subtree
    inorderTraversal(root->right);
}
//In-order traversal of our tree: 6 4 5 2 10 1


//Post-order Traversal : leftSubtree - rightSubtree - Root->Data 
void postorderTraversal(TreeNode* root){
    if(!root) return;       //Base Condition: (root == NULL)


    //Recursive call to the left Subtree
    postorderTraversal(root->left);

    //Recursive call to the right Subtree
    postorderTraversal(root->right);

    //Printing Root Data
    cout<<root->val<<" ";
}
//Post-order traversal of our tree: 6 5 4 1 10 2



//Following Are the iterative methods of the traversals

//Pre-order Traversal interative technique
void iPreorderTraversal(TreeNode* root){
    stack<TreeNode*> st;
    st.push(root);

    while(!st.empty()){
        TreeNode* temp = st.top();
        st.pop();

        cout<<temp->val<<" ";
        if(temp->right) st.push(temp->right);
        if(temp->left) st.push(temp->left);
    }
}
//Pre-order traversal of our tree: 2 4 6 5 10 1


//In-order Traversal interative technique
void iIntorderTraversal(TreeNode* root){
    stack<TreeNode*> st;
    TreeNode* node = root;

    while(!st.empty() || node){
        if(node){  //If node is not equal to NULL
            st.push(node);
            node = node->left;
        }
        else{   //If node is equal to NULL
            TreeNode* temp = st.top();
            st.pop();
            cout<<temp->val<<" ";
            node = temp->right;
        }
    }
}
//In-order traversal of our tree: 6 4 5 2 10 1


//Post-order Traversal interative technique
void iPostorderTraversal(TreeNode* root){
    stack<TreeNode*> st1;
    stack<TreeNode*> st2;
    st1.push(root);

    while(!st1.empty()){
        TreeNode* temp = st1.top();
        st1.pop();

        st2.push(temp);
        if(temp->left) st1.push(temp->left);
        if(temp->right) st1.push(temp->right);
    }

    while(!st2.empty()){
        cout<<st2.top()->val<<" ";
        st2.pop();
    }
}
//Post-order traversal of our tree: 6 5 4 1 10 2

