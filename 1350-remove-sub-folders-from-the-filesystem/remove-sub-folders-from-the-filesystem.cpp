class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        // Step 1: Sort the folders
        sort(folder.begin(), folder.end());

        vector<string> stack;

        for (const string& f : folder) {
           
            if (stack.empty() || f.find(stack.back() + "/") != 0) {
                stack.push_back(f);
            }
        }

        return stack; // Stack now contains the required folders
    }
};