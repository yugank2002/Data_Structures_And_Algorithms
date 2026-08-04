class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>map(n+1);
        for(auto elem:times){
            map[elem[0]].push_back({elem[1],elem[2]});
        }

        priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
        >pq;

        pq.push({0,k});
        int maxi = INT_MIN;

        vector<int>dist(n+1,1e8);
        dist[k]= 0;
        

        while(!pq.empty()){
            int weight = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if(weight>dist[node])continue;

            
            maxi = max(maxi,weight);

            for(auto [v,w]:map[node]){
                if(dist[v]>weight+w){
                    dist[v] = weight+w;
                    pq.push({weight+w,v});
                }
                
            }

        }

        for(int i=1; i<=n; i++){
            if(dist[i]==1e8)return -1;
        }

        return maxi;
    
    }
};