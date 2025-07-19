class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
           vector<double>sum;
        int m=nums1.size();
        int n=nums2.size();
        for(auto k1 : nums1){
            sum.push_back(k1);
        }
        for(auto k2 : nums2){
            sum.push_back(k2);
        }
        sort(sum.begin(),sum.end());
        int x=sum.size();
        if(x%2==0){
        double y=(sum[x/2]+sum[(x-2)/2])/2.0;
        return y;
        }
        return sum[x/2]; 
    }
};