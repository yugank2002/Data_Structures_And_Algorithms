class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<vector<int>>memo(n+1,vector<int>(m+1,0));

        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(word1[i-1]==word2[j-1]){
                    memo[i][j] = 1+memo[i-1][j-1];
                }
                else{
                    memo[i][j] = max(memo[i-1][j],memo[i][j-1]);
                }
            }
        }

       

        return n+m-2*memo[n][m];
    }
};