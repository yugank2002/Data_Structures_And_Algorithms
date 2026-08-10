class Solution {
public:
int help(int n, vector<int>&memo){
    if(n<=0)return 0;

    if(memo[n]!=-1)return memo[n];
        for(int i=1; i*i<=n; i++ ){
            if(help(n-i*i,memo)==0)return memo[n] = 1;
        }

        return memo[n] = 0;
}
    bool winnerSquareGame(int n) {
        vector<int>memo(n+1, -1);
        return help(n,memo);
    }
};