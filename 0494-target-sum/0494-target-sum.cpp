class Solution {
public:
    int total = 0;
    int solve(int i, int sum, vector<int>& arr, vector<vector<int>>& memo) {
        if (i < 0) {
            if (sum == 0)
                return 1;
            else
                return 0;
        }
        if (sum > total || sum < -total)
            return 0;

        if (memo[i][sum + total] != -1)
            return memo[i][sum + total];
        int plus = solve(i - 1, sum - arr[i], arr, memo);
        int minus = solve(i - 1, sum + arr[i], arr, memo);

        return memo[i][sum + total] = plus + minus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {

        for (int elem : nums) {
            total += elem;
        }

        if (abs(target) > total)
            return 0;

        vector<vector<int>> memo(nums.size() + 1,
                                 vector<int>(total * 2 + 1, -1));
        return solve(nums.size() - 1, target, nums, memo);
    }
};