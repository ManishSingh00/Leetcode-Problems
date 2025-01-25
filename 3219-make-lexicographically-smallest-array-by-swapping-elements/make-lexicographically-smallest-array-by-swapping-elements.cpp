#define pp pair<int,int>
class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<pp>arr;
        int n = nums.size();
        for(int i=0;i<n;i++){
            arr.push_back({nums[i],i});
        }

        sort(arr.begin(),arr.end());
        vector<vector<pp>>groups;
        groups.push_back({arr[0]});

        for(int i=1;i<n;i++){
            if(arr[i].first-arr[i-1].first<=limit){
                groups.back().push_back({arr[i]});
            }
            else groups.push_back({arr[i]});
        }
        vector<int>ans(n);
        for(auto group : groups){
            vector<int>idx;
            for(auto x:group){
                idx.push_back(x.second);
            }
            sort(idx.begin(),idx.end());
            for(int i=0;i<idx.size();i++){
                ans[idx[i]]=group[i].first;
            }
        }
        return ans;
    }
};