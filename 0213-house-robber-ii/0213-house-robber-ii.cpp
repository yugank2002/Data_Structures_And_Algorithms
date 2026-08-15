class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==0)return 0;
        if(n==1)return nums[0];

        vector<int>ans1(n);
        vector<int>ans2(n);

        for(int i=0; i<n-1; i++){
            int take = nums[i] + ((i-2>=0)?ans1[i-2]:0);
            int notTake = (i-1>=0)?ans1[i-1]:0;
            ans1[i] = max(take,notTake);
        }
        for(int i=1; i<n; i++){
            int take = nums[i] + ((i-2>=1)?ans2[i-2]:0);
            int notTake = (i-1>=1)?ans2[i-1]:0;
            ans2[i] = max(take,notTake);
        }

        return max(ans1[n-2],ans2[n-1]);
    }
};