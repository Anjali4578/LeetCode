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
    bool inorder(TreeNode* root, int value) {
        if (root == NULL) return true;

        if (!inorder(root -> left, value)) return false;
        if (root -> val != value) {
            return false;
        }
        if (!inorder(root -> right, value)) return false;
        return true;
    }

    bool isUnivalTree(TreeNode* root) {
        int value = root -> val;
        return inorder(root, value);

        // T.C. = O(N) for traversal
        // S.C. = O(H)
    }
};