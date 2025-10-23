class LRUCache {
public:
    int cap;
    list<pair<int,int>>l;
    unordered_map<int,list<pair<int,int>>::iterator>mp;

    LRUCache(int capacity) {
        cap = capacity;    
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end()) return -1;

        auto it = mp[key];
        int value = it->second;
        l.erase(it);
        l.push_front({key,value});
        mp[key] = l.begin();

        return value;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            l.erase(mp[key]);
        }

        if(l.size() == cap){
            auto it = l.back();
            mp.erase(it.first);
            l.pop_back();
        }

        l.push_front({key,value});
        mp[key] = l.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */