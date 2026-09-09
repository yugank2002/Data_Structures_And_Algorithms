class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int elem:nums){
            mp[elem]++;
        }

        int prev = -1;
        int count=0;

        
        
        for(int elem:nums){
            if(prev==-1){
                mp[elem]--;
                prev = elem;
                continue;
            }

            if(elem==prev){
                mp[elem]--;
            }
            else{
                if(mp[prev]==0){
                    count++;
                }
                else{
                    mp[prev] = INT_MAX;
                }
                prev = elem;
                mp[elem]--;
            }
        }
        if(mp[prev]==0)count++;

        return count;
    }
};