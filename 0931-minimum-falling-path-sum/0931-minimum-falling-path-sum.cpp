class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>>memo(n,vector<int>(n));

        for(int j=0; j<n; j++){
            memo[0][j] = matrix[0][j];
            
        }
        for(int i=1; i<n; i++){
            for(int j=0; j<n; j++){
                int up = memo[i-1][j];
                int left = (j-1<0)?INT_MAX:memo[i-1][j-1];
                int right = (j+1>=n)?INT_MAX:memo[i-1][j+1];

                memo[i][j] = matrix[i][j]+min({up,left,right});
            }
        }

        int mini = INT_MAX;

        for(int j=0; j<n; j++){
            mini = min(mini,memo[n-1][j]);
        }

        return mini;
    }
};