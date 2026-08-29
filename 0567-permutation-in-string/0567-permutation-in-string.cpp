class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length())
            return false;
        unordered_map<char, int> mpp1, mpp2;
        for (char c : s1) {
            mpp1[c]++;
        }
        int k = s1.length();
        int n = s2.length();
        for (int i = 0; i < k; i++) {
            mpp2[s2[i]]++;
        }
        if (mpp1 == mpp2)
            return true;
        for (int i = k; i < n; i++) {
            mpp2[s2[i]]++;

            mpp2[s2[i - k]]--;
            if (mpp2[s2[i - k]] == 0) {
                mpp2.erase(s2[i - k]);
            }
            if (mpp2 == mpp1)
                return true;
        }

        return false;
    }
};