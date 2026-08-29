class Solution {
public:
    int findParent(int node, vector<int>& parent) {
        if (node == parent[node])
            return node;

        return parent[node] = findParent(parent[node], parent);
    }
    void makeDSU(int u, int v, vector<int>& parent) {
        int pu = findParent(u, parent);
        int pv = findParent(v, parent);

        if (pu != pv) {
            parent[pv] = pu;
        }

        return;
    }
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> parent(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        vector<pair<int, int>> arr(n);
        for (int i = 0; i < n; i++) {
            arr[i] = {nums[i], i};
        }

        sort(arr.begin(), arr.end());

        for (int i = 1; i < n; i++) {

            if (abs(arr[i].first - arr[i - 1].first) <= limit) {
                makeDSU(arr[i].second, arr[i - 1].second, parent);
            }
        }

        unordered_map<int, priority_queue<int, vector<int>, greater<int>>> mp;

        for (int i = 0; i < n; i++) {
            mp[findParent(i, parent)].push(nums[i]);
        }

        vector<int> ans(n);

        for (int i = 0; i < n; i++) {
            int ind = findParent(i, parent);
            ans[i] = mp[ind].top();
            mp[ind].pop();
        }

        return ans;
    }
};