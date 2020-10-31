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
    void recoverTree(TreeNode* root) {
        
        vector<pair<TreeNode*, TreeNode*>> vec;
        stack<TreeNode*> st;
        TreeNode* temp = root;
        while(temp->left != NULL){
            st.push(temp);
            temp = temp->left;
        }
        
        TreeNode* prev = temp;
        
        if(temp->right != NULL){
            temp = temp->right;
            while(temp != NULL){
                st.push(temp);
                temp = temp->left;
            }
        }
        
        TreeNode* curr;
        
        while(!st.empty()){
            curr = st.top();
            st.pop();
            temp = curr->right;
            while(temp != NULL){
                st.push(temp);
                temp = temp->left;
            }
            if(prev->val > curr->val)
                vec.push_back(make_pair(prev, curr));
            prev = curr;
        }
        
        if(vec.size() == 1){
            int tmp = (vec[0].first)->val;
            (vec[0].first)->val = (vec[0].second)->val;
            (vec[0].second)->val = tmp;
        }
        else{
            int tmp = (vec[0].first)->val;
            (vec[0].first)->val = (vec[1].second)->val;
            (vec[1].second)->val = tmp;
        }
        
    }
};
