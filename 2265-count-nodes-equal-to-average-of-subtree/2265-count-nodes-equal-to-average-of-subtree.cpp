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
int ans = 0;
pair<int,int> solve(TreeNode* node){
    if(node==NULL){
        return {0,0};
    }

    auto left = solve(node->left);
    auto right = solve(node->right);

    
    int sum = left.first + right.first + node->val;
    int nodeCount = left.second + right.second + 1;

    if(sum/nodeCount==node->val){
        ans++;
    }

    return {sum,nodeCount};
}
    int averageOfSubtree(TreeNode* root) {
        auto res = solve(root);

        return ans;
    }
};