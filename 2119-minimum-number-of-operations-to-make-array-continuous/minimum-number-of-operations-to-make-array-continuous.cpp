class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        int ans = INT_MAX;
        cout<<n<<endl;
        for(int i=0;i<n;i++){
            int l = nums[i];
            int r = l+n-1;
        
            
            int j=upper_bound(nums.begin(),nums.end(),r)-nums.begin();
            int keep = j-i;
            int remain = n- keep;

            ans = min(ans,remain);
        }

        return ans;

        
    }
};