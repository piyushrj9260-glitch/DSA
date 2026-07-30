/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == NULL){
            return "";
        }
        string s = "";
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            if(temp == NULL){
                s.append("#,");
            }else{
                s.append(to_string(temp->val)+',');
            }

            if(temp != NULL){
                q.push(temp->left);
                q.push(temp->right);
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        
        if(data.size() == 0){
            return NULL;
        }

        stringstream str(data);
        string word;
        getline(str,word,',');
        TreeNode* root = new TreeNode(stoi(word));
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            
            getline(str,word,',');
            if(word != "#"){
                
                temp->left = new TreeNode(stoi(word));
                q.push(temp->left);
            }
            getline(str,word,',');
            if(word != "#"){
                
                temp->right = new TreeNode(stoi(word));
                q.push(temp->right);
            }

        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;