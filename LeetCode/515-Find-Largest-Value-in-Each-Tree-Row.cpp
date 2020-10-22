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

#include <bits/stdc++.h>

class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        
        if (root == NULL)
            return vector<int>();
        vector<int> vec;
        queue<pair<TreeNode*, int>> q;
        int curr_depth = 0;
        q.push(make_pair(root, curr_depth));
        vec.push_back(INT_MIN);
        while(!q.empty()){
            pair<TreeNode*, int> p = q.front();
            q.pop();
            if(p.second == curr_depth){
                vec[vec.size()-1] = max(vec[vec.size()-1], (p.first)->val);
            }
            else{
                curr_depth += 1;
                vec.push_back((p.first)->val);
            }
            if((p.first)->left != NULL)
                q.push(make_pair((p.first)->left, p.second+1));
            if((p.first)->right != NULL)
                q.push(make_pair((p.first)->right, p.second+1));
        }
        return vec;
        
    }
};
