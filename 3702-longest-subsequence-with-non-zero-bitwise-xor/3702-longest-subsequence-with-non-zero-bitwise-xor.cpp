class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        bool flag = false;
        int Xor = 0;
        for(int elem:nums){
            Xor^=elem;
            if(elem>0)flag = true;
        }
        if(!flag)return 0;

        if(Xor)return nums.size();

        return nums.size()-1;
        
        
    }
};