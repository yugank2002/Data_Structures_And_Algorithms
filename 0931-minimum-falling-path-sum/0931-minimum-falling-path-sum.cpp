class Solution {
public:
int solve(int i, int j, vector<vector<int>>&mat, vector<vector<int>>&memo){
    if(i==mat.size()-1)return mat[i][j];

    if(memo[i][j]!=INT_MAX)return memo[i][j];

    int left = (j-1<0)?INT_MAX:solve(i+1,j-1,mat,memo);
    int down = solve(i+1,j,mat,memo);
    int right = (j+1>=mat.size())?INT_MAX:solve(i+1,j+1,mat,memo);

    return memo[i][j] = mat[i][j]+min({left,right,down});
}
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int mini = INT_MAX;
        int n = matrix.size();
        vector<vector<int>>memo(n,vector<int>(n,INT_MAX));
        for(int i=0; i<matrix.size(); i++){
            mini = min(mini,solve(0,i,matrix,memo));
        }

        return mini;
    }
};