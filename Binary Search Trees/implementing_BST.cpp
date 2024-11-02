//Building Binary Search Tree from the Sorted Array
#include<iostream>
#include<vector>
using namespace std;


//Class for the Binary Search Tree Node
class TreeNode{
public:
    //Integer Data of the Node
    int data;           

    //Left and Right child of the Node
    TreeNode* left;
    TreeNode* right;

    //Constructor
    TreeNode(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

//Function for Building A Binary Search Tree(BST)
TreeNode* buildBST(TreeNode* root, vector<int> arr, int low, int high){
    if(low > high) return NULL;     //Base Condition

    int mid = low + (high - low)/2;

    root = new TreeNode(arr[mid]);      //Root Node

    //Building Left Subtree
    root->left = buildBST(root->left,arr,low,mid-1);

    //Building Right Subtree
    root->right = buildBST(root->right,arr,mid+1,high);

    return root;
}
