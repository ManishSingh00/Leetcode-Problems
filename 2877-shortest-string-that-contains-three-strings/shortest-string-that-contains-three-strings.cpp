class Solution {
public:
    string f(string s, string t){
        if(s.find(t) != string::npos) return s;
        for(int i= min(s.size(), t.size());i>=0; i--){
            if(s.substr(s.size() - i) == t.substr(0, i)) return s + t.substr(i); 
        }
        return s + t;
    }

    string merge(string a, string b, string c) {
        return f(f(a, b), c);
    }

    static bool cmp(string& a, string& b) {
        if (a.length() == b.length()) return a < b;
        return a.length() < b.length();
    }

    string minimumString(string a, string b, string c) {
        vector<string> store;
        store.push_back(merge(a, b, c));
        store.push_back(merge(a, c, b));
        store.push_back(merge(b, a, c));
        store.push_back(merge(b, c, a));
        store.push_back(merge(c, a, b));
        store.push_back(merge(c, b, a));
        
        sort(store.begin(), store.end(), cmp);
        return store[0];
    }
};
