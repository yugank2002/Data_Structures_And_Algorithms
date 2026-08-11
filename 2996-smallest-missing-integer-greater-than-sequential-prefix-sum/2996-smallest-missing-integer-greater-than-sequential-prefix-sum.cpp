class Solution {
public:
    int missingInteger(vector<int>& nums) {
        unordered_map<int, int> mp;

        for (int elem : nums) {

            if (mp.find(elem) == mp.end())
                mp[elem]++;
        }

        auto curr = 1;

        int num;

        int sum = nums[0];
        while (curr < nums.size()) {
            if (nums[curr - 1] + 1 == nums[curr]) {
                sum += nums[curr];
                curr++;
            }
            else
            break;

            
        }

        while (mp[sum] > 0) {
            sum++;
        }

        return sum;
    }
};