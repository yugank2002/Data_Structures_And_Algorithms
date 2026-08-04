class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto &elem:times){
            adj[elem[0]].push_back({elem[1],elem[2]});
        }

        priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
        >pq;

        pq.emplace(0,k);
        int maxi = INT_MIN;

        vector<int>dist(n+1,INT_MAX);
        dist[k]= 0;
        

        while(!pq.empty()){
            int weight = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if(weight>dist[node])continue;

            
            

            for(auto &[v,w]:adj[node]){
                if(dist[v]>weight+w){
                    dist[v] = weight+w;
                    pq.emplace(weight+w,v);
                }
                
            }

        }

        for(int i=1; i<=n; i++){
            if(dist[i]==INT_MAX)return -1;
            maxi = max(maxi,dist[i]);
        }

        return maxi;
    
    }
};