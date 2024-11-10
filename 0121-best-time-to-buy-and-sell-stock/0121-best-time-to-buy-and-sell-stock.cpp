class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int n = prices.size();
        int minprice = INT_MAX;
        int maxpr = 0;

        for(int i= 0; i< n;i++){
              minprice = min(minprice, prices[i]);
              maxpr = max(maxpr, prices[i]-minprice);
        }
        

        return maxpr;
    }
};