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
private: 
    void dfs (TreeNode* node, int targetSum, vector<vector<int>> &ans, vector<int> &path) {
        if (node == NULL) return;
        path.push_back(node -> val);
        targetSum -= node -> val;

        if (node -> left == NULL && node -> right == NULL) {
            if (targetSum == 0) {
                ans.push_back(path);
            }
        }
        else {
            dfs(node -> left, targetSum, ans, path);
            dfs(node -> right, targetSum, ans, path);
        }

        path.pop_back();
    }

public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> path;
        dfs(root, targetSum, ans, path);

        return ans;
    }
};