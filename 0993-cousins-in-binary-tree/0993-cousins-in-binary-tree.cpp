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
    int depthX = -1,  depthY = -1;
    TreeNode* parentX = NULL;
    TreeNode* parentY = NULL;
    void dfs(TreeNode* root,TreeNode* parent,int depth,int x,int y){
        if(root == NULL){
            return;
        }

        if(root->val == x){
            depthX = depth;
            parentX = parent;
        }

        if(root->val == y){
            depthY = depth;
            parentY  = parent;
        }
        dfs(root->left,root,depth+1,x,y);
        dfs(root->right,root,depth+1,x,y);
    }

    bool isCousins(TreeNode* root,int x, int y) {
        dfs(root,NULL,0,x,y);
        if(depthX == depthY && parentX != parentY){
            return true;
        }

        return false;
    }
};