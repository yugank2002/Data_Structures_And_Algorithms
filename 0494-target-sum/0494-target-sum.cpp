class Solution {
public:
int solve(int i, int sum, vector<int>&arr){
    if(i<0){
        if(sum==0)return 1;
        else return 0;
    }

    int plus = solve(i-1,sum-arr[i],arr);
    int minus = solve(i-1,sum+arr[i],arr);

    return plus+minus;
}
    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(nums.size()-1,target,nums);
    }
};