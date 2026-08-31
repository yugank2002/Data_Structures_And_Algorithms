class Solution {
public:
int solve(int i, int pi, vector<int>&nums, vector<vector<int>>&memo){
    if(i==nums.size())return 0;

    if(memo[i][pi+1]!=-1)return memo[i][pi+1];

    int skip = solve(i+1,pi,nums,memo);

    int take = 0;
    if(pi==-1 || nums[pi]<nums[i]){
        take = 1+solve(i+1,i,nums,memo);
    }

    return memo[i][pi+1] = max(take,skip);
}
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>memo(n,vector<int>(n,-1));
        return solve(0,-1,nums,memo);
    }
};