class Solution {
    private: 
    int dfs(int i, int j, vector<vector<int>>& grid){
        int n = grid.size();
        int m = grid[0].size();

        if(i<0 || i>=n || j<0 || j>=m || grid[i][j] ==0){
            return 0;
        }

        int gold = grid[i][j];
        grid[i][j] = 0;

        int maxgold = max({dfs(i,j-1,grid), dfs(i-1,j,grid),
                            dfs(i+1,j,grid), dfs(i,j+1,grid)});

            grid[i][j] = gold;
            return gold + maxgold;
    }
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int maxG = 0;
        
        int n = grid.size();
        int m = grid[0].size();

        for(int i = 0; i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]>0){
                    maxG = max(maxG, dfs(i,j,grid));
                }
            }
        }
        return maxG;
    }
};