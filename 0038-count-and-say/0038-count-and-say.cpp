class Solution {
public:
    string countAndSay(int n) {
        string ans = "1";
        for(int i=1;i<n;i++){
            string next="";
            int j=0;
            while(j<ans.size()){
                int cnt=0;
                char digit=ans[j];
                while(j<ans.size() && ans[j]==digit){
                    cnt++;
                    j++;
                }
                next+=to_string(cnt);
                next+=digit;
            }
            ans=next;
        }
        return ans;
    }
};