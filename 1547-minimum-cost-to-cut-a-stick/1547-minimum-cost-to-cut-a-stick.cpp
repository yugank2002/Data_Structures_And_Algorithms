class Solution {
public:
int solve(int i, int j, vector<int>&cuts, vector<vector<int>>&memo){
    if(i>j)return 0;

    if(memo[i][j]!=-1)return memo[i][j];

    int mini = INT_MAX;
    for(int k=i; k<=j; k++){
        int cut = cuts[j+1]-cuts[i-1] + solve(i,k-1,cuts,memo)+solve(k+1,j,cuts,memo);
        mini= min(mini,cut);
    }

    return memo[i][j] = mini;
}
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(),cuts.end());
        cuts.insert(cuts.begin(),0);
        cuts.push_back(n);
        int size = cuts.size();
        vector<vector<int>>memo(size,vector<int>(size,-1));
        return solve(1,cuts.size()-2,cuts,memo);
        

    }
};