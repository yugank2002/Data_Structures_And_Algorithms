class Solution {
public:

    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(),cuts.end());
        cuts.insert(cuts.begin(),0);
        cuts.push_back(n);
        int size = cuts.size();
        
        vector<vector<int>>memo(size,vector<int>(size,0));

        for(int i=size-1; i>=1; i--){
            for(int j=1; j<size-1; j++){
                if(i>j)continue;
                int mini = INT_MAX;
                for(int k=i; k<=j; k++){
                    int cut = cuts[j+1]-cuts[i-1] + memo[i][k-1]+memo[k+1][j];
                    mini= min(mini,cut);
                }
                memo[i][j] = mini;
            }
        }

        return memo[1][size-2];
    }
};