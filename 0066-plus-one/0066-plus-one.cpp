class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        int carry =1;
        for(int i=n-1; i>=0; i--){
            digits[i] = (digits[i]+carry)%10;
            if(digits[i]!=0) carry =0;
            if(carry == 0) break;
        }
        if(carry) digits.insert(digits.begin(),1);
        return digits;
    }
};