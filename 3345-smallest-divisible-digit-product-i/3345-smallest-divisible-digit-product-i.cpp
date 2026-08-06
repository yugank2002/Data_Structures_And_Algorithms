class Solution {
public:
int prod(int n){
    int p=1;
    while(n){
        p*=(n%10);
        n/=10;
    }
    return p;
}
    int smallestNumber(int n, int t) {
        while(n){
            if(!(prod(n)%t))return n;
            n++;
        }
        return 0;
    }
};