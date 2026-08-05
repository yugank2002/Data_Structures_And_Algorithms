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



    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<bool>sus(n,false);
        vector<vector<int>>adj(n);
        for(auto elem:invocations){
            adj[elem[0]].push_back(elem[1]);
        }

        dfs(k,sus,adj);

        vector<bool>visited(n,false);
        vector<int>ans;

        for(auto elem:invocations){
            if(!sus[elem[0]] && sus[elem[1]]){
                for(int i=0; i<n; i++){
                    ans.push_back(i);

                }
                return ans;
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