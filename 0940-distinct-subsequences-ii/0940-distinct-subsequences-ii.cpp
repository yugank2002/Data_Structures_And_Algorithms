#define MOD 1000000007
class Solution {
public:
    int distinctSubseqII(string s) {
        int n = s.size();
        vector<long long>dp(n+1,0);
        unordered_map<char,int>mp;
        for(int i=1; i<=n;i++){
            char c = s[i-1];
            if(mp.find(c)==mp.end()){
                dp[i] = (dp[i-1]*2 +1)%MOD;
                mp[c] = i;
            }
            else{
                int rep = dp[mp[c]-1];
                dp[i] = (dp[i-1]*2 -rep + MOD)%MOD;
                dp[i]%=MOD;
                mp[c] = i;
            }
        }

        return dp[n]%MOD;
    }
};