class Solution {
public:
    int dp[10005];
    int f(vector<int> arr,int i){
        if(i==arr.size()-1) return arr[i];
        if(i==arr.size()-2) return max(arr[i],arr[i+1]);
        if(dp[i]!=-1) return dp[i];
        return dp[i]=max((arr[i]+f(arr,i+2)),f(arr,i+1));
       
    }
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();
        int val = *max_element(nums.begin(),nums.end());
        vector<int>arr(val+1,0); // by doing this it became HOUSE ROBBER problem
        for(int i=0;i<n;i++){
            arr[nums[i]] += nums[i];
        }
        memset(dp,-1,sizeof dp);
        return f(arr,0);

    }
};