class Solution {
public:

    int findPeakElement(vector<int>& arr){
        if(arr.size()==1)return 0;
        if(arr.size()==2){
            return (arr[0]>arr[1])?0:1;
    }
        int start = 0;
        int end = arr.size()-1;

        while(start<=end){
            int mid = start+(end-start)/2;

            if((mid==0 || arr[mid-1]<=arr[mid] ) && (mid == arr.size()-1 || arr[mid]>=arr[mid+1])){
                return mid;
            }

            if(arr[mid+1]>arr[mid]){
                start = mid+1;
            }
            else{
                end = mid-1;
            }

        }
        return 0;
    }
};