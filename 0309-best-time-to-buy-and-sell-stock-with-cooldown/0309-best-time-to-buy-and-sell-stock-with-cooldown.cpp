class Solution {
public:
int solve(int i, bool canBuy, vector<int>&prices, vector<vector<int>>&memo){
    if(i>=prices.size()){
        return 0;
    }

    if(memo[i][canBuy]!=-1)return memo[i][canBuy];

    if(canBuy){
        int take = -prices[i] + solve(i+1,false,prices,memo);
        int skip = solve(i+1,true,prices,memo);
        return memo[i][canBuy] = max(take,skip);
    }

    int take = prices[i] + solve(i+2,true,prices,memo);
    int skip = solve(i+1,false,prices,memo);
    return memo[i][canBuy] = max(take,skip);

}
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>memo(n,vector<int>(2,-1));
        return solve(0,true,prices,memo);
    }
};