class Solution {
public:
    int numTeams(vector<int>& nums) {
        int n = nums.size();
        vector<int>high(n,0);
        vector<int>low(n,0);

        for(int i=0;i<n;i++){
            for(int j = i+1;j<n;j++){
                if(nums[i] < nums[j]) high[i]++;
            }
        }

        for(int i=n-1;i>=0;i--){
            for(int j = 0;j<i;j++){
                if(nums[i] < nums[j]) low[i]++;
            }
        }

        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(nums[i] < nums[j]){
                    ans += high[j];
                }
            }
        }
        for(int i=n-1;i>=0;i--){
            for(int j = 0;j<i;j++){
                if(nums[i] < nums[j]){
                    ans += low[j];
                }
            }
        }

        return ans;
    }
};