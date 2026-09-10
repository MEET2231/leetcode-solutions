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
    int count = 0;
    vector<int> solve(TreeNode* root)
    {
        if(root->left == nullptr && root->right == nullptr)
        {
            count++;
            return {root->val,1};
            
        }
        
        vector<int> Left = {0,0};
        vector<int> Right = {0,0};

        if(root->left != nullptr) Left = solve(root->left);
        if(root->right != nullptr)Right = solve(root->right);

        int sum = Left[0] + Right[0] + root->val;
        int n = Left[1] + Right[1] + 1;
        int avg = sum / n;
        if(avg == root->val) count++;
        return {sum,n};

    }
    int averageOfSubtree(TreeNode* root) {
        auto temp = solve(root);
        return count;
    }
};