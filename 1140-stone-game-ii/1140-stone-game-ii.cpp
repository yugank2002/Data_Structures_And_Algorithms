class Solution {
public:
int solve(int ind, int M, bool flag, vector<int>&arr, vector<vector<vector<int>>>&dp){
    if(ind>=arr.size())return 0;

    if(dp[ind][M][flag]!=-1)return dp[ind][M][flag];

    int stone = 0;
    int result = flag?INT_MIN:INT_MAX;
    for(int x=1; x<=2*M && ind+x<=arr.size(); x++){
        stone+=arr[ind+x-1];
        if(flag){
            result = max(result,stone + solve(ind+x,max(x,M),false,arr,dp));
        }
        else{
            result = min(result,solve(ind+x,max(x,M),true,arr,dp));
        }
    }

    return dp[ind][M][flag] = result;
}
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(n+1, vector<int>(2,-1)));
        return solve(0,1,1,piles,dp);
    }
};