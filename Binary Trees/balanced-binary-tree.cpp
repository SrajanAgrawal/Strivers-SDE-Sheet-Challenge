// First Solution (Naiva Approach) - brute force approach 

TC - O(N) * O(N) => O(N^2) 
class Solution {
public:

    int maxDepth(TreeNode* node){
        if (node == NULL) return 0;
        int lh = maxDepth(node->left);
        int rh = maxDepth(node->right);

        return (1 + max(lh,rh));
    }
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;
        int lh = maxDepth(root->left);
        int rh = maxDepth(root->right);
        if(abs(lh-rh) > 1) return false;

        bool left = isBalanced(root->left);
        bool right = isBalanced(root->right);
        if(!left || !right) return false;

        return true;
    }
};


// Second Solution (Best Solution) - O(N) SC-> O(H)

bool isBalanced(TreeNode *root){
    return dfsHeight(root) != -1;
}
int dfsHeight(TreeNode* root) {
    if(root == NULL) return 0;
    int leftHeight = dfsHeight(root->left);

    // Condition for checking the balanced binary tree.
    if(leftHeight == -1)  return -1;
    int rightHeight = dfsHeight(root->right);
    // Condition for checking the balanced binary tree.
    if(rightHeight == -1) return -1;


    // condiiton for checkng the balanced binary tree.
    if(abs(leftHeight - rightHeight) > 1) return -1;

    return max(leftHeight, rightHeight) + 1;
}
