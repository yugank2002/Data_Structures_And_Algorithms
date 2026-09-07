#define MOD 1000000007
class Solution {
public:
    int distinctSubseqII(string s) {
        vector<int>freq(26,0);
        int total = 0;
        for(char c:s){
            int count = ((total+1)-freq[c-'a'] + MOD)%MOD;
            total+=count;
            total%=MOD;
            freq[c-'a']+=count;
            freq[c-'a']%=MOD;
        }

        return total;
    }
};