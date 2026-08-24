class Solution {
public:
int solve(int i, vector<int>&pref, vector<int>&memo){
    if(i == pref.size()-1){
        return pref[i];
    }

    if(memo[i]!=INT_MIN) return memo[i];
    int take = pref[i] - solve(i+1,pref,memo);
    int skip = solve(i+1,pref,memo);

    return memo[i] = max(take,skip);

}
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();
        vector<int>pref(n);
        pref[0] = stones[0];
        for(int i=1; i<n; i++){
            pref[i] = pref[i-1]+stones[i];
        }

        vector<int>memo(n,INT_MIN);

        return solve(1,pref,memo);
    }
};