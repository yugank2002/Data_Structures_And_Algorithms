class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int row[4] = {-1,1,0,0};
        int col[4] = {0,0,-1,1};

        queue<pair<int,int>>q;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                }
            }
        }

        

        int count = -1;
        while(!q.empty()){
            int size = q.size();
            count++;
            while(size--){
                auto [i,j] = q.front();
                q.pop();

                for(int k=0; k<4; k++){
                    int ni = i+row[k];
                    int nj = j+col[k];

                    if(ni>=0 && ni<n && nj>=0 && nj<m && grid[ni][nj]==1){
                        grid[ni][nj] = 2;
                        q.push({ni,nj});
                    }
                }
            }
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1){
                    return -1;
                }
            }
        }

        return count==-1?0:count;
    }
};