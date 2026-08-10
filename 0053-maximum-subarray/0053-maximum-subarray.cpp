class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = INT_MIN;
        int currSum = 0;
        int i=0;
        while(i<nums.size()){
            currSum+=nums[i];
            sum = max(sum,currSum);
            if(currSum<0){
                currSum = 0;
                
            }
            
            i++;
        }
        return sum;
    }
};