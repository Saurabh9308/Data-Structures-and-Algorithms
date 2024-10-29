#include<iostream>
using namespace std;

//Class of the Tree Node
class TreeNode{
    public:
    int val;           
    TreeNode* left;
    TreeNode* right;

    //Constructor
    TreeNode(int val){
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

//Function for Buiding Tree(Recursive Function)
// 2 4 6 -1 -1 5 -1 -1 10 -1 1 -1 -1
TreeNode* buildTree(TreeNode* root){
    int data;
    cout<<"Enter Data: ";
    cin>>data;      //Taking Input of the data of root

    if(data == -1) return NULL;     

    root = new TreeNode(data);

    cout<<endl<<"Inserting in the left of "<<data<<endl;
    root->left = buildTree(root->left);         //Recursive call to the left subTree


    cout<<endl<<"Inserting in the right of "<<data<<endl;
    root->right = buildTree(root->right);       //Recursive call to the right subTree


    return root;
}



/*
Tree we are implementing looks like: 

        2
       / \
      4  10
     / \   \
    6   5   1

*/