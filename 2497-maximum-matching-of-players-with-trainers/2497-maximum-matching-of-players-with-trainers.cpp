class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());
        
        int i = 0, j = 0, matches = 0;
        
        // Two-pointer technique
        while (i < players.size() && j < trainers.size()) {
            if (players[i] <= trainers[j]) {
                matches++; // Match found
                i++; // Move player pointer
            }
            j++; // Always move trainer pointer
        }
        
        return matches;
    }
};