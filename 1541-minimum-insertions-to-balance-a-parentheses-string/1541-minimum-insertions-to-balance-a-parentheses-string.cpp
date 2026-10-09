class Solution {
public:
    int minInsertions(string s) {
        int close = 0;
        int ans = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                close += 2;
                if (close % 2 != 0) {
                    ans++;
                    close--;
                }
            } else {
                close--;

                if (close < 0) {
                    ans++;
                    close = 1;
                }
            }
        }
        return close + ans;
    }
};