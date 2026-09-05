class Solution {
public:
long long solve(int i, int j, vector<int>&arr){
    if(i>j)return 0;

    long long maxi = INT_MIN;
    for(int k=i; k<=j; k++){

        long long cost = arr[i-1]*arr[j+1]*arr[k] + solve(i,k-1,arr) + solve(k+1,j,arr);
        

        maxi = max(maxi,cost);
        
    }

    return maxi;
}
    int maxCoins(vector<int>& arr) {
        
        arr.insert(arr.begin(),1);
        arr.push_back(1);
        int n = arr.size();

        vector<vector<int>>memo(n,vector<int>(n,0));

        for(int i=n-2; i>=1; i--){
            for(int j=1; j<n-1; j++){
                if(i>j)continue;

                long long maxi = INT_MIN;
                for(int k=i; k<=j; k++){

                    long long cost = arr[i-1]*arr[j+1]*arr[k] + memo[i][k-1] + memo[k+1][j];
                    

                    maxi = max(maxi,cost);
                    
                }

                memo[i][j] = maxi;
            }
        }

        return memo[1][n-2];
    }
};