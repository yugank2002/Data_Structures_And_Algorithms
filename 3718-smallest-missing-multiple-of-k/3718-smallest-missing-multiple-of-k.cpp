class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n = nums.size();

        int num = k;
        int i=0;
        while(i<n){
            if(nums[i]==num){
                i++;
                num += k;
                continue;
            }
            if(nums[i]<num){
                i++;

            }
            else{
                break;
            }
        }

        return num;
    }
};