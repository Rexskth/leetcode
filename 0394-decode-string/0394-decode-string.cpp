class Solution {
public:
    string decodeString(string s) {
        stack<int> numStack;
        stack<string> strStack;
        string currentString = "";
        int num = 0;

        for (char c : s) {
            if (isdigit(c)) {
                num = num * 10 + (c - '0'); // Build number
            } else if (c == '[') {
                numStack.push(num);
                strStack.push(currentString);
                num = 0;
                currentString = "";
            } else if (c == ']') {
                int repeatCount = numStack.top(); numStack.pop();
                string temp = strStack.top(); strStack.pop();
                while (repeatCount--) temp += currentString; // Repeat and merge
                currentString = temp;
            } else {
                currentString += c; // Build substring
            }
        }

        return currentString;
    }
};