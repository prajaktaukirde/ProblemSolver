class Solution {
public:
    bool isPalindrome(string s) {
        // Build a cleaned string with only lowercase alphanumeric chars
        string cleaned = "";
        for (char c : s) {
            if (isalnum(c)) {
                cleaned += tolower(c);
            }
        }

        // Compare with its reverse
        string reversed = cleaned;
        reverse(reversed.begin(), reversed.end());
        return cleaned == reversed;
    }
};