class Solution {
public:
    int dp[101][102];

    bool solve(int i, int balance, string& s) {

        if (balance < 0) return false;

        if (i == s.size()) {
            return balance == 0;
        }

        if (dp[i][balance] != -1)
            return dp[i][balance];

        bool ans = false;

        if (s[i] == '(') {
            ans = solve(i + 1, balance + 1, s);
        }

        else if (s[i] == ')') {
            ans = solve(i + 1, balance - 1, s);
        }

        else {
            // * as empty
            ans = solve(i + 1, balance, s);

            // * as (
            if (!ans)
                ans = solve(i + 1, balance + 1, s);

            // * as )
            if (!ans)
                ans = solve(i + 1, balance - 1, s);
        }

        return dp[i][balance] = ans;
    }

    bool checkValidString(string s) {
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, s);
    }
};