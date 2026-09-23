class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int totalSum = accumulate(nums.begin(),nums.end(),0);
        int sum = totalSum-x;

        cout<<sum;

        int left=0;
        int right = 0;
        int currSum = 0;
        int ans= -1;
        while(right<n){
            currSum+=nums[right];
            

            while(currSum>sum && left<=right){
                currSum-=nums[left];
                left++;
            }

            if(currSum==sum){
                ans = max(ans,right-left+1);
            }

            right++;


        }

        return ans==-1?ans:n-ans;
    }
};