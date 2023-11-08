// First solution using level order traversal.
class Solution {
public:
    int maxDepth(TreeNode* root) {
        // Count stores the count of level 
        if(root == NULL) return 0;
        int count = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            count++;
            for(int i=0;i<n;i++){
                TreeNode* temp = q.front();
                q.pop();
                if(temp->left != NULL){
                    q.push(temp->left);
                }
                if(temp->right != NULL){
                    q.push(temp->right);
                }
            }
        }
        return (count);
    }
};

// Second using recursion (left height and right height)

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        int lh = maxDepth(root->left);
        int rh = maxDepth(root->right);

        return (1 + max(lh,rh));
    }
};

























