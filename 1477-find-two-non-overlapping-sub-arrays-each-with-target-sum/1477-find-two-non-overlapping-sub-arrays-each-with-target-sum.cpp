class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int>prevSize(n,INT_MAX);

        int currSum = 0;
        int i=0;
        int j=0;
        int result = INT_MAX;
        int bestSize = INT_MAX;
        while(j<n){
            currSum+=arr[j];

            while(currSum>target){
                currSum-=arr[i];
                i++;
            }

            if(currSum==target){
                int len = j-i+1;
                if(i>0 && prevSize[i-1]!=INT_MAX){
                    result = min(result,len+prevSize[i-1]);
                }
                bestSize = min(bestSize,len);
            }
            prevSize[j] = bestSize;
            j++;
        }

        return result==INT_MAX?-1:result;
    }
};