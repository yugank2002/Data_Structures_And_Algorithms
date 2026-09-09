class Solution {
public:
    bool isPalindrome(int i, int j, string& s) {
        while (i < j) {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    int solve(int i, int j, string& s, vector<vector<int>>& memo) {
        if (i > j) {
            return -1;
        }

        if (memo[i][j] != -1)
            return memo[i][j];

        int mini = INT_MAX;
        for (int k = i; k <= j; k++) {
            if (isPalindrome(i, k, s)) {
                int cut = solve(k + 1, j, s, memo);
                mini = min(mini, cut);
            }
        }

        return memo[i][j] = mini + 1;
    }
    int minCut(string s) {
        int n = s.size();
        vector<vector<int>> memo(n+1, vector<int>(n+1, -1));
        //return solve(0, n - 1, s, memo);

        for (int i = n - 1; i >= 0; i--) {
            
                
                int mini = INT_MAX;
                for (int k = i; k <n; k++) {
                    if (isPalindrome(i, k, s)) {
                        int cut = memo[k + 1][n-1];
                        mini = min(mini, cut);
                    }
                }

                memo[i][n-1] = mini + 1;
            
        }

        return memo[0][n-1];
    }
};