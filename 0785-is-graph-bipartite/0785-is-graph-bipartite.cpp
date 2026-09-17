class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        queue<int> q;
        vector<int> flag(n, -1);

        vector<int> visited(n, false);

        for (int i = 0; i < n; i++) {
            if (visited[i])
                continue;

            visited[i] = true;
            q.push(i);
            flag[i] = 0;

            while (!q.empty()) {
                int node = q.front();
                q.pop();

                for (int neigh : graph[node]) {
                    if (flag[neigh] == flag[node])
                        return false;

                    if (!visited[neigh]) {
                        flag[neigh] = 1 - flag[node];
                        visited[neigh] = true;
                        q.push(neigh);
                    }
                }
            }
        }

        return true;
    }
};