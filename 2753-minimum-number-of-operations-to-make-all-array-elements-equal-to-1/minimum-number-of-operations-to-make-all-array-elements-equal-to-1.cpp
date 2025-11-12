class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int len = 55;
        int cnt1 = 0;
        for (int i = 0; i < n; ++i) cnt1 += (nums[i] == 1);

        if(cnt1 !=0 ) return n-cnt1;

        for(int i=0;i<n;i++){
            int ans = nums[i];
            for(int j=i+1;j<n;j++){
                ans = __gcd(ans,nums[j]);
                if(ans == 1){
                  len = min(len,j-i+1);
                  break;
                }
            }
        }
        if(len == 55) return -1;
        return (len-1) + (n-1);
    }
};