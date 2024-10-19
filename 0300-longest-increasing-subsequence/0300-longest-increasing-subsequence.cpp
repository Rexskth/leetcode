class Solution {
public:

int f(int indx, int prev, vector<int>& nums,  vector<vector<int>>& dp){
      
      if(indx<0){
        return 0;
      }


        if (dp[indx][prev + 1] != -1) {
            return dp[indx][prev + 1];  // Use memoized result
        }

      int npick = 0 + f(indx-1, prev, nums,dp);
      int pick = 0;
      if(prev == -1 || nums[indx] < nums[prev]){
          pick = 1 + f(indx-1, indx, nums, dp);
      }
    
    return dp[indx][prev + 1] = max(pick, npick);
}
    int lengthOfLIS(vector<int>& nums) {
        int n =  nums.size();
        int prev = -1;
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return f(n-1,prev,nums,dp);
    }
};