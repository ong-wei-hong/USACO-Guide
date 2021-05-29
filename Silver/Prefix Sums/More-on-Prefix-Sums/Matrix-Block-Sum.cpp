class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int n = mat.size(), m = mat[0].size();
        
        vector<vector<int>> dp (n+1);
        for(int i=0; i<=n; ++i)
            for(int j=0; j<=m; ++j)
                dp[i].push_back(0);
        
        for(int i=1; i<=n; ++i)
            for(int j=1; j<=m; ++j)
                dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + mat[i-1][j-1];
           
        vector<vector<int>> ans;
        for(int i=1; i<=n; ++i) {
            vector<int> curr;
            for(int j=1; j<=m; ++j) {
                int a = max(1, i-k), b = max(1, j-k), c = min(n, i+k), d = min(m, j+k);
                int sum = dp[c][d] - dp[a-1][d] - dp[c][b-1] + dp[a-1][b-1];
                curr.push_back(sum);
            }
            ans.push_back(curr);
        }
        return ans;
    }
};