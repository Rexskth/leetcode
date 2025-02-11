class Solution {
public:
    int mySqrt(int A) {
        if (A == 0 || A == 1) return A;

        int low = 1, high = A, ans = 0;

        while (low <= high) {
            long long mid = low + (high - low) / 2; // Prevent overflow

            if (mid * mid == A) {
                return mid;
            } else if (mid * mid < A) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};
