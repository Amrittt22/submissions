class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()) return false;
        unordered_map<char,int> charcnt;
        for(char ch:s){
            charcnt[ch]+=1;
        }
        for(char ch:t){
            charcnt[ch]-=1;
        }
        for(auto& pair:charcnt){
            if(pair.second!=0) return false;
        }
        return true;
    }
};