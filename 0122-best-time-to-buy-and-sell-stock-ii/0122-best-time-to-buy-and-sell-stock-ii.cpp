class Solution {
public:

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        
        vector<vector<int>>memo(n,vector<int>(2,0));
        memo[0][1] = -prices[0];
        for(int i=1; i<n; i++){
            int take1 = -prices[i] + memo[i-1][0];
            int notTake1 = memo[i-1][1];
            
            int take2 = prices[i] + memo[i-1][1];
            int notTake2 = memo[i-1][0];

            memo[i][0] = max(take2,notTake2);
            memo[i][1] = max(take1,notTake1);
        }

        return memo[n-1][0];

    }
};