class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
       
        vector<int> points(10001, 0);
        for (int num : nums) {
            points[num] += num;
        }
        
        // Apply DP (similar to House Robber)
        vector<int> dp(10001, 0);
        dp[1] = points[1]; 
        for (int i = 2; i < 10001; i++) {
            dp[i] = max(dp[i - 1], dp[i - 2] + points[i]);
        }
        
        return dp[10000];
    }
};