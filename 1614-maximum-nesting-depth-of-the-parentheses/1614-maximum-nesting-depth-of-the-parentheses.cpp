class Solution {
public:
    int maxDepth(string s) {
        int cnt=0;
        int maxcnt=0;
        for(auto ch:s){
            if(ch=='(') cnt++;
            else if(ch==')') cnt--;
            maxcnt=max(maxcnt,cnt);
        }
        return maxcnt;
    }
};