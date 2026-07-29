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
    int countNodes(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        int leftH = 0;
        TreeNode* leftNode = root;
        while(leftNode != NULL){
            leftH++;
            leftNode = leftNode->left;
        }
        int rightH = 0;
        TreeNode* rightNode = root;
        while(rightNode != NULL){
            rightH++;
            rightNode = rightNode->right;
        }

        if(leftH == rightH){
            return pow(2,leftH) - 1;
        }

        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};