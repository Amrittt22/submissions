class Solution {
public:
    vector<int> partitionLabels(string s) {
         unordered_map<char,int>freq;
        for(int i=0;i<s.length();i++){
            freq[s[i]]=i;
        }
        int start=0;
        int end=0;
        vector<int>ans;
        for(int i=0;i<s.length();i++){
            end=max(end,freq[s[i]]);
            if(i==end){
                ans.push_back(i-start+1);
                start=i+1;
            }
        }
        return ans;
    }
};