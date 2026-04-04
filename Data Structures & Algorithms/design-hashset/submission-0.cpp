class MyHashSet {
private:
    vector<int> hashset;

public:
    MyHashSet() {
        hashset = {};
    }
    
    void add(int key) {
        if (!contains(key)) {
            hashset.push_back(key);
        }
    }
    
    void remove(int key) {
        auto it = find(hashset.begin(), hashset.end(), key);
        if (it != hashset.end()) {
            hashset.erase(it);
        }
    }
    
    bool contains(int key) {
        return find(hashset.begin(), hashset.end(), key) != hashset.end();
    }
};
