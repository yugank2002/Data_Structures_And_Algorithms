class Solution {
public:
    int rob(vector<int>& nums) {

        vector<int> ans(nums.size());
        for (int i = 0; i < ans.size(); i++) {
            int take = nums[i] + ((i - 2 >= 0) ? ans[i - 2] : 0);
            int notTake = (i - 1 >= 0) ? ans[i - 1] : 0;
            ans[i] = max(take, notTake);
        }

        return ans[ans.size() - 1];
    }
};