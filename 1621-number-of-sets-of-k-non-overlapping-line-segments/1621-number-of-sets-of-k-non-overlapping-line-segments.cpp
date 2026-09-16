#define mod 1000000007

class Solution {
public:
    int numberOfSets(int n, int k) {

        vector<vector<int>> memo(n + 1, vector<int>(k + 1, 0));

        for(int i = 0; i <= n; i++) {
            memo[i][0] = 1;
        }

        for(int K = 1; K <= k; K++) {

            long long suffix = 0;

            for(int i = n - 1; i >= 0; i--) {

                // Current suffix represents:
                // memo[i+1][K-1] + ... + memo[n-1][K-1]
                int take = suffix;

                int skip = memo[i+1][K];

                memo[i][K] = (skip + take) % mod;

                // Prepare suffix for the NEXT i
                suffix = (suffix + memo[i][K-1]) % mod;
            }
        }

        return memo[0][k];
    }
};