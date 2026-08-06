class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
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