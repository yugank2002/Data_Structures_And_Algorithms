class Solution {
public:
bool isPalindrome(int i, int j, int k, string& s){
    vector<int>index;
    while(j-i+1 >= k ){
        if(s[i]==s[j]){
            index.push_back(i);
        }
        i++;
    }
    

    for(int ind:index){
        bool flag = true;
        int jind = j;
         while(ind<j){
            if(s[ind]!=s[jind]){
                flag = false;
                break;
            }
            ind++;
            jind--;
        }
        if(flag){
            return true;
        }
    }

   

    return false;
}
    int maxPalindromes(string s, int k) {
        int n = s.size();
        vector<int>memo(n,0);
        int prev = -1;

        for(int i=0; i<n; i++){
            if(i-prev >= k){
                if(isPalindrome(prev+1,i,k,s)){
                    memo[i] = i==0?1:memo[i-1]+1;
                    prev = i;
                }
                else{
                    memo[i] = i==0?0:memo[i-1];
                }
            }
            else{
                memo[i] = i==0?0:memo[i-1];
            }
        }

       for(int e:memo){
        cout<<e<<" ";
       }
       cout<<endl;

        return memo[n-1];

    }
};