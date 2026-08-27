class Solution {
public:
int n;
string solve(int i, map<char,int>&mp,string& s){
    if(i==n-1){
        for(auto &it:mp){
            if(it.first>s[i] && it.second>0){
                string ans(1,it.first);
                it.second--;
                return ans;
            }
        }
        return "";
    }

    if(mp.find(s[i])!=mp.end() && mp[s[i]]>0){
        mp[s[i]]--;
        string equal = solve(i+1,mp,s);
        mp[s[i]]++;
        if(!equal.empty()){
            return s[i]+equal;
        }
        
    }
    
    string ans="";
    for(auto &it:mp){
        if(it.first>s[i] && it.second>0){
            ans+=it.first;
            it.second--;
            break;
        }
    }
    if(ans.empty()){
        return "";
    }
    for(auto &it:mp){
        while(it.second>0){
            ans+=it.first;
            it.second--;
        }
    }
    return ans;
}
    string lexGreaterPermutation(string s, string target) {
        n = s.size();
        map<char,int>mp;
        for(int elem:s){
            mp[elem]++;
        }

        return solve(0,mp,target);

    }
};