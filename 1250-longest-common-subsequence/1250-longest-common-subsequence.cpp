class Solution {
    private:
 int tabulatedLCS(string s1, string s2) {
    int m = s1.length();
    int n = s2.length();

    // DP table
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // Fill the DP table
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[m][n];
}

public:
    int longestCommonSubsequence(string text1, string text2) {
       
        int ans = tabulatedLCS(text1, text2);
        return ans;
    }
};