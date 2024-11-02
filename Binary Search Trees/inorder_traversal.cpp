//The inorder traversal of a BST produces the nodes in sorted order

#include<iostream>
#include<stack>
#include "implementing_BST.cpp"
using namespace std;


void inorderTraversal(TreeNode* root){
    TreeNode* node = root;

    stack<TreeNode*> st;

    while(!st.empty() || node){ //Loop will run until stack is not empty or node is not NULL
        //Going Extream left of the Binary Search Tree
        if(node){   
            st.push(node);
            node = node->left;
        }
        else{   //node == NULL
            TreeNode* temp = st.top();      //accessing the top node in the stack
            st.pop();

            cout<<temp->data<<" ";

            //Going right 
            node = temp->right;
        }
    }
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

   inorderTraversal(root);
   //Output of the Inorder Traversal: 1 2 3 4 5 6 7 8 9 10
}