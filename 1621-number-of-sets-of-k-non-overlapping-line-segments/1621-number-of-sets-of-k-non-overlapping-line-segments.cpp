#define mod 1000000007
class Solution {
public:
    int solve(int i, int n, int k) {
        if (k == 0)
            return 1;
        if (i == n)
            return 0;

        int skip = solve(i + 1, n, k);
        int take = 0;
        for (int j = i + 1; j < n; j++) {
            take += solve(j, n, k - 1);
        }

        return skip + take;
    }
    int numberOfSets(int n, int k) {
        // return solve(0,n,k);
        vector<vector<int>> memo(n + 1, vector<int>(k + 1, 0));

        for (int i = 0; i <= n; i++) {
            memo[i][0] = 1;
        }

        for (int K = 1; K <= k; K++) {
            int take = 0;
            for (int i = n - 1; i >= 0; i--) {

                int skip = memo[i + 1][K];
                memo[i][K] = (skip + take)%mod;

                take += memo[i][K - 1];
                take %= mod;
            }
        }

        return memo[0][k];
    }
};