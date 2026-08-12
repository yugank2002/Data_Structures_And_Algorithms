class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(int elem:nums){
            if(mp.find(elem)==mp.end()){
                mp[elem] = 0;
            }
        }

        int size = 1;
        int first = 0;
        int second = 0;
        while(second<nums.size()){
            mp[nums[second]]++;
            while(mp[nums[second]]>k && first<second){
                mp[nums[first]]--;
                first++;
            }

            size = max(size,second-first+1);
            second++;
        }

        return size;
    }
};