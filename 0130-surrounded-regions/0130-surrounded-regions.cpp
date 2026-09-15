class Solution {
public:
void bfs(int i,int j, vector<vector<char>>&grid){
    queue<pair<int,int>>q;
    int row[4] = {-1,1,0,0};
    int col[4] = {0,0,-1,1};
    q.push({i,j});
    grid[i][j] = '#';

    while(!q.empty()){
        auto [ci,cj] = q.front();
        q.pop();

        for(int k=0; k<4; k++){
            int ni = ci+row[k];
            int nj = cj+col[k];

            if(ni>=0 && ni<grid.size() && nj>=0 && nj<grid[0].size() && grid[ni][nj]=='O'){
                grid[ni][nj] = '#';
                q.push({ni,nj});
            }
        }
    }
}
    void solve(vector<vector<char>>& grid) {
         for(int i=0; i<grid.size(); i++){
            if(grid[i][0]=='O'){
                bfs(i,0,grid);

            }
            if(grid[i][grid[0].size()-1]=='O'){
                bfs(i,grid[0].size()-1,grid);
            }
        }

        for(int j=0; j<grid[0].size(); j++){
            if(grid[0][j]=='O'){
                bfs(0,j,grid);
            }
            if(grid[grid.size()-1][j]=='O'){
                bfs(grid.size()-1,j,grid);
            }
        }

        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j]=='#')grid[i][j]='O';
                else if(grid[i][j]=='O')grid[i][j] = 'X';
            }
        }

        return;
    }
};