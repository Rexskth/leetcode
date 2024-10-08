class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        
          int ans = 0;
        unordered_map<char, int> Map;
        unordered_map<string, int> substrOccur;
        for(int start = 0, end = 0; end < s.length(); end++) {
            if(Map[s[end]]++ == 0) maxLetters--;
            while(maxLetters < 0 || end - start + 1 > minSize) {
                if(Map[s[start++]]-- == 1) maxLetters++;
            }
            if(end - start + 1 == minSize) 
                ans = max(ans, ++substrOccur[s.substr(start, minSize)]);
        }
        return ans;
    }
};