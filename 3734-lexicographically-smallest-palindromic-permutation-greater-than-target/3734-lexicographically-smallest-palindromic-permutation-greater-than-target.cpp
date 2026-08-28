class Solution {
public:
    int n;
    char single = '\0';

    string makePalindrome(string &half) {
        string ans = half;

        if (single != '\0')
            ans += single;

        string rev = half;
        reverse(rev.begin(), rev.end());

        ans += rev;

        return ans;
    }

    string solve(int i, map<char, int>& mp, string& target, string& half) {

        // We have constructed the complete first half
        if (i == n) {
            string ans = makePalindrome(half);

            if (ans > target)
                return ans;

            return "";
        }

        // ------------------------------------------------
        // 1. Try to keep the current character equal
        // ------------------------------------------------
        if (mp[target[i]] > 0) {

            mp[target[i]]--;
            half.push_back(target[i]);

            string res = solve(i + 1, mp, target, half);

            if (!res.empty())
                return res;

            // Backtrack
            half.pop_back();
            mp[target[i]]++;
        }

        // ------------------------------------------------
        // 2. Try the smallest character greater than target[i]
        // ------------------------------------------------
        for (auto& it : mp) {

            if (it.first > target[i] && it.second > 0) {

                char c = it.first;

                mp[c]--;
                half.push_back(c);

                // Fill remaining positions with smallest chars
                string remaining = half;

                for (auto& x : mp) {
                    while (x.second > 0) {
                        remaining.push_back(x.first);
                        x.second--;
                    }
                }

                // Construct palindrome
                string ans = remaining;

                if (single != '\0')
                    ans += single;

                string rev = remaining;
                reverse(rev.begin(), rev.end());

                ans += rev;

                // Restore map before returning
                for (auto& x : mp) {
                    // restore later using remaining difference
                }

                // Instead of complicated restoration,
                // restore all counts from the constructed half.
                for (char ch : remaining) {
                    mp[ch]++;
                }

                mp[c]++;
                half.pop_back();

                if (ans > target)
                    return ans;

                // Only the smallest greater character is needed.
                // Larger characters will produce larger answers.
                break;
            }
        }

        return "";
    }

    string lexPalindromicPermutation(string s, string target) {

        // Count characters
        map<char, int> mp;

        for (char c : s)
            mp[c]++;

        // Check whether a palindrome is possible
        int odd = 0;
        single = '\0';

        for (auto& it : mp) {

            if (it.second % 2) {
                odd++;
                single = it.first;
            }
        }

        if (odd > 1)
            return "";

        // We only need half of every frequency
        for (auto& it : mp)
            it.second /= 2;

        n = s.size() / 2;

        string half = "";

        return solve(0, mp, target, half);
    }
};