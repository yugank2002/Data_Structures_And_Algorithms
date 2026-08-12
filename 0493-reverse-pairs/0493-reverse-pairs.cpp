class Solution {
public:
 void merge(int start, int mid, int end, vector<int>&arr){
      int n = end-start+1;
      vector<int>temp;
      
      int i=start;
      int j = mid+1;
      
      while(i<=mid && j<=end){
          if(arr[i]<arr[j]){
              temp.push_back(arr[i]);
              i++;
          }
          else{
              temp.push_back(arr[j]);
              j++;
          }
      }
      
      while(i<=mid){
           temp.push_back(arr[i]);
              i++;
      }
      
      while(j<=end){
           temp.push_back(arr[j]);
              j++;
      }
      
      for(int i=0; i<n; i++){
          arr[i+start] = temp[i];
      }
      
      return;
  }

int solve(int start, int end, vector<int>&arr){
      if(start==end)return 0;
      
      int mid = start+(end-start)/2;
      
      int left = solve(start,mid,arr);
      int right = solve(mid+1,end,arr);
      
      int count = 0;
      int i=start;
      int j=mid+1;
      
      while(i<=mid && j<=end){
        long long tar = 2*(long long)arr[j];
          if(arr[i]>tar){
              count += mid-i+1;
              j++;
          }
          else{
              i++;
          }
      }
      
      merge(start,mid,end,arr);
      
      return left+right+count;
  }
    int reversePairs(vector<int>& nums) {
        return solve(0,nums.size()-1,nums);
    }
};