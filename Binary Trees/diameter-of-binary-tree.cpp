// Brute force solution 

// O(N^2) - Time Complexity
// O(H^2) - Space Complexity


class Solution {
public:

    int maxDepth(TreeNode* root){
        if(root == NULL) return 0;

        int lh = maxDepth(root->left);
        int rh = maxDepth(root->right);

        return (1 + max(lh,rh));
    }
    int d = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;
        int lh = maxDepth(root->left);
        int rh = maxDepth(root->right);

        d = max(d, (lh+rh));

        diameterOfBinaryTree(root->left);
        diameterOfBinaryTree(root->right);

        return (d);
    }
};


// Optimized approach

class Solution {
public:
    int maxi = 0;
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        int lh = maxDepth(root->left);
        int rh = maxDepth(root->right);
        maxi = max(maxi, (lh+rh));
        return (1 + max(lh , rh));
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int d = maxDepth(root);
        return maxi;
    }
};