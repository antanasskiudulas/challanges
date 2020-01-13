/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int TreeDepth(TreeNode* node)
    {
        if(node == NULL)
            return 0;
        else
        {
            int left = TreeDepth(node->left);
            int right = TreeDepth(node->right);
            
            if(left>right)
                return left+1;
            else
                return right+1;
        }
    }
    
    void SumTreeLevel(TreeNode* root, int level, int target, int& sum)
    {
        if(root == NULL)
            return;
        
        if(level == target)
            sum += root->val;
        
        SumTreeLevel(root->left, level+1, target, sum);
        SumTreeLevel(root->right, level+1, target, sum);
    }
    int deepestLeavesSum(TreeNode* root) {
        int depth = TreeDepth(root);
        int sum = 0;
        SumTreeLevel(root, 1, depth, sum);
        return sum;
    }
};
