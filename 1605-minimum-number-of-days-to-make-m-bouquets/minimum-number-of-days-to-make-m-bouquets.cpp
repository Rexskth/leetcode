class Solution {
public:
    // Helper function to check if we can make m bouquets in 'day'
    bool canMakeBouquets(vector<int>& bloomDay, int m, int k, int day) {
        int flowers = 0, bouquets = 0;

        for (int bloom : bloomDay) {
            if (bloom <= day) {
                flowers++;
                if (flowers == k) { // Form a bouquet
                    bouquets++;
                    flowers = 0;
                }
            } else {
                flowers = 0; // Reset if flowers are not consecutive
            }
        }

        return bouquets >= m; // Check if we can form at least m bouquets
    }

    
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long totalFlowers = (long long)m * k;
        if (totalFlowers > bloomDay.size()) return -1; 

        int low = 1, high = *max_element(bloomDay.begin(), bloomDay.end());
        int result = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (canMakeBouquets(bloomDay, m, k, mid)) {
                result = mid;   
                high = mid - 1; 
            } else {
                low = mid + 1; 
        }
        }

        return result;
    }
};