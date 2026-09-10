class Solution {
public:
    int count = 0;
    
    vector<int> solve(TreeNode* root) {
        // Step 1: Base case for null nodes
        if (root == nullptr) {
            return {0, 0};
        }
        
        // Step 2: Post-order traversal (Left, then Right)
        vector<int> Left = solve(root->left);
        vector<int> Right = solve(root->right);

        // Step 3: Aggregate subtree data
        int sum = Left[0] + Right[0] + root->val;
        int n = Left[1] + Right[1] + 1;
        
        // Step 4: Evaluate condition
        int avg = sum / n;
        if (avg == root->val) {
            count++;
        }
        
        // Step 5: Return to parent
        return {sum, n};
    }
    
    int averageOfSubtree(TreeNode* root) {
        solve(root);
        return count;
    }
};