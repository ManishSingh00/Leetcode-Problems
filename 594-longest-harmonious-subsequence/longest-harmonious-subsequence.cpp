class Solution {
public:
    int findLHS(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        int ans = 0;

        for(int i=0;i<n;i++){
            int curr_freq = mp[nums[i]];
            bool flag = false;
            if(mp.find(nums[i]+1)!=mp.end()){
                flag = true;
            }

            if(flag){
                ans = max(ans , curr_freq+mp[nums[i]+1]);
            }
        }
        return ans;
    }
};