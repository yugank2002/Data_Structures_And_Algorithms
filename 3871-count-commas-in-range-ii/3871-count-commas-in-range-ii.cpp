class Solution {
public:
    long long countCommas(long long n) {
        long long sum = 0;
        if(n<1e3)return sum;
        if(n>=1e6){
            sum+= 1e6-1e3;
        }
        else{
            sum+=n-1e3+1;
            return sum;
        }

        if(n>=1e9){
            sum+= (1e9-1e6)*2;
        }
        else{
            sum+= (n-1e6+1)*2;
            return sum;
        }

        if(n>=1e12){
            sum+= (1e12-1e9)*3;
        }
        else{
            sum+= (n-1e9+1)*3;
            return sum;
        }

        if(n>=1e15){
            sum+= (1e15-1e12)*4;

        }
        else{
            sum+= (n-1e12+1)*4;
            
        }

        if(n>=1e15){
            sum+=5;
        }

        return sum;
    }
};