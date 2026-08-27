/*
lets say there is a word and we want to push some characters into it to make it palindrome
so first calculate that how many charcters in the word can form the largest palindrome 
after that we can push the left characters wo are not contributing to the longest palindrom subsequence
subsequence coz there is no requirement of strict arrangement , we can push characters to any place.
So now we just have to find the longest palindromic subsequence and for that we revrese the ord and try to find out the longet common subsequence in the both words. and at last we will get the result by n-lcs
*/
class Solution {
public:

    int minInsertions(string s) {
        int n = s.size();
        vector<vector<int>>memo(n+1,vector<int>(n+1,0));

        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(s[i-1]==s[n-j]){
                    memo[i][j] = 1+memo[i-1][j-1];
                }
                else{
                    memo[i][j] = max(memo[i-1][j],memo[i][j-1]);
                }
                
            }
        }

        return n-memo[n][n];

    }
};