class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,1);
        int maxi = 1;
        vector<int>count(n,1);
        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                if(nums[j]<nums[i]){
                    if(dp[i]<dp[j]+1){
                        dp[i] = 1+dp[j];
                        count[i] = count[j];
                    }
                    else if(dp[i]==1+dp[j]){
                        count[i]+=count[j];
                    }
                }
            }
            maxi = max(maxi,dp[i]);
        }

        int c=0;
        for(int i=0; i<n; i++){
            if(maxi==dp[i]){
                c+=count[i];
            }
        }

        return c;
    }
};