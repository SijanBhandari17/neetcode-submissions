class TimeMap {
   private:
    unordered_map<string, vector<pair<int, string>>> tbkv;

   public:
    TimeMap() {};

    void set(string key, string value, int timestamp) { tbkv[key].push_back({timestamp, value}); }

    string get(string key, int timestamp) {
        auto& it = tbkv[key];
        int l = 0;
        int r = it.size() - 1;
        string res = "";

        while (l <= r) {
            int mid = (l + r) / 2;

            if (it[mid].first <= timestamp) {
                res = it[mid].second;
                l = mid + 1;
            } else
                r = mid - 1;
        }
        return res;
    }
};
