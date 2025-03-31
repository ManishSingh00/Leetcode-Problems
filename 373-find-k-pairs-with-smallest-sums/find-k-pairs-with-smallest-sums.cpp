#define pp pair<int,int>
class Solution {
public:
vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
    vector<vector<int>> ans;
    priority_queue<pp,vector<pp>,greater<pp>>pq;
    for(int i=0;i<nums2.size();i++){
        pq.push({nums1[0]+nums2[i],0});
    }
    while(k-- && pq.size()>0){
        int sum=pq.top().first;
        int idx=pq.top().second;
        pq.pop();
        ans.push_back({nums1[idx],sum-nums1[idx]});
        if(idx+1<nums1.size()) pq.push({sum-nums1[idx]+nums1[idx+1],idx+1});
    }
    return ans;
    }
};