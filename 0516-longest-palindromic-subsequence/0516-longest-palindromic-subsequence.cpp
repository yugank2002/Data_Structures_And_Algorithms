/*
since we have to find the palindrome sub sequence, if we make another string which is reversed of the original string then the problem will become to find longest common subsequence.
*/
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();

        vector<vector<int>> memo(n + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (s[i - 1] == s[n - j]) {
                    memo[i][j] = 1 + memo[i - 1][j - 1];
                } else {
                    int skip1 = memo[i - 1][j];
                    int skip2 = memo[i][j - 1];
                    memo[i][j] = max(skip1, skip2);
                }
            }
        }
        return memo[n][n];
    }
};