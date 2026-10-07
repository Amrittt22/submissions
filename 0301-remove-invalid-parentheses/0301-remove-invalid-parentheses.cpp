class Solution {
public:
    bool valid(string s) {
        int balance = 0;

        for (char ch : s) {
            if (ch == '(')
                balance++;

            else if (ch == ')') {
                balance--;

                if (balance < 0)
                    return false;
            }
        }

        return balance == 0;
    }

    vector<string> removeInvalidParentheses(string s) {
        vector<string> ans;

        queue<string> q;
        unordered_set<string> vis;

        q.push(s);
        vis.insert(s);

        bool found = false;

        while (!q.empty() && !found) {

            int size = q.size();

            while (size--) {

                string curr = q.front();
                q.pop();

                if (valid(curr)) {
                    ans.push_back(curr);
                    found = true;
                }

                if (found)
                    continue;

                for (int i = 0; i < curr.size(); i++) {

                    if (curr[i] != '(' && curr[i] != ')')
                        continue;

                    string next =
                        curr.substr(0, i) + curr.substr(i + 1);

                    if (!vis.count(next)) {
                        vis.insert(next);
                        q.push(next);
                    }
                }
            }
        }

        return ans;
    }
};