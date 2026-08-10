class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int start=1;
        int end = INT_MIN;
        for(int elem:quantities){
            end = max(end,elem);
        }

        int save;
        while(start<=end){
            int mid = start+(end-start)/2;
            int count=0;

            for(int elem:quantities){
                count+=elem/mid;
                count+= (elem%mid)?1:0;
            }

            if(count<=n){
                save=mid;
                end = mid-1;
            }
            else{
                start=mid+1;
            }
        }

        return save;
    }
};