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
    void markParent(TreeNode* root, unordered_map<TreeNode*,TreeNode*>&parent){
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();

            if(temp->left){
                parent[temp->left] = temp;
                q.push(temp->left);
            }
            if(temp->right){
                parent[temp->right] = temp;
                q.push(temp->right);
            }
        }
    }

    TreeNode* find(TreeNode* root,int start){
        if(root == NULL){
            return NULL;
        }
        if(root->val == start){
            return root;
        }
        TreeNode* left = find(root->left,start);
        TreeNode* right = find(root->right,start);

        return left ? left : right;
    }

    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*,TreeNode*>parent;
        markParent(root,parent);
        unordered_map<TreeNode*,bool>visited;
        
        TreeNode* target = find(root,start);
        queue<TreeNode*>q;
        q.push(target);
        visited[target] = true;
        int time=0;
        while(!q.empty()){
            int size = q.size();
            time++;
            for(int i=0;i<size;i++){
                TreeNode* temp = q.front();
                q.pop();

                if(temp->left &&  !visited[temp->left]){
                    q.push(temp->left);
                    visited[temp->left] = true;
                }

                if(temp->right &&  !visited[temp->right]){
                    q.push(temp->right);
                    visited[temp->right] = true;
                }

                if(parent[temp] && !visited[parent[temp]]){
                    q.push(parent[temp]);
                    visited[parent[temp]] = true;
                }
            }
        }
        return time-1;
    }
};