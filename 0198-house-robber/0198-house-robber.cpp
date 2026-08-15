class Solution {
public:
int solve(int ind, vector<int>&arr, vector<int>&memo){
    if(ind<0)return 0;

    if(memo[ind]!=-1)return memo[ind];

    int take = arr[ind]+solve(ind-2,arr,memo);
    int notTake = solve(ind-1,arr,memo);

    return memo[ind] = max(take,notTake);
}
    int rob(vector<int>& nums) {
        vector<int>memo(nums.size()+1,-1);
        return solve(nums.size()-1,nums,memo);
    }
};