class Solution {
public:
    string minWindow(string s, string t) {
        
        int n = s.size();
        int m = t.size();

        int l = 0, r = 0, cnt = 0, minl = INT_MAX, start = -1;

        vector<int> map(256, 0);

        for(int i = 0; i < m; i++){
            map[t[i]]++;
        }

        while(r < n){
            if(map[s[r]] > 0){
                cnt++;
            }

             map[s[r]]--;
             while(cnt == m){
                if(r - l + 1 < minl){
                    minl = r - l + 1;
                    start = l;
                }
                 
                 map[s[l]]++;
                if(map[s[l]] > 0){
                    cnt--;
                }
                
                l++;
             }

             r++;

        }


        return start == -1 ? "" : s.substr(start, minl);
    }
};