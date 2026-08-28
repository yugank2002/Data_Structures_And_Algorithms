class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();

        vector<vector<long long>> memo(n + 1, vector<long long>(m + 1, 0));
        for (int i = 0; i <= n; i++) {
            memo[i][0] = 1;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                long long take = 0;
                if (s[i - 1] == t[j - 1]) {
                    take = memo[i - 1][j - 1];
                }
                long long notTake = memo[i - 1][j];
                if(take > INT_MAX-notTake){
                    memo[i][j] = INT_MAX;
                    continue;
                }
                memo[i][j] = (take + notTake);
            }
        }

        return memo[n][m];
    }
};