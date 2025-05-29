class Solution {
public:
    int dp[100005][5];
    int f(int i,int prev,vector<int>& nums1,vector<int>& nums2){
        if(i==nums1.size()){
            return 0;
        }
        if(dp[i][prev]!=-1) return dp[i][prev];
        int ans = 0;

        if(prev == 0){
            ans = max(ans,f(i+1,0,nums1,nums2));
            ans = max(ans, 1 + f(i+1,1,nums1,nums2));
            ans = max(ans, 1 + f(i+1,2,nums1,nums2));
        }
        else{
            if(prev == 1){
                if(nums1[i]>=nums1[i-1])  ans = max(ans, 1 + f(i+1,1,nums1,nums2));
                if(nums2[i]>=nums1[i-1])  ans = max(ans, 1 + f(i+1,2,nums1,nums2));
            }
            else if(prev == 2){
                if(nums2[i]>=nums2[i-1])  ans = max(ans, 1 + f(i+1,2,nums1,nums2));
                if(nums1[i]>=nums2[i-1])  ans = max(ans, 1 + f(i+1,1,nums1,nums2));
            }
        }

        return dp[i][prev]= ans;
    }
    int maxNonDecreasingLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        memset(dp,-1,sizeof dp);
        return f(0,0,nums1,nums2);
    }
};