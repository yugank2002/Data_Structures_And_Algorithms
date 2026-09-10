class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        

        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (matrix[i][j]) {
                    matrix[i][j] = 1 + min({matrix[i - 1][j - 1], matrix[i - 1][j],
                                          matrix[i][j - 1]});
                }
            }
        }

        int sum = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                sum += matrix[i][j];
            }
        }

        return sum;
    }
};