class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> mpp;
    TimeMap() {}

    void set(string key, string value, int timestamp) {
        mpp[key].push_back({timestamp, value});
    }

    string get(string key, int timestamp) {
        if (mpp.find(key) == mpp.end())
            return "";
        vector<pair<int, string>>& arr = mpp[key];
        int low = 0;
        int high = arr.size() - 1;
        int ans = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid].first <= timestamp) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        if (ans == -1) {
            return "";
        }
        return arr[ans].second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */