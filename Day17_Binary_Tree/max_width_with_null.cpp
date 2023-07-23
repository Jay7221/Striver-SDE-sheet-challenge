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
        queue<pair<TreeNode*, long long>> q;
        if(root != NULL){
            q.push({root, 0});
        }
        int ans = 0;
        while(!q.empty()){
            queue<pair<TreeNode*, long long>> nq;
            int mn = q.front().second;
            int mx = q.front().second;
            while(!q.empty()){
                TreeNode* cur;
                long long level;
                tie(cur, level) = q.front();
                level -= mn;
                mx = level + 1;
                q.pop();
                if(cur -> left){
                    nq.push({cur -> left, 2ll * level});
                }
                if(cur -> right){
                    nq.push({cur -> right, 2ll * level + 1});
                }
            }
            q = nq;
            ans = max(ans, mx);
        }
        return ans;
    }
};
