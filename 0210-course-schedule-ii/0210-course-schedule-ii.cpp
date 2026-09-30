class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        unordered_map<int, vector<int>> adj;

        for (auto elem : prerequisites) {
            adj[elem[1]].push_back(elem[0]);
            indegree[elem[0]]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        

        
        vector<int> ans;

            while (!q.empty()) {
                int n = q.front();
                q.pop();
                ans.push_back(n);

                for (auto neigh : adj[n]) {
                    indegree[neigh]--;
                    if (indegree[neigh]==0) {
                        q.push(neigh);
                        
                    }
                }
            }
        

        
        if(ans.size()!=numCourses)return {};

        return ans;
    }
};