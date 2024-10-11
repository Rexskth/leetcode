class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int  l = k-1, r = n - 1;
        int sum = 0, maxS= 0;

        for(int i =0; i <= k-1; i++){
            maxS += cardPoints[i];
        }
           sum = maxS;
        while(l>=0){
           
           sum += cardPoints[r];
           r--;
           sum -= cardPoints[l];
           l--;

           maxS = max(maxS, sum);


        }
        return maxS;
    }
};