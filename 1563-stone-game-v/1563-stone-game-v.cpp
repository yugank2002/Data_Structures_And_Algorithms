class Solution {
public:
int solve(int start, int end, int TotalSum, vector<int>&arr, vector<vector<int>>&memo){
    if(start==end)return TotalSum;

    if(memo[start][end]!=-1)return memo[start][end];

    int maxi  = INT_MIN;
    int currSum = 0;
    for(int i=start; i<end; i++){
        currSum+=arr[i];
        int secondHalfSum = TotalSum-currSum;

        if(currSum == secondHalfSum){
            
                maxi = max(maxi,solve(start,i,currSum,arr,memo));
                maxi = max(maxi,solve(i+1,end,secondHalfSum,arr,memo));
            
        }
        else if(currSum<secondHalfSum){
            maxi = max(maxi,solve(start,i,currSum,arr,memo));
        }
        else{
            maxi = max(maxi,solve(i+1,end,secondHalfSum,arr,memo));
        }
    }

    return memo[start][end] = maxi+TotalSum;
}
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<vector<int>>memo(n+1,vector<int>(n+1,-1));
        int sum = 0;
        for(int elem:stoneValue){
            sum+=elem;
        }
        return solve(0,n-1,sum,stoneValue,memo)-sum;
    }
};