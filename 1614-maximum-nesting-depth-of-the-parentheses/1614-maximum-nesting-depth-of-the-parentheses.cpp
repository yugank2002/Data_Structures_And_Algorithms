class Solution {
public:
    int maxDepth(string s) {
       
        int count = 0;
        int curr=0;
        for(char c:s){
            if(c=='('){
                curr++;
                count = max(count,curr);
            }
            else if(c==')'){
                curr--;
            }
        }

        return count;
    }
};