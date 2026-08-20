class Solution {
public:

bool solve(int ind, int sum, vector<int>&arr, vector<vector<int>>&memo){
    if(sum==0)return 1;
    
    if(ind>=arr.size() || sum<0)return 0;

    if(memo[ind][sum]!=-1)return memo[ind][sum];
    int take = solve(ind+1,sum-arr[ind],arr,memo);
    int notTake = solve(ind+1,sum,arr,memo);

    return memo[ind][sum] = take||notTake;
}
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int elem:nums){
            sum+=elem;
        }
        if(sum%2)return false;

        vector<vector<int>>memo(nums.size(),vector<int>(sum/2+1,-1));
        return solve(0,sum/2,nums,memo);
    }
};