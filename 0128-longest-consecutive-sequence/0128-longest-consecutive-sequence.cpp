class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)return 0;
        set<int>s;
        for(int elem:nums){
            s.insert(elem);
        }
        int size = 1;
        int currSize = 1;
        auto curr = s.begin();
        curr++;
        auto prev = s.begin();
        while(curr!=s.end()){
            if(*prev+1 == *curr){
                currSize++;
                size = max(size,currSize);
                curr++;
                prev++;
            }
            else{
                currSize = 1;
                curr++;
                prev++;
            }
        }

        return size;
    }
};