class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<char,int>mp;
        for(char c:s){
            mp[c] = 0;
        }
        int curr = 0;
        int prev = 0;
        int size = 0;
        while(curr<s.size()){
            mp[s[curr]]++;
            while(mp[s[curr]]>2 && prev<curr){
                mp[s[prev]]--;
                prev++;
            }

            size = max(size,curr-prev+1);
            curr++;
        }

        return size;
    }
};