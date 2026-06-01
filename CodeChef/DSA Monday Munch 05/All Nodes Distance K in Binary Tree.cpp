// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };

class Solution {
public:
    void parent_edges(TreeNode* root, TreeNode* target, unordered_map<TreeNode*,TreeNode* > &m){
        
        queue<TreeNode*>q;
        q.push(root);
        
        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();
            
            if(curr->left){
                m[curr->left] = curr;
                q.push(curr->left);
            }
            
            if(curr->right){
                m[curr->right] = curr;
                q.push(curr->right);
            }
            
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        // write your code here
        if(!root || !target) return {};
        
        unordered_map<TreeNode*, TreeNode*> m;
        parent_edges(root, target,m);
        
        unordered_map<TreeNode*, bool> vis;
        queue<TreeNode*> q;
        int lvl=0;
        vector<int> ans;
        q.push(target);
        vis[target] = true;
        
        int curr_level = 0;
        while(!q.empty()) {
            
            int sz = q.size();
            if (lvl++ == k) break;
                
            while (sz--) {
            
                TreeNode* curr = q.front();
                q.pop();
            
                if (curr->left && !vis[curr->left]) {
                    vis[curr->left] = true;
                    q.push(curr->left);
                }
                if (curr->right && !vis[curr->right]) {
                    vis[curr->right] = true;
                    q.push(curr->right);
                }
                
                if ( (m.find(curr) != m.end() && !vis[m[curr]]) ) {
                    vis[m[curr]] = true;
                    q.push(m[curr]);
                }
            }
        }
        while (!q.empty()) {
            TreeNode* c = q.front();
            q.pop();
            ans.push_back(c->val);
        }
        
        return ans;
    }
};
