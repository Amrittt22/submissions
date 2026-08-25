class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> mpp;
        for(auto it:nums){
            mpp.insert(it);
        }
        int prod=k;
        for(int i=1; ;i++){
            prod=k*i;
            if(mpp.find(prod)==mpp.end()){
                break;
            }
        }
        return prod;
    }
};