class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>is_flipped(n,0);
        int flip_cnt = 0;
        int ans = 0;

        for(int i=0;i<n;i++){
            if(i>=k){
                flip_cnt -= is_flipped[i-k]; 
            }

            if((nums[i]==1 && flip_cnt%2==1) || (nums[i]==0 && flip_cnt%2==0)){
                if(i+k>n) return -1;
                ans ++;
                flip_cnt++;
                is_flipped[i]=1;
            }
        }

        return ans;
    }
};