class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
       
        
        for(int i=0; i<nums.size(); i++){
            
            while(nums[i]>=1 && nums[i]<=nums.size() && nums[i]!=nums[nums[i]-1]){
                swap(nums[i],nums[nums[i]-1]);
            }
        }

       


        
        
        int i=0;
        while(i<nums.size() && nums[i] == i+1 ){
            i++;
        }

        return i+1;
    }
};