class Solution {
public:
    int dp[100005][2];
    int f(int i,bool swapp,int prev1,int prev2,vector<int>& nums1,vector<int>& nums2,int n){
        if(i == n){
            return 0;
        }
        if(dp[i][swapp]!=-1) return dp[i][swapp];
        int ans = INT_MAX;
        
        if(nums1[i] > prev1 && nums2[i] > prev2){ // not swapping , just move ahead
            ans = min(ans, f(i+1,false,nums1[i],nums2[i],nums1,nums2,n));
        }
        if(nums1[i] > prev2 && nums2[i] > prev1){ // do a swapping (swapping CONDITION IS MAIN CRUCKS OF THIS PROBLEM)
            ans = min(ans, 1+f(i+1,true,nums2[i],nums1[i],nums1,nums2,n));
        }
        

        return dp[i][swapp] = ans;
    }
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        memset(dp,-1,sizeof dp);

        return f(0,false,-1,-1,nums1,nums2,n);

    }
};