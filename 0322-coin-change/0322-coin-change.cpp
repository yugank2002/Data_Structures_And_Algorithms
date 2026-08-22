class Solution {
public:
    int solve(int ind, int amount, vector<int>& coins,
              vector<vector<int>>& memo) {
        if (ind < 0 || amount < 0)
            return 1e8;
        if (amount == 0)
            return 0;

        if (memo[ind][amount] != -1)
            return memo[ind][amount];
        int take = 1e8;
        if (amount >= coins[ind]) {
            take = 1 + solve(ind, amount - coins[ind], coins, memo);
        }
        int notTake = solve(ind - 1, amount, coins, memo);

        return memo[ind][amount] = min(take, notTake);
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> memo(coins.size() + 1, vector<int>(amount + 1, -1));
        int ans = solve(coins.size() - 1, amount, coins, memo);
        if (ans >= 1e8)
            return -1;
        return ans;
    }
};