class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int ans = 0;
        int start=0;
        long long currSum = 0;
        for(int i=0; i<n; i++){
            currSum+=nums[i];

            while(((long long)(i-start+1)*nums[i]) - currSum >k){
                currSum-=nums[start];
                start++;
            }

            ans = max(ans,i-start+1);
        }

        return ans;
    }
};