class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int>freq;
        for(auto it : nums){
            if(freq.count(it)){
                return true;
            }
            freq.insert(it);
        }
        return false;
    }
};