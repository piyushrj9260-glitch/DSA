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
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        long long ans = 0;
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        while(!q.empty()){
            int size = q.size();
            long long minInd = q.front().second;
            long long first,last;
            for(int i=0;i<size;i++){
                long long curInd = q.front().second - minInd;
                TreeNode* temp = q.front().first;
                q.pop();
                if(i == 0) first = curInd;
                if(i == size-1) last = curInd;

                if(temp->left){
                    q.push({temp->left,curInd*2+1});
                }
                if(temp->right){
                    q.push({temp->right,curInd*2+2});
                }
            }
            ans = max(ans,last-first+1);
        }
        return ans;
    }
};