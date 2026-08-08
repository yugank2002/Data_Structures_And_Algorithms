class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        vector<int>last(word2.size()+1,-1);
        last[last.size()-1] = 1e8;
        int i=word1.size()-1;
        int j = word2.size()-1;
        while(i>=0 && j>=0){
            if(word1[i]==word2[j]){
                last[j] = i;
                j--;

            }
            i--;
            
        }

        vector<int>ans;
        bool flag = false;
        i=0;
        j=0;
        while(i<word1.size() && j<word2.size()){
            if(word1[i]==word2[j]){
                ans.push_back(i);
                
                j++;
            }
            else{
                if(!flag && i+1<=last[j+1]){
                    flag = true;
                    ans.push_back(i);
                
                    j++;
                }
            }
            i++;
        }

        if(ans.size()==word2.size())return ans;

        return {};
    }
};