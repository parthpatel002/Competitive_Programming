/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
 
class Solution {
public:
    
    int find_height(TreeNode* root){
        if (root == NULL)
            return 0;
        return 1 + max(find_height(root->left), find_height(root->right));
    }
    
    void recurse(TreeNode* root, int depth, int& height, int& sum){
        if (root == NULL)
            return;
        if (depth == height)
            sum += root->val;
        else{
            recurse(root->left, depth+1, height, sum);
            recurse(root->right, depth+1, height, sum);
        }
    }
    
    int deepestLeavesSum(TreeNode* root) {
        int ht = find_height(root);
        int sum = 0;
        recurse(root, 1, ht, sum);
        return sum;
    }
    
};
