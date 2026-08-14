class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.length();

        unordered_map<char, int> freq;

        int i = 0;
        int ans = 0;

        for (int j = 0; j < n; j++) {

            freq[s[j]]++;

            while (freq[s[j]] > 2) {
                freq[s[i]]--;
                i++;
            }

            ans = max(ans, j - i + 1);
        }

        return ans;
    }
};