class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();
        int cnt_k = 0;
        for(int i= 0; i<n;i++){
            if(nums[i] == k) cnt_k++;
        }
        int ans = 0;
        for(int tar = 1;tar<=50;tar++){
            if(tar == k) continue;
            
            int cntt = 0;
            int maxi = 0;
            for(auto num : nums){
                if(num == tar) cntt++;
                if(num == k) cntt--;
                if(cntt < 0) cntt = 0;
                maxi = max(maxi,cntt);
            }
            ans = max(ans, cnt_k+maxi);
        }

        return ans;
    }

    // kind of KADANE ALGORITHM;

};