class Solution {
public:
    string reorganizeString(string s) {
        int n = s.length();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[s[i]-'a']++;
        }
        for(auto x:mp){
            int cnt = x.second;
            if(cnt > (n+1)/2) return "";
        }

        priority_queue<pair<int,int>>pq;
        for(auto x:mp){
            pq.push({x.second,x.first});
        }
        int start = 0;
        while(pq.size()>0){
            int cnt = pq.top().first;
            int letter = pq.top().second;
            pq.pop();
        
            for(int i=0;i<cnt;i++){
                if(start >= n) start = 1;
                s[start] = 'a' + letter;
                start+=2;
            }
        }
        return s;

    }
};