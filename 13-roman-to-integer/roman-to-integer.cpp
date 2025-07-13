class Solution {
public:
    int romanToInt(string s) {

        int ans = 0;
         unordered_map<char, int> mpp = {{'I',1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};

         for(int i = 0; i < s.size()-1; i++){

            if((s[i] == 'I' || s[i] == 'X' ||s[i] == 'C' ) && mpp[s[i]]<mpp[s[i+1]]){
                ans = ans - mpp[s[i]];
            }else{
                ans += mpp[s[i]];
            }
         }


         return ans + mpp[s[s.size()-1]];
        
    }
};