class Solution {
    private:

    int f(int n, vector<int>& dp){
        if(n < 2){
            return dp[n] = n;
        }
        if(dp[n] != -1) return dp[n];

        return dp[n] = f(n-1, dp) + f(n-2, dp);
    }
public:
    int fib(int n) {
        vector<int> dp(n+1, -1);

   return f(n, dp);
        
    }
};