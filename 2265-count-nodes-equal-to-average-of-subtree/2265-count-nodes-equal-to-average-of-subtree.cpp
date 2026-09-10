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
vector<int> solve(TreeNode* node){
    if(node==NULL){
        return {0,0,0};
    }

    vector<int>left = solve(node->left);
    vector<int>right = solve(node->right);

    int avgCount = left[0]+right[0];
    int sum = left[1]+right[1]+node->val;
    int nodeCount = left[2]+right[2]+1;

    if(sum/nodeCount==node->val){
        avgCount++;
    }

    return {avgCount,sum,nodeCount};
}
    int averageOfSubtree(TreeNode* root) {
        vector<int>ans = solve(root);

        return ans[0];
    }
};