// The task is to create a binary tree with a set of values given as a form of an Array here the size is set as 7 elements and then create it. 
/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *left, *right;
    Node()
    {
        this->data = 0;
        left = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->left = NULL;
        this->right = NULL;
    }
    Node(int data, Node* left, Node* right)
    {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};
*/

Node *solve(int i, vector<int> &arr, int n){
    
    Node *head = new Node(arr[i]);

    if(i>=n) return NULL;
    head->left = solve(2*i+1, arr, n);
    head->right = solve(2*i+2, arr, n);
    return head;
}

Node* createTree(vector<int>&arr){
    int n = arr.size();
    return solve(0,arr,n);
}