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

        vector<bool>visited(n+1,false);
        visited[0] = true;

        while(!pq.empty()){
            int weight = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if(visited[node])continue;

            visited[node] = true;
            maxi = max(maxi,weight);

            for(auto [v,w]:map[node]){
                pq.push({weight+w,v});
            }

        }

        for(bool flag:visited){
            if(!flag)return -1;
        }

        return maxi;
    
    }
};