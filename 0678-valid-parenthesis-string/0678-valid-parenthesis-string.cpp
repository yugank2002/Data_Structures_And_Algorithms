class Solution {
public:
bool solve(int i, int open, int close, string& s, vector<vector<vector<int>>>&memo){
    if(i==s.size()){
        return open==close;
    }

    if(memo[i][open][close]!=-1)return memo[i][open][close];

    if(s[i]=='('){
        if(solve(i+1,open+1,close,s,memo)){
            return memo[i][open][close] = true;
        }
    }
    else if(s[i]==')' && close<open){
        if(solve(i+1,open,close+1,s,memo)){
            return memo[i][open][close] = true;
        }
    }
    else if(s[i]=='*'){
        if(solve(i+1,open,close,s,memo)){
            return memo[i][open][close] = true;
        }

        if(solve(i+1,open+1,close,s,memo)){
            return memo[i][open][close] = true;
        }

        if(close<open && solve(i+1,open,close+1,s,memo)){
            return memo[i][open][close] = true;
        }
    }

    return memo[i][open][close] = false;

}
    bool checkValidString(string s) {
        int n = s.size();
        vector<vector<vector<int>>>memo(n,vector<vector<int>>(n,vector<int>(n,-1)));
        return solve(0,0,0,s,memo);
    }
};