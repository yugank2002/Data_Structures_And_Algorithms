class Solution {
public:
void dfs(int node, vector<bool>&sus, vector<vector<int>>&adj){
    sus[node] = true;
    for(int neigh:adj[node]){
        if(!sus[neigh]){
            dfs(neigh,sus,adj);
        }
    }
}

bool dfs2(int node, vector<bool>&sus, vector<bool>&visited, vector<vector<int>>&adj){
    if(sus[node])return true;
    visited[node] = true;

    for(int neigh:adj[node]){
        if(!visited[neigh]){
            if(dfs2(neigh,sus,visited,adj))return true;
        }
    }

    return false;
}

    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<bool>sus(n,false);
        vector<vector<int>>adj(n);
        for(auto elem:invocations){
            adj[elem[0]].push_back(elem[1]);
        }

        dfs(k,sus,adj);

        vector<bool>visited(n,false);
        vector<int>ans;

        for(int i=0; i<n; i++){
            if(!sus[i] && !visited[i]){
                if(dfs2(i,sus,visited,adj)){
                    for(int i=0; i<n; i++){
                        ans.push_back(i);
                        
                    }
                    return ans;
                }
            }
        }

        for(int i=0; i<n; i++){
            if(!sus[i]){
                ans.push_back(i);
            }
        }

        return ans;
    }
};