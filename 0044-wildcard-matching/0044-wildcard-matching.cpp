class Solution {
public:
int solve(int i, int j, string& s, string& p, vector<vector<int>>&memo){
    if(i<0 && j<0)return true;
    if(j<0)return false;

    if(i<0){
        while(j>=0){
            if(p[j]!='*'){
                return false;
            }
            j--;
        }
        return true;
    }

    if(memo[i][j]!=-1)return memo[i][j];

    if(s[i]==p[j] || p[j] == '?'){
        return memo[i][j] = solve(i-1,j-1,s,p,memo);
    }

    if(p[j]=='*'){
        return memo[i][j] = solve(i,j-1,s,p,memo) || solve(i-1,j,s,p,memo);
    }

    return memo[i][j] = false;

}
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<int>>memo(n+1,vector<int>(m+1,-1));
        return solve(n-1,m-1,s,p,memo);
    }
};