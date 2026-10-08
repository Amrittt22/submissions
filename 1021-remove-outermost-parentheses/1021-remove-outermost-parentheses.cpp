class Solution {
public:
    string removeOuterParentheses(string s) {
        int opencnt=0;
        int closecnt=0;
        string res="";
        int start=0;
        for(int i=0;i<s.length();i++){
            char c=s[i];
            if(c=='('){
                opencnt++;
            }
            else if(c==')'){
                closecnt++;
            }
            if(opencnt==closecnt){
                res+=s.substr(start+1,i-start-1);
                start=i+1;
            }
        }
        return res;
    }
};