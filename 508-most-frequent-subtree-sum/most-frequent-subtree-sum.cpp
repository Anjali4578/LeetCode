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
    int dfs (TreeNode* root) {
        if (root == NULL) return 0;
        int sum = dfs(root -> left) + dfs(root -> right) + root -> val;
        maxFrequency = max( maxFrequency, ++mp[sum]);

        return sum;
    }

public:
    unordered_map<int, int> mp;
    int maxFrequency = 0;

    vector<int> findFrequentTreeSum(TreeNode* root) {
        dfs(root);
        vector<int> ans;

        for (auto it: mp) { 
            if (it.second ==  maxFrequency) {
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};