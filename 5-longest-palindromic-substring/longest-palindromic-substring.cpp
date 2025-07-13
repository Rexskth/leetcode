class Solution {
private:
    int expandAroundCenter(string &s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;
            right++;
        }
        return right - left - 1; 
          
    }

public: 
    string longestPalindrome(string &s) {
        int n = s.size();
        if (n == 0) return "";

        int startIdx = 0, maxLen = 1;

        for (int i = 0; i < n; i++) {
            // Odd-length palindromes (center at i)
            int len1 = expandAroundCenter(s, i, i);
            // Even-length palindromes (center between i and i+1)
            int len2 = expandAroundCenter(s, i, i + 1);

            int len = max(len1, len2);
            if (len > maxLen) {
                maxLen = len;
                startIdx = i - (len - 1) / 2;
            }
        }

        return s.substr(startIdx, maxLen);
    }
};