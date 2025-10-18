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

// Use DFS

class Solution {
public:
    int answer = 0; // found max depth
    int maxDepth(TreeNode* root, int depth=1) {
        // depth indicates the level of the current node
        if(root == nullptr) return 0;

        answer = max(answer, depth);

        if(root->left) { // left child exists
            maxDepth(root->left, depth+1);
        } 
        if(root->right) { // right child exists
            maxDepth(root->right, depth+1);
        }

        return answer;
    }
};