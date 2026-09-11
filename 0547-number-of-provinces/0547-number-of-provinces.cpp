class Solution {
public:
int findParent(int node, vector<int>&parent){
    if(node==parent[node]){
        return node;
    }

    return parent[node] = findParent(parent[node],parent);
}
void connect(int i, int j, vector<int>&parent){

    int pu = findParent(i,parent);
    int pv = findParent(j,parent);

    if(pu==pv)return;

    parent[pv] = pu;
    return;
}
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int>parent(n);
        for(int i=0; i<n; i++){
            parent[i] = i;
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(isConnected[i][j])
                connect(i,j,parent);
            }
        }

        int count = 0;
        for(int i=0; i<n; i++){
            if(i == findParent(i,parent)){
                count++;
            }
        }
        return count;
    }
};