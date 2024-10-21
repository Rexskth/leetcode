class Solution {
public:
    string longestPalindrome(string s) {
        
        int n = s.size();
        if(n == 0) return s;
        int ans = 1;
        int start = 0;

        for(int i =0;i<n;i++){
            int l = i, r=i;
            while(l>=0 && r<n && s[l] == s[r]){
                l--;
                r++;

            }
            if(ans < r-l-1){
                start = l+1;
                ans = r-l-1;
            }
        }

          for(int i =0;i<n-1;i++){
            int l = i, r=i+1;
            while(l>=0 && r<n && s[l] == s[r]){
                l--;
                r++;

            }

            if(ans < r-l-1){
                start = l+1;
                ans = r-l-1;
            }
       }
           return s.substr(start,ans);
    }
};