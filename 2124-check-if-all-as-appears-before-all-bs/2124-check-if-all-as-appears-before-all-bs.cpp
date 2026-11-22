class Solution {
public:
    bool checkString(string s) {
        bool foundB = false;

        for (char ch : s) {
            if (ch == 'b') {
                foundB = true;
            }

            if (ch == 'a' && foundB) {
                return false;
            }
        }

        return true;
    }
};