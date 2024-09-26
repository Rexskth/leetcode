class Solution {
public:
    char repeatedCharacter(string s) {
        unordered_map<char,int> mpp;
       char ans;
       int n =s.size();
       for(int i=0;i<n;i++){
        mpp[s[i]]++;
        if(mpp[s[i]]>1){
        ans  = s[i];
        break;
          
        }
       }
       return ans;
    }
};