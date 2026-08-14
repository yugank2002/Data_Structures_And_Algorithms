class Solution {
public:
    int maxJump(vector<int>& stones) {
        int n = stones.size();
        int maxi = INT_MIN;
        for(int i=2; i<n; i+=2){
            maxi = max(maxi,stones[i]-stones[i-2]);

        }
      maxi = max(stones[1]-stones[0],maxi);
      maxi = max(stones[n-1]-stones[n-2],maxi);

      for(int i=3; i<n; i+=2){
        maxi = max(maxi,stones[i]-stones[i-2]);
      }

      return maxi;
    }
};