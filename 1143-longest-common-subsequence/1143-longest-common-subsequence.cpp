class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size();
        int n2 = text2.size();
        vector<vector<int>> memo(n1 + 1, vector<int>(n2 + 1, 0));

        for (int i = 0; i < n1; i++) {
            memo[i][0] = 0;
        }
        for (int j = 0; j < n2; j++) {
            memo[0][j] = 0;
        }

        for (int i = 0; i <= n1; i++) {
            for (int j = 0; j <= n2; j++) {
                if (i != 0 && j != 0) {
                    if (text1[i - 1] == text2[j - 1]) {
                        memo[i][j] = 1 + memo[i - 1][j - 1];
                    } else {
                        memo[i][j] = max(memo[i - 1][j], memo[i][j - 1]);
                    }
                }
            }
        }

        return memo[n1][n2];
    }
};