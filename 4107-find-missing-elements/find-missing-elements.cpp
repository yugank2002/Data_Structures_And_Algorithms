class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end(), greater<int>());
        int low = nums[n - 1];
        int high = nums[0];

        stack<int> st;
        for (int elem : nums) {
            st.push(elem);
        }
        vector<int> ans;
        for (int i = low; i <= high; i++) {
            if (st.top() == i)
                st.pop();

            else {
                ans.push_back(i);
            }
        }
        return ans;
    }
};