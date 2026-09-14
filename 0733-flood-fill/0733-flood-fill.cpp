class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc]==color)return image;
        int oldCol = image[sr][sc];
        int n = image.size();
        int m = image[0].size();

        int row[4] = {-1,1,0,0};
        int col[4] = {0,0,-1,1};

        queue<pair<int,int>>q;
        q.push({sr,sc});
        image[sr][sc] = color;

        while(!q.empty()){
            auto [i,j] = q.front();
            q.pop();

            

            for(int k=0; k<4; k++){
                int ni = i+row[k];
                int nj = j+col[k];

                if(ni>=0 && ni<n && nj>=0 && nj<m && image[ni][nj]==oldCol){
                    image[ni][nj] = color;
                    q.push({ni,nj});
                }
            }
        }

        return image;
    }
};