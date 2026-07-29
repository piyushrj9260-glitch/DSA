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
    int findSecondMinimumValue(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        long long second = LLONG_MAX;
        int first = root->val;

        while(!q.empty()){

            TreeNode* temp = q.front();
            q.pop();

            if(temp->val > first && temp->val < second){
                second = temp->val;
            }

            if(temp->left)
                q.push(temp->left);

            if(temp->right)
                q.push(temp->right);
        }

        return second == LLONG_MAX ? -1 : second;
    }
};