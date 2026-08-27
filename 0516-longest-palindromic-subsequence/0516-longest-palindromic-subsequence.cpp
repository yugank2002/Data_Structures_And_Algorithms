class Solution {
public:
int solve(int i, int j, string& s1, string& s2){
    if(i>=s1.size() || j>=s2.size())return 0;

    if(s1[i]==s2[j]){
        return 1+solve(i+1,j+1,s1,s2);
    }

    int skip1 = solve(i+1,j,s1,s2);
    int skip2 = solve(i,j+1,s1,s2);

    return max(skip1,skip2);
}
    int longestPalindromeSubseq(string s) {
        int n = s.size();
       
        
        vector<vector<int>>memo(n+1,vector<int>(n+1,0));
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(s[i-1] == s[n-j]){
                    memo[i][j] = 1+memo[i-1][j-1];
                }
                else{
                    int skip1 = memo[i-1][j];
                    int skip2 = memo[i][j-1];
                    memo[i][j] = max(skip1,skip2);
                }

                
            }
        }
        return memo[n][n];
    }
};