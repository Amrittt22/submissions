class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0")
            return "0";
        int n = num1.size();
        int m = num2.size();
        vector<int> res(n + m, 0);
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                int a = num1[i] - '0';
                int b = num2[j] - '0';
                int prod = a * b;
                int p1 = i + j;
                int p2 = i + j + 1;
                int sum = prod + res[p2];
                res[p2] = sum % 10;
                res[p1] += sum / 10;
            }
        }
        string ans = "";
        for (int i : res) {
            if (!(ans.empty() && i == 0)) {
                ans += i + '0';
            }
        }
        return ans;
    }
};
