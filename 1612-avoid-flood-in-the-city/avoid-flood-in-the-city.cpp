class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        vector<int>ans(n);

        unordered_map<int,int>mp; // store last day 
        set<int>st;
        for(int i=0;i<n;i++){
            if(rains[i] > 0){
                if(mp.count(rains[i]) != 0){
                    int first = mp[rains[i]];
                    auto it= st.upper_bound(first);
                    if(it == st.end()){
                        return {};
                    }
                    else{
                        ans[*it] = rains[i];
                        st.erase(it);
                    }
                }
                mp[rains[i]] = i;
                ans[i] = -1; 
            }
            else if(rains[i] == 0){
                st.insert(i);
                ans[i] = 1; // can be changed later on
            }
        }

        return ans;
    }
};