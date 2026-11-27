class Solution {
public:
    void recurr(string &s , vector<vector<string>>& ans , vector<string>& ds , int index){
        if(index >= s.length()){
            ans.push_back(ds);
            return ;
        }
        for(int j=index ; j<s.length();j++){
            if(isPalindrome(s,index,j)){
                ds.push_back(s.substr(index,j-index+1));
                recurr(s,ans,ds,j+1);
                ds.pop_back();
            }
        }
    }

    bool isPalindrome(string &s , int l , int r){
        while(l<r){
            if(s[l]!=s[r]){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> ds;
        recurr(s,ans,ds,0);
        return ans;
    }
};
