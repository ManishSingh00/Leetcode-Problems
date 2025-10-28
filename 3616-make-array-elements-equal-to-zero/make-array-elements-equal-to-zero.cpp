class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n = nums.size();
        vector<int>pre(n);
        pre[0] = nums[0];
        for(int i=1;i<n;i++){
            pre[i] = pre[i-1] + nums[i];
        }

        int ans = 0;

        for(int i =0;i<n;i++){
            if(nums[i] == 0){
                int left = pre[i];
                int right = pre[n-1] - pre[i];
                if(abs(left-right) == 0) ans += 2;
                else if( abs(left-right) == 1) ans += 1;
            }
        }

        return ans;
    }
};