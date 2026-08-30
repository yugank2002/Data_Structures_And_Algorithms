class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        if(n<=2)return n;
        if(n==3)return 2;

        int minInd;
        int minElem = INT_MAX;
        int maxInd;
        int maxElem = INT_MIN;

        for(int i=0; i<n; i++){
            if(nums[i]<minElem){
                minElem = nums[i];
                minInd = i;
            }
            if(nums[i]>maxElem){
                maxElem = nums[i];
                maxInd = i;
            }
        }

        int case1 = max(maxInd,minInd)+1;
        int case2 = n - min(maxInd,minInd);
        int case3 = min(maxInd,minInd)+1 + n-max(maxInd,minInd);

        return min({case1,case2,case3});

        
    }
};