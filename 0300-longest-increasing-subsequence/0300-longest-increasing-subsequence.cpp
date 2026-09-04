class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> memo(n + 1, vector<int>(n + 1, 0));
        for (int i = n - 1; i >= 0; i--) {
            for (int pi = i - 1; pi >= -1; pi--) {
                int skip = memo[i + 1][pi + 1];

                int take = 0;
                if (pi == -1 || nums[pi] < nums[i]) {
                    take = 1 + memo[i + 1][i + 1];
                }

                memo[i][pi + 1] = max(take, skip);
            }
        }
        return memo[0][0];
    }
};