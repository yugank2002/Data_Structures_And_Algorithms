class Solution {
public:
int solve(vector<int>&arr){
    int n = arr.size();
    vector<int>next(n,n);
    vector<int>prev(n,-1);

    stack<int>st;
    for(int i=0; i<n; i++){
        while(!st.empty() && arr[i]<arr[st.top()]){
            next[st.top()] = i;
            st.pop();

        }
        st.push(i);
    }
    stack<int>st2;
    for(int i=n-1; i>=0; i--){
        while(!st2.empty() && arr[i]<arr[st2.top()]){
            prev[st2.top()] = i;
            st2.pop();

        }
        st2.push(i);
    }

    int ans = 0;
    for(int i=0; i<n; i++){
        int area = arr[i] * (next[i]-prev[i]-1);
        ans = max(area,ans);
    }

    return ans;
    
}
    int maximalRectangle(vector<vector<char>>& matrix) {
        int maxi =0;
        int n = matrix[0].size();
        vector<int>arr(n,0);
        for(int i=0; i<matrix.size(); i++){
            
            for(int j=0; j<n; j++){
                if(matrix[i][j]=='1'){
                    arr[j]+=1;
                }
                else{
                    arr[j] = 0;
                }
            }

            maxi = max(maxi,solve(arr));

        }

        return maxi;
    }
};