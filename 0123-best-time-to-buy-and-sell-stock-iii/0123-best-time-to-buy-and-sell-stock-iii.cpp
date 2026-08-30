class Solution {
public:
int solve(int i, int buy, bool canBuy, vector<int>&prices, vector<vector<vector<int>>>&memo){
    if(i==prices.size())return 0;

    if(buy==0 && canBuy)return 0;

    if(memo[i][buy][canBuy]!=-1)return memo[i][buy][canBuy];

    if(canBuy){
        int take = -prices[i]+solve(i+1,buy-1,false,prices,memo);
        int notTake = solve(i+1,buy,true,prices,memo);
        return memo[i][buy][canBuy] = max(take,notTake);
    }
    
    int take = prices[i]+solve(i+1,buy,true,prices,memo);
    int notTake = solve(i+1,buy,false,prices,memo);

    return memo[i][buy][canBuy] = max(take,notTake);
}
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>>memo(n+1,vector<vector<int>>(2+1,vector<int>(2,-1)));
        return solve(0,2,true,prices,memo);
    }
};