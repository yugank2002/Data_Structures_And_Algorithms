class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        set<int>st;
        for(int elem:nums){
            if(elem>0){
                st.insert(elem);
            }
        }
        int i = 1;
        auto curr = st.begin();
        while(curr!=st.end() && i==*curr ){
            i++;
            curr++;
        }

        return i;
    }
};