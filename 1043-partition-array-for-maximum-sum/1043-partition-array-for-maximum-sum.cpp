class Solution {
public:
    int solve(int i, int k, vector<int>& arr) {
        if (i >= arr.size())
            return 0;

        int maxi = INT_MIN;
        int lSum = INT_MIN;
        for (int j = 0; j + i < arr.size() && j < k; j++) {
            maxi = max(maxi, arr[j + i]);
            int cost = maxi * (j + 1) + solve(i + j + 1, k, arr);
            lSum = max(lSum, cost);
        }

        return lSum;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        //return solve(0, k, arr);

        vector<int> memo(n+1, 0);

        for (int i = n - 1; i >= 0; i--) {
            int maxi = INT_MIN;
            int lSum = INT_MIN;
            for (int j = 0; j + i < arr.size() && j < k; j++) {
                maxi = max(maxi, arr[j + i]);
                int cost = maxi * (j + 1) + memo[i + j + 1];
                lSum = max(lSum, cost);
            }

            memo[i] =  lSum;
        }

        return memo[0];
    }
};