class Solution {
public:
    string intToRoman(int num) {

         string ans;
        vector<string> v = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        vector<int> vv= {1000,900,500,400,100,90,50,40,10,9,5,4,1};
        
        int pos = 0;
        while(num>0){
            while(num>=vv[pos]){
                ans+=v[pos];
                num-=vv[pos];
            }
            pos++;
        }

        return ans;
        
    }
};