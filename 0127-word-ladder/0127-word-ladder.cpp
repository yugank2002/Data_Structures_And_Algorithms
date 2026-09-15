class Solution {
public:
int diff(string& str1, string& str2){
    int d = 0;
    for(int i=0; i<str1.size(); i++){
        if(str1[i]!=str2[i]){
            d++;
        }
    }

    return d;
}

int shortestDist(int d, int n, unordered_map<int,vector<int>>&adj ){
    vector<int>dist(n,1e8);
    dist[0] = 0;
    queue<int>q;
    q.push(0);

    while(!q.empty()){
        int node = q.front();
        q.pop();

        for(int neigh:adj[node]){
            if(dist[node]+1<dist[neigh]){
                dist[neigh] = dist[node]+1;
                q.push(neigh);
            }
        }
    }

    return dist[d];
}
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();
        int d = diff(beginWord,endWord);
        if(n<d)return 0;
        
        int dest = -1;
        for(int i=0; i<n; i++){
            if(wordList[i]==endWord){
                
                dest = i;
            }
        }
        if(dest==-1)return 0;

        wordList.insert(wordList.begin()+0,beginWord);
        n++;

        

        unordered_map<int,vector<int>>adj;
        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                int d = diff(wordList[i],wordList[j]);
                
                if(d==1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        

        int ans = shortestDist(dest+1,n,adj);

        return ans==1e8?0:ans+1;

        
    }
};