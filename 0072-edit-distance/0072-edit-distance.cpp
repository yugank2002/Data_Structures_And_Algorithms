class Solution {
public:

    int minDistance(string word1, string word2) {
       
        int n = word1.size();
        int m = word2.size();

        vector<vector<int>>memo(n+1,vector<int>(m+1,0));

        for(int i=0; i<=n; i++){
            memo[i][0] = i;
        }
        for(int j=0; j<=m; j++){
            memo[0][j] = j;
        }

        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(word1[i-1]==word2[j-1]){
                    memo[i][j] = memo[i-1][j-1];
                }
                else{
                    int replace = memo[i-1][j-1];
  
                    int del = memo[i-1][j];

                    int ins = memo[i][j-1];

                    memo[i][j] =  1+ min({replace,del,ins});
                }
            }
        }

        return memo[n][m];
    }
};