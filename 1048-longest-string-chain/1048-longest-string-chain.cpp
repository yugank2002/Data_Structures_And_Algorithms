class Solution {
public:
bool solve(string str1, string str2){
    int n1 = str1.size();
    int n2 = str2.size();
    if(n2-n1 != 1)return false;

    bool mismatch = false;
    int i=0;
    int j=0;
    while(i<n1 && j<n2){
        if(str1[i]!=str2[j] && !mismatch){
            mismatch=true;
            j++;
        }
        else if(str1[i]!=str2[j] && mismatch){
            return false;
        }
        else{
            i++;
            j++;
        }
        
    }

    return true;
}
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(), [](auto &a, auto& b){
            if(a.size()==b.size()){
                return a<b;
            }
            return a.size()<b.size();
        });

        int n = words.size();
        unordered_map<int,vector<int>>mp;
        for(int i=0; i<n; i++){
            mp[words[i].size()].push_back(i);
        }
        
        vector<int>dp(n,1);
        int maxi = 1;
        for(int i=1; i<n; i++){
            for(auto j:mp[words[i].size()-1]){
                if(solve(words[j],words[i])){
                    dp[i] = max(dp[i],1+dp[j]);
                    
                }
            }
            maxi =max(dp[i],maxi);
        }
        return maxi;
    }
};