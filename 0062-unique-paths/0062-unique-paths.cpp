class Solution {
public:

    int uniquePaths(int m, int n) {
        vector<vector<int>>memo(m,vector<int>(n));
        memo[0][0] = 1;
        for(int i=0;i<m; i++){
            for(int j=0;j<n; j++){
                if(i!=0 || j!=0){
                    int up = (i-1<0)?0:memo[i-1][j];
                    int left = (j-1<0)?0:memo[i][j-1];
                    memo[i][j] = up+left;
                }
            }
        }
        return memo[m-1][n-1];
    }
};