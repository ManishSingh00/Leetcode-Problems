class Solution {
public:
    vector<vector<int>>ans;
    int n;

    bool check(int val){
        int root = sqrt(val);
        return root*root == val;
    }
    void f(vector<int>& nums,int idx){
        if(idx==n){
            ans.push_back(nums);
            return;
        }
        unordered_set<int>vis;
        for(int i=idx;i<n;i++){
            if(vis.count(nums[i])==0){
                if(idx>0 && check(nums[idx-1]+nums[i]) == false) continue;
                vis.insert(nums[i]);
                swap(nums[i],nums[idx]);
                f(nums,idx+1);
                swap(nums[i],nums[idx]);
            }
        }

    }
    int numSquarefulPerms(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        n=nums.size();
        ans.clear();
        f(nums,0);
    

        return ans.size();
    }
};