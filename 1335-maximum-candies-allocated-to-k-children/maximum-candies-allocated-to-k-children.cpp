class Solution {
    private:

    bool isValid(vector<int>& candies, long long k, int mid) {
    long long totalChildren = 0;
    for (int pile : candies) {
        totalChildren += pile / mid; 
        if (totalChildren >= k) {
            return true; 
        }
    }
    return totalChildren >= k;
}
public:
    int maximumCandies(vector<int>& candies, long long k) {

         long long totalSum = accumulate(candies.begin(), candies.end(), 0LL);
    if (totalSum < k) {
        return 0;
    }

    
    int left = 1;
    int right = *max_element(candies.begin(), candies.end());
    int result = 0;

    while (left <= right) {
        int mid = left + (right - left) / 2; 
        if (isValid(candies, k, mid)) {
            result = mid; 
            left = mid + 1; 
        } else {
            right = mid - 1; 
        }
    }

    return result;
        
    }
};