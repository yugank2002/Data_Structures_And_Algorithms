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

void bfs(int node, vector<int>&dist, vector<vector<int>>&parent, unordered_map<int,vector<int>>&adj){
    dist[node] = 0;
    queue<int>q;
    q.push(node);

    while(!q.empty()){
        int n = q.front();
        q.pop();

        for(int neigh:adj[n]){
            if(dist[neigh]==1+dist[n]){
                parent[neigh].push_back(n);
            }
            else if(dist[neigh]>1+dist[n]){
                parent[neigh].push_back(n);
                dist[neigh] = 1+dist[n];
                q.push(neigh);
            }
        }
    }
}

void makeAns(int node, vector<vector<int>>&parent, vector<int>&temp, vector<vector<string>>&ans, vector<string>&wordList){
    if(node==0){
        vector<string>curr;
        curr.push_back(wordList[0]);
        for(int i=temp.size()-1; i>=0; i--){
            curr.push_back(wordList[temp[i]]);
        }
        ans.push_back(curr);
        return;
    }

    temp.push_back(node);
    for(int n:parent[node]){
        makeAns(n,parent,temp,ans,wordList);
    }
    temp.pop_back();
    return;
}


    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();
        int d = diff(beginWord,endWord);
        vector<vector<string>>ans;
        if(n<d)return ans;
        
        int dest = -1;
        for(int i=0; i<n; i++){
            if(wordList[i]==endWord){
                
                dest = i;
            }
        }
        if(dest==-1)return ans;

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

        
        vector<int>temp;
        vector<int>dist(n,1e8);
        vector<vector<int>>parent(n);

        bfs(0,dist,parent,adj);

        
        

        makeAns(dest+1,parent,temp,ans,wordList);

        cout<<wordList[dest+1]<<endl;


        return ans;
    }
};