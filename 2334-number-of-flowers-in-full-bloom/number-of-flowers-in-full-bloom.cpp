class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        int n = flowers.size();
        vector<int>start;
        vector<int>last;

        for(int i=0;i<n;i++){
            start.push_back(flowers[i][0]);
            last.push_back(flowers[i][1]);
        }
        sort(start.begin(),start.end());
        sort(last.begin(),last.end());

        vector<int>ans;

        int sz = people.size();
        for(int i=0;i<sz;i++){
            int x = upper_bound(start.begin(),start.end(),people[i]) - start.begin();
            int y = lower_bound(last.begin(),last.end(),people[i]) - last.begin();
            // cout<<x<<" "<<y<<endl;
            ans.push_back(x-y);
        }

        return ans;
    }
};