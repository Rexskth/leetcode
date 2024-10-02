class Solution {
public:
    int lengthOfLastWord(string s) {
        int ans=0,ans2=0;

        for(auto it:s){
            if(it==' '){
                ans=0;
            }else{
                ans++;
                ans2=ans;
            }
        }
    
        return ans2;
    }
};