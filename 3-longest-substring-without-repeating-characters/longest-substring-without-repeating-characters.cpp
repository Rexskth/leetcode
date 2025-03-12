class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();

        int l = 0, r = 0, maxl = INT_MIN;

        vector<int> mpp(256,0);

        while(r < n){
         mpp[s[r]]++;
         while(mpp[s[r]] > 1){ 
                      mpp[s[l]]--;
                      l++;
         }  
        maxl = max(maxl, r - l + 1);

         r++;
        }
        return maxl == INT_MIN ? 0: maxl;
    }
};