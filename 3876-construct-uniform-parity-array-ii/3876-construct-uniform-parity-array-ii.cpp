class Solution {
public:
    bool uniformArray(vector<int>& nums1) {

        int lo = INT_MAX;
        int le = INT_MAX;
        for (int elem : nums1) {
            if (elem % 2) {

                lo = min(lo, elem);
            } else {

                le = min(le, elem);
            }
        }

        if (le == INT_MAX || lo == INT_MAX)
            return true;

        if (le - lo >= 1)
            return true;

        return false;
    }
};