class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> mapp;
        for (auto& pair : knowledge) {
            mapp[pair[0]] = pair[1];
        }
        string ans = "";
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                string key = "";
                i++;
                while (s[i] != ')') {
                    key += s[i];
                    i++;
                }
                if (mapp.find(key) != mapp.end()) {
                    ans += mapp[key];
                } else {
                    ans += "?";
                }
            }
            else{
                ans+=s[i];
            }
        }
        return ans;
    }
};