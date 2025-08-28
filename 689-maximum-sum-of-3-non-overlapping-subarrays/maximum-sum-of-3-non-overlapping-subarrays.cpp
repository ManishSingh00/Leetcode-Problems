class Solution {
public:
    vector<int>pre;
    int dp[20005][4];
    int f(int i,int cnt,int k,int n){ // this func is just finding maximum sum
        if(cnt == 0){
            return 0;
        }
        if(i > n-k) return INT_MIN;
        if(dp[i][cnt] != -1) return dp[i][cnt];

        int ans = f(i+1,cnt,k,n);    
        ans = max(ans , pre[i+k-1] - (i>0 ? pre[i-1] : 0) + f(i+k,cnt-1,k,n));
        
        return dp[i][cnt] = ans;
    }

    void find_path(int i,int cnt,int k,vector<int>& ans,int n){ // this func is for greedy path selection which leads to maximum sum
        if(cnt == 0) return;
        if(i>n-k) return;
        
        int not_take = f(i+1,cnt,k,n);
        int take = pre[i+k-1] - (i>0 ? pre[i-1] : 0) + f(i+k,cnt-1,k,n);

        if(take >= not_take){ // in case of tie we will not avoid that index , instead we will take it to get lexico smaller path
            ans.push_back(i);
            find_path(i+k,cnt-1,k,ans,n);
        }
        else find_path(i+1,cnt,k,ans,n);
    }
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        pre.resize(n);
        memset(dp,-1,sizeof dp);
        pre[0] = nums[0];
        
        for(int i=1;i<n;i++){
            pre[i] = pre[i-1] + nums[i];
        }

        f(0,3,k,n);
        vector<int>ans;
        find_path(0,3,k,ans,n);

        return ans;
    }
};