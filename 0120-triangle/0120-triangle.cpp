class Solution {
public:
int solve(int i, int j, vector<vector<int>>& triangle, vector<vector<int>>&memo){
    if(i==triangle.size()-1)return triangle[i][j];

    if(memo[i][j]!=INT_MAX)return memo[i][j];

    int down = solve(i+1,j,triangle,memo);
    int nextDown = solve(i+1,j+1,triangle,memo);

    return memo[i][j] = triangle[i][j] + min(down,nextDown);
}
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>>memo(n,vector<int>(n,INT_MAX));
        return solve(0,0,triangle,memo);
    }
};