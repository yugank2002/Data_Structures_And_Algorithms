class Solution {
public:
void bfs(int i,int j, vector<vector<int>>&grid){
    queue<pair<int,int>>q;
    int row[4] = {-1,1,0,0};
    int col[4] = {0,0,-1,1};
    q.push({i,j});
    grid[i][j] = 0;

    while(!q.empty()){
        auto [ci,cj] = q.front();
        q.pop();

        for(int k=0; k<4; k++){
            int ni = ci+row[k];
            int nj = cj+col[k];

            if(ni>=0 && ni<grid.size() && nj>=0 && nj<grid[0].size() && grid[ni][nj]==1){
                grid[ni][nj] = 0;
                q.push({ni,nj});
            }
        }
    }
}
    int numEnclaves(vector<vector<int>>& grid) {
        for(int i=0; i<grid.size(); i++){
            if(grid[i][0]==1){
                bfs(i,0,grid);

            }
            if(grid[i][grid[0].size()-1]==1){
                bfs(i,grid[0].size()-1,grid);
            }
        }

        for(int j=0; j<grid[0].size(); j++){
            if(grid[0][j]==1){
                bfs(0,j,grid);
            }
            if(grid[grid.size()-1][j]==1){
                bfs(grid.size()-1,j,grid);
            }
        }

        int count = 0;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j]==1)count++;
            }
        }

        return count;
    }
};