class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int minW = INT_MAX; // Minimum white blocks to recolor
        int wcnt = 0;       // Count of white blocks in the current window
        int l = 0;          // Left pointer of the window
        int r = 0;          // Right pointer of the window

        for (r = 0; r < k; r++) {
            if (blocks[r] == 'W') {
                wcnt++;
            }
        }
        minW = min(minW, wcnt);

        while (r < blocks.size()) {
            if (blocks[l] == 'W') {
                wcnt--;
            }
            l++;

            if (blocks[r] == 'W') {
                wcnt++;
            }
            r++;

            minW = min(minW, wcnt);
        }

        return minW;
    }
};