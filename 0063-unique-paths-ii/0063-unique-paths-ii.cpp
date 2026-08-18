class Solution {
public:
int solve(int i, int j, vector<vector<int>>&obstacle){
    if(i<0 || j<0 || obstacle[i][j])return 0;

    if(i==0 && j == 0){
        return 1;
    }
    
    int up = solve(i-1,j,obstacle);
    int left = solve(i,j-1,obstacle);

    return up+left;
}
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid[0][0])return 0;
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>>memo(m,vector<int>(n,0));
        memo[0][0] = 1;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if((i!=0 || j!=0) && !obstacleGrid[i][j]){
                    int up = (i-1<0)?0:memo[i-1][j];
                    int left = (j-1<0)?0:memo[i][j-1];
                    memo[i][j] = up+left;
                }
            }
        }

        return memo[m-1][n-1];
    }
};