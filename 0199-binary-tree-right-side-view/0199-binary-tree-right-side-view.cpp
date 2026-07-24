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
    vector<vector<int>>levelOrder(TreeNode* root){
        vector<vector<int>>ans;
        if(root == NULL){
            return ans;
        }
       
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int>level(size);
            for(int i=0;i<size;i++){
            TreeNode* temp = q.front();
            q.pop();
            level.push_back(temp->val);
            if(temp->left != NULL){
                q.push(temp->left);
                }
            if(temp->right != NULL){
                q.push(temp->right);
                }
            }
            ans.push_back(level);
        }
        return ans;
    }

    vector<int>res(vector<vector<int>>&last){
        vector<int>ans;
        for(int i=0;i<last.size();i++){
            ans.push_back(last[i][last[i].size()-1]);
        }
        return ans;
    }

    vector<int> rightSideView(TreeNode* root) {
       
        vector<vector<int>>last= levelOrder(root);
        return res(last);
    }
};