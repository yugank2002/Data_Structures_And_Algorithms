class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        vector<pair<int,int>>mat1;
        vector<pair<int,int>>mat2;

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(img1[i][j]==1){
                    mat1.push_back({i,j});
                }
                if(img2[i][j]==1){
                    mat2.push_back({i,j});
                }
            }
        }

        vector<vector<int>>ans(2*n,vector<int>(2*n,0));
        
        for(int i=0; i<mat1.size(); i++){
            for(int j=0; j<mat2.size(); j++){
                int r = mat2[j].first-mat1[i].first;
                int c = mat2[j].second-mat1[i].second;
                ans[r+n][c+n]++;
            }
        }

        int maxi = 0;
        for(int i=0; i<ans.size(); i++){
            for(int j=0; j<ans.size(); j++){
                maxi = max(maxi,ans[i][j]);
            }
        }

        return maxi;
    }
};