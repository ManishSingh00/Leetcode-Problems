class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<pair<int,int>>pq;
        for(int i=0;i<n;i++){
            pq.push({nums[i],i});
        }

        vector<pair<int,int>>v;
        for(int i=1;i<=k;i++){
            auto [val,idx] = pq.top();
            v.push_back({idx,val});
            pq.pop();
        }
        sort(v.begin(),v.end());
        vector<int>ans;
        for(auto x:v){
            ans.push_back(x.second);
        }
        return ans;

    }
};