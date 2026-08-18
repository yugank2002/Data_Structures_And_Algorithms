class Solution {
public:
int solveFor1(vector<int>&nums){
    unordered_map<int,int>mp;
    for(int elem:nums){
        mp[elem]++;
    }

    int maxi = -1;
    for(auto it:mp){
        if(it.second==1){
            maxi = max(maxi,it.first);
        }
    }

    return maxi;
}

int solveForN(vector<int>&nums){
    int maxi=-1;
    for(int elem:nums){
        maxi = max(maxi,elem);
    }
    return maxi;
}

    int largestInteger(vector<int>& nums, int k) {
        if(k==1)return solveFor1(nums);
        if(k==nums.size())return solveForN(nums);
        

        int first = nums[0];
        int last = nums[nums.size()-1];
        if(first == last)return -1;
        bool f = false;
        bool l = false;

        for(int i=1; i<nums.size()-1; i++){
            if(nums[i] == first){
                f = true;
            }
            if(nums[i] == last){
                l = true;
            }
        }

        if(!f && !l){
            return max(first,last);
        }
        if(!f)return first;
        if(!l)return last;

        return -1;
    }
};