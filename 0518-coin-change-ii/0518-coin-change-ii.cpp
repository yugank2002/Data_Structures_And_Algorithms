class Solution {
public:
int solve(int i, int sum, vector<int>&coins, vector<vector<int>>&memo){
    if(sum==0)return 1;
    if(sum<0 || i<0)return 0;

    if(memo[i][sum]!=-1)return memo[i][sum];
    int take = 0;
    if(sum>=coins[i]){
        take = solve(i,sum-coins[i],coins,memo);
    }
    int notTake = solve(i-1,sum,coins,memo);

    return memo[i][sum] = take+notTake;
}
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>memo(n+1,vector<int>(amount+1,-1));
        return solve(n-1,amount,coins,memo);
    }
};