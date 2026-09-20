class Solution {
public:
    int reverseDegree(string s) {
        int ans = 0;
        for(int i=1; i<=s.size(); i++){
            char c = s[i-1];
            ans += (26-(c-'a'))*i;
        }
        return ans;
    }
};