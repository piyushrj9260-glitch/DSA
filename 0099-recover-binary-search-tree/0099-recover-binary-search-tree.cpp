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
    TreeNode* first = NULL;
    TreeNode* middle = NULL;
    TreeNode* last = NULL;
    TreeNode* prevNode = NULL;

    void inorder(TreeNode* root){
        if(root == NULL){
            return;
        }

        inorder(root->left);
        if(prevNode != NULL && prevNode->val > root->val){
            if(first == NULL){
                first = prevNode;
                middle = root;
            }else{
                last = root;
            }
        }
        prevNode = root;
        inorder(root->right);
    }

    void recoverTree(TreeNode* root) {
        first = middle = last = prevNode = NULL;

        inorder(root);

        if(first && last){
            swap(first->val,last->val);
        }else if(first && middle){
            swap(first->val,middle->val);
        }
    }
};