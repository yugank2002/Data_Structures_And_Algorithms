class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        vector<vector<int>>memo(n+1,vector<int>(m+1,0));

        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(str1[i-1]==str2[j-1]){
                    memo[i][j] = 1+memo[i-1][j-1];
                }
                else{
                    memo[i][j] = max(memo[i-1][j],memo[i][j-1]);
                }
            }
        }

        int i=n;
        int j=m;
        string ans = "";

        while(i>0 && j>0){
            if(str1[i-1]==str2[j-1]){
                ans+=str1[i-1];
                i--;
                j--;
            }
            else if(memo[i][j-1]==memo[i][j]){
                ans+=str2[j-1];
                j--;
            }
            else{
                ans+=str1[i-1];
                i--;
            }
        }

        while(j>0){
            ans+=str2[j-1];
            j--;
        }
        while(i>0){
            ans+=str1[i-1];
            i--;
        }

        reverse(ans.begin(),ans.end());

        return ans;
    }
};