class Solution {
public:
int n;
int m;
bool solve(int i, int j, int openCount, vector<vector<char>>&grid, vector<vector<vector<int>>>&memo){
    if(i>=n || j>=m)return false;

    char paran = grid[i][j];
    if(paran=='(')openCount++;

    if(i+j+1>2*openCount)return false;

    if(i==n-1 && j==m-1){
        return openCount==i+j+1-openCount;
    }

    if(memo[i][j][openCount]!=-1)return memo[i][j][openCount];

    if(solve(i,j+1,openCount,grid,memo)){
        return memo[i][j][openCount] = true;
    }

    return memo[i][j][openCount] = solve(i+1,j,openCount,grid,memo);


    


}
    bool hasValidPath(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();
        vector<vector<vector<int>>>memo(n,vector<vector<int>>(m,vector<int>(n+m,-1)));
        return solve(0,0,0,grid,memo);
    }
};