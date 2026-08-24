class Solution {
public:
int solve(int i, int j, string& text1, string& text2, vector<vector<int>>&memo){
    
    if(i==text1.size() || j==text2.size()){
        return 0;
    }

    if(memo[i][j]!=-1)return memo[i][j];

    if(text1[i]==text2[j]){
        return memo[i][j] = 1+solve(i+1,j+1,text1,text2,memo);
    }

    

    int skip1 = solve(i+1,j,text1,text2,memo);
    int skip2 = solve(i,j+1,text1,text2,memo);

    return memo[i][j] = max(skip1,skip2);
}
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size();
        int n2 = text2.size();
        vector<vector<int>> memo(n1 + 1, vector<int>(n2 + 1, -1));

        return solve(0,0,text1,text2,memo);
        
    }
};