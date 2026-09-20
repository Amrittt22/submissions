class Solution {
public:
    int reverseDegree(string s) {
        int n=s.length();
        int ans=0;
        for(int i=1;i<=n;i++){
            ans+=('z'-s[i-1]+1)*i;
        }
        return ans;
    }
};