class Solution {
public:
    long long gcd(long long a, long long b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }

    long long lcm(long long a, long long b) {
        return (a / gcd(a, b)) * b;
    }

    long long count(long long mid, vector<int>& coins) {
        int n = coins.size();
        long long pos = 0;

        // All subsets of coins
        for (int mask = 1; mask < (1 << n); mask++) {

            long long L = 1;
            int bits = 0;
            bool valid = true;

            for (int i = 0; i < n; i++) {

                if (mask & (1 << i)) {
                    bits++;

                    L = lcm(L, coins[i]);

                    // L is already greater than mid
                    if (L > mid) {
                        valid = false;
                        break;
                    }
                }
            }

            if (!valid) continue;

            if (bits % 2 == 1)
                pos += mid / L;
            else
                pos -= mid / L;
        }

        return pos;
    }

    long long findKthSmallest(vector<int>& coins, int k) {

        long long start = 1;
        long long end = LLONG_MAX;

        while (start <= end) {

            long long mid = start + (end - start) / 2;

            long long pos = count(mid, coins);

            if (pos >= k)
                end = mid - 1;
            else
                start = mid + 1;
        }

        return start;
    }
};