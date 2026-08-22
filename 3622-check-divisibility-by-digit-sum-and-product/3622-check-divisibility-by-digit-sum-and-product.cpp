class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0;
        int prod = 1;
        int num = n;
        while(n){
            sum+=n%10;
            prod*=n%10;
            n/=10;

        }

        return num%(sum+prod)==0  ;
    }
};