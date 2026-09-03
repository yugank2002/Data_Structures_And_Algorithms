class Solution {
public:
bool checkEven(vector<int>&arr){
    for(int elem:arr){
        if(elem%2){
            return false;
        }
    }
    return true;
}

bool checkOdd(vector<int>&arr){
    for(int elem:arr){
        if(!(elem%2)){
            return false;
        }
    }
    return true;
}
    bool uniformArray(vector<int>& nums1) {
        
        if(checkEven(nums1)||checkOdd(nums1)){
            return true;
        }

        
        int lo = INT_MAX;
        int le = INT_MAX;
        for(int elem:nums1){
            if(elem%2){
                
                lo = min(lo,elem);
            }
            else{
                
                le = min(le,elem);
            }
        }

       
        
        
        
        if(le-lo>=1)return true;
        

        return false;
    }
};