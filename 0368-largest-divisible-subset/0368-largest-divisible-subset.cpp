class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<int> dp(n,0), hash(n);
        int maxi=0;
        for(int i=0; i<n; i++){
            hash[i] = i;
            for(int j=0; j<i; j++){
                if(nums[i]%nums[j]==0 && dp[j]+1>dp[i]){
                    dp[i] = 1+dp[j];
                    hash[i] = j;
                }
            }

            if(dp[i]>dp[maxi]){
                maxi = i;
            }
        }

        vector<int>ans;
        while(maxi!=hash[maxi]){
            ans.push_back(nums[maxi]);
            maxi = hash[maxi];
        }
        ans.push_back(nums[maxi]);

        reverse(ans.begin(),ans.end());
        return ans;
    }
};