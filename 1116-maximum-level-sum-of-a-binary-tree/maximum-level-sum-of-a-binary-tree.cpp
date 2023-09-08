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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        int level = 0;
        int maxi = INT_MIN;
        int ans_level;

        while (q.size()) {
            int size = q.size();
            level++;
            int sum = 0;

            while (size--) {
                auto x = q.front();
                q.pop();

                sum += x -> val;
                if (x -> left != NULL) q.push(x -> left);
                if (x -> right != NULL) q.push(x -> right);
            }

            if (maxi < sum) {
                maxi = sum;
                ans_level = level;
            }
        }

        return ans_level;
    }
};