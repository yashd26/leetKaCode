class Solution {
public:
    int helper(int inRow, int inCol, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        if (inRow < 0 || inCol < 0) {
            return 1e9;
        }
        if (inRow == 0 && inCol == 0) {
            return grid[inRow][inCol];
        }
        if(dp[inRow][inCol] != -1) {
            return dp[inRow][inCol];
        }
        
        return dp[inRow][inCol] = min(grid[inRow][inCol] + helper(inRow - 1, inCol, grid, dp), grid[inRow][inCol] + helper(inRow, inCol - 1, grid, dp));
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        vector<vector<int>> dp(row, vector<int>(col, -1));
        
        return helper(row - 1, col - 1, grid, dp);
    }
};