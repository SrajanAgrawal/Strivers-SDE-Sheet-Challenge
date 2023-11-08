/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/

void inorder_trav(TreeNode *root, vector<int> &inorder){
    if(root == NULL) return;
    inorder_trav(root->left, inorder);
    inorder.push_back(root->data);
    inorder_trav(root->right, inorder);
}

void preorder_trav(TreeNode *root, vector<int> &preorder){
    if(root == NULL) return;
    preorder.push_back(root->data);
    preorder_trav(root->left, preorder);
    preorder_trav(root->right, preorder);
}

void postorder_trav(TreeNode *root, vector<int> &postorder){
    if(root == NULL) return;
    postorder_trav(root->left, postorder);
    postorder_trav(root->right, postorder);
    postorder.push_back(root->data);
}

vector<vector<int>> getTreeTraversal(TreeNode *root){
    // Write your code here.
    vector<int> inorder;
    inorder_trav(root, inorder);
    vector<int> preorder;
    preorder_trav(root,preorder);
    vector<int> postorder;
    postorder_trav(root, postorder);

    vector<vector<int>> ans;
    ans.push_back(inorder);
    ans.push_back(preorder);
    ans.push_back(postorder);
    
    return (ans);
}